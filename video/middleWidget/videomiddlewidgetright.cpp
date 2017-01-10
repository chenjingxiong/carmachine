#include "videomiddlewidgetright.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QDir>
#include <QTime>
#include <QFileDialog>
#include "player/videomediadatabase.h"
#include "global_value.h"
#include <QEventLoop>
#include <QMediaPlayer>


videoMiddleWidgetRight::videoMiddleWidgetRight(QWidget *parent):baseWidget(parent)
{
    setObjectName("videoMiddleWidgetRight");
    setStyleSheet("#videoMiddleWidgetRight{background:rgb(43,45,51)}");

    m_playList = new videoList(this);
    m_curPlayingIndex = -1;
    initLayout();
    initConnection();
    // 初始化Video列表数据
    //    getLocalListFromDataBase();
    beginSearchFromPath(VIDEO_SEARCH_PATH);
}

void videoMiddleWidgetRight::initLayout()
{
    QVBoxLayout *vmianlyout = new QVBoxLayout;

    m_listHeader = new listHeader(this);

    m_stackedWid = new QStackedWidget(this);
    m_localTable = new videoLocalListTable(m_stackedWid);
    m_netTable = new videoNetListTable(m_stackedWid);

    m_stackedWid->addWidget(m_localTable);
    m_stackedWid->addWidget(m_netTable);

    vmianlyout->addWidget(m_listHeader);
    vmianlyout->addWidget(m_stackedWid);
    vmianlyout->setContentsMargins(10,0,10,0);

    setLayout(vmianlyout);
}

void videoMiddleWidgetRight::initConnection()
{
    connect(m_listHeader,SIGNAL(buttonLocalClick()),this,SLOT(slot_switchToLocalList()));
    connect(m_listHeader,SIGNAL(buttonNetClick()),this,SLOT(slot_switchToNetList()));

    //    connect(m_localTable,SIGNAL(cellDoubleClicked(int,int)),this,SIGNAL(sig_localTableItemDoubleClick(int,int)));
}

void videoMiddleWidgetRight::setOriginState()
{

    //    m_localTable->item(m_curPlayingIndex,0)->setTextColor(QColor(255,255,255));
    //    m_localTable->item(m_curPlayingIndex,1)->setTextColor(QColor(255,255,255));
    //    m_localTable->item(m_curPlayingIndex,1)->setText("马丹");
    //    m_curPlayingIndex = -1;

}

//void videoMiddleWidgetRight::getLocalListFromDataBase()
//{
//    QVector<QStringList> vec= videoMediaDataBase::getVideoInfo();
//    QStringList listname=vec.at(0);
//    QStringList listpath=vec.at(1);
//    for(int i=0;i<listname.count();i++)
//    {
//        QString duration = verifyPathAndGetDuration(listname.value(i));
//        if(duration!=NULL){
//            insertIntoLocalTable(i,listname.value(i),duration);
//            m_playList->addToPlayList(listpath.value(i));
//        }else{
//            videoMediaDataBase::removeVideo(listname.value(i),listpath.value(i));
//        }
//    }
//}

void videoMiddleWidgetRight::beginSearchFromPath(QString path)
{
    QStringList filter;
    filter<<"mp4"<<"avi"<<"mp3";
    QMediaPlayer player;
    QEventLoop lp;
    QFileInfoList fileList = getFileList(path);
    for(int i=0;i<fileList.size();i++){
        QFileInfo fileInfo = fileList.at(i);
        for(int j=0;j<filter.size();j++){
            if(!m_playList->getUrlList().contains(QUrl::fromLocalFile(fileInfo.absoluteFilePath()))&&fileInfo.fileName().endsWith(filter.at(j))){
                player.setMedia(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
                //prevent the loop dont stop
                QTimer timer;
                connect(&timer,&QTimer::timeout,[&](){
                    lp.quit();
                });
                timer.setSingleShot(true);
                timer.start(2000);

                connect(&player,SIGNAL(durationChanged(qint64)),&lp,SLOT(quit()));
                lp.exec();
                qint64 videoTime= player.duration();
                QTime total_time((videoTime % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60),
                                 (videoTime % (1000 * 60 * 60)) / (1000 * 60),
                                 (videoTime % (1000 * 60)) / 1000);
                int allMinite = total_time.hour()*60+total_time.minute();
                QString duration = QString::number(allMinite).append(str_videoTime_minite);
                if(videoTime>0)
                {
                    int rowCount = m_localTable->rowCount();
                    insertIntoLocalTable(rowCount,fileInfo.baseName(),duration);
                    m_playList->addToPlayList(fileInfo.absoluteFilePath());
                    //                    videoMediaDataBase::addVideo(fileInfo.baseName(),fileInfo.absoluteFilePath(),"..");
                }
            }
        }
    }
}

// 搜索path路径下的所有文件
QFileInfoList videoMiddleWidgetRight::getFileList(QString path){
    QDir *dir=new QDir(path);
    QFileInfoList file_list = dir->entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir->entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i != folder_list.size(); i++){
        QString name = folder_list.at(i).absoluteFilePath();
        QFileInfoList child_file_list = getFileList(name);
        file_list.append(child_file_list);
    }
    return file_list;
}

void videoMiddleWidgetRight::insertIntoLocalTable(int row, QString videoName, QString duration)
{
    m_localTable->insertRow(row);
    m_localTable->setItem(row,0,new QTableWidgetItem(videoName));
    m_localTable->setItem(row,1,new QTableWidgetItem(duration));
    m_localTable->item(row,1)->setTextAlignment(Qt::AlignVCenter|Qt::AlignRight);
}

void videoMiddleWidgetRight::updatePlayingItemStyle(QMediaContent content)
{
    QList<QUrl> urlList = m_playList->getUrlList();
    // 还原上次选中的item
    if(m_curPlayingIndex!=-1)
    {
        m_localTable->setRowTextColor(m_curPlayingIndex,QColor(255,255,255));
        m_localTable->item(m_curPlayingIndex,1)->setText(m_curPlayingDuration);
        m_curPlayingIndex = -1;
        m_localTable->setPlayingItemIndex(m_curPlayingIndex);
        m_localTable->setCurrentCell(-1,0);
    }
    int index = -1;
    for(int i=0;i < urlList.size();i++)
    {
        if(urlList.at(i)==content.canonicalUrl()){
            index = i;
            break;
        }
    }
    if(index!=-1)
    {
        m_curPlayingIndex = index;
        m_curPlayingDuration = m_localTable->item(index,1)->text();
        m_curPlayingVideoName = m_localTable->item(index,0)->text();

        m_localTable->setRowTextColor(m_curPlayingIndex,QColor(26,158,255));
        m_localTable->item(index,1)->setText(str_video_playing);

         m_localTable->setCurrentCell(index,0);
        m_localTable->setPlayingItemIndex(m_curPlayingIndex);
    }
    update();
}


void videoMiddleWidgetRight::addVideo()
{
    static QString  initialName = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QStringList files=QFileDialog::getOpenFileNames(this, tr("Select File"), initialName, tr("*"));
    if(files.isEmpty())
        return;

    QMediaPlayer player;
    QEventLoop lp;
    for(int i=0;i<files.count();i++)
    {
        if(!m_playList->getUrlList().contains(QUrl::fromLocalFile(files.value(i))))
        {
            QFileInfo info(files[i]);
            QString fileName=info.completeBaseName();
            QString filePath=files.value(i);

            player.setMedia(QUrl::fromLocalFile(filePath));
            //prevent the loop dont stop
            QTimer timer;
            connect(&timer,&QTimer::timeout,[&](){
                lp.quit();
            });
            timer.setSingleShot(true);
            timer.start(2000);

            connect(&player,SIGNAL(durationChanged(qint64)),&lp,SLOT(quit()));
            lp.exec();
            qint64 videoTime= player.duration();
            QTime total_time((videoTime % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60),
                             (videoTime % (1000 * 60 * 60)) / (1000 * 60),
                             (videoTime % (1000 * 60)) / 1000);
            int allMinite = total_time.hour()*60+total_time.minute();
            QString duration = QString::number(allMinite).append(str_videoTime_minite);
            if(videoTime>0)
            {
                int rowCount = m_localTable->rowCount();
                insertIntoLocalTable(rowCount,fileName,duration);
                m_playList->addToPlayList(filePath);
                //                videoMediaDataBase::addVideo(fileName,filePath,"..");
            }
        }
    }
}
