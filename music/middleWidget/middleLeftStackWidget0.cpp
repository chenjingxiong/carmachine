#include "middleLeftStackWidget0.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QMediaPlayer>
#include <QEventLoop>
#include <QTime>
#include <QDir>
#include <QFileDialog>
#include "global_value.h"

#ifdef DEVICE_EVB
int header_height = 70;
int menu_width = 50;
#else
int header_height = 40;
int menu_width = 20;
#endif

QColor m_normalItemTextColor(48,48,48);
QColor m_PlayingItemTextColor(37,120,255);

middleLeftStackWidget0::middleLeftStackWidget0(QWidget*parent):baseWidget(parent)
{
    m_playlist = new mediaList(this);
    m_curPlayingIndex = -1;

    initLayout();
    initConnection();

    // 初始化音乐列表数据
    beginSearchFromPath(MUSIC_SEARCH_PATH);
}

void middleLeftStackWidget0::initLayout()
{
    QVBoxLayout *vlyout=new QVBoxLayout;

    m_header = new playListHeader(this);
    m_table = new musicListTable(this);

    vlyout->addWidget(m_header);
    vlyout->addWidget(m_table);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0,0,0,0);

    setLayout(vlyout);
}

void middleLeftStackWidget0::initConnection()
{
    connect(m_header,SIGNAL(sig_addSong()),this,SLOT(slot_addSong()));

    connect(m_table,SIGNAL(cellClicked(int,int)),this,SLOT(slot_itemDoubleClick(int,int)));
}

void middleLeftStackWidget0::setInitMainWidgets(musicWidgets *musicWidgets)
{
    this->m_mainwid = musicWidgets;
}

void middleLeftStackWidget0::addToPlayList(const QString &name,const QString &path,const QString &duration)
{
    int rowcount= m_table->rowCount();
    m_table->insertRow(rowcount);
    m_table->setItem(rowcount,1, new QTableWidgetItem(name));
    m_table->setItem(rowcount,2, new QTableWidgetItem(duration));
    m_table->item(rowcount,2)->setTextAlignment(Qt::AlignVCenter|Qt::AlignRight);

    m_playlist->addPlayList(path);

    updateSongCountLabel();
}

// 初始化_从数据库中获取音乐信息
//void middleLeftStackWidget0::getListfromDateBase()
//{
//    QVector<QStringList> vec= mediaDataBase::getSongInfo();
//    QStringList listname=vec.at(0);
//    QStringList listpath=vec.at(1);
//    QStringList listduration=vec.at(2);
//    for(int i=0;i<listname.count();i++)
//    {
//        m_table->insertRow(i);
//        m_table->setItem(i,1,new QTableWidgetItem(listname.value(i)));
//        m_table->setItem(i,2,new QTableWidgetItem(listduration.value(i)));
//        m_table->item(i,2)->setTextAlignment(Qt::AlignVCenter|Qt::AlignRight);
//        m_playlist->addPlayList(listpath.value(i));
//    }
//    updateSongCountLabel();
//}


void middleLeftStackWidget0::updateSongCountLabel()
{
    m_header->m_listInfo->setText(str_song_list+QString("[%1]").arg(QString::number(m_table->rowCount())));
}

// 搜索path路径下的所有文件
QFileInfoList middleLeftStackWidget0::getFileList(QString path){
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
bool isSearchOver = false;

// 从path路径下搜索所有mp3文件并添加到list
void middleLeftStackWidget0::beginSearchFromPath(QString path){
    if(isSearchOver){
        return;
    }
    isSearchOver = true;
    QStringList filter;
    filter<<".mp3";
//    QMediaPlayer player;
//    QEventLoop lp;
    QFileInfoList fileList = getFileList(path);
    for(int i=0;i<fileList.size();i++){
        QFileInfo fileInfo = fileList.at(i);
        for(int j=0;j<filter.size();j++){
            // 如果是后缀为mp3的文件
            if(!m_playlist->getUrlList().contains(QUrl::fromLocalFile(fileInfo.absoluteFilePath()))&&fileInfo.fileName().endsWith(filter.at(j))){
//                player.setMedia(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));
//                //prevent the loop dont stop
//                QTimer timer;
//                connect(&timer,&QTimer::timeout,[&](){
//                    lp.quit();
//                });
//                timer.setSingleShot(true);
//                timer.start(2000);

//                connect(&player,SIGNAL(durationChanged(qint64)),&lp,SLOT(quit()));
//                lp.exec();
//                qint64 musicTime= player.duration();
//                QTime total_time(0, (musicTime/60000)%60, (musicTime/1000)%60);
//                QString duration=total_time.toString("mm:ss");
//                if(musicTime>0){
                    addToPlayList(fileInfo.baseName(),fileInfo.absoluteFilePath()," ");
//                }
            }
        }
    }
}

void middleLeftStackWidget0::slot_addSong()
{
    static QString  initialName = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QStringList files=QFileDialog::getOpenFileNames(this, tr("Select File"), initialName, tr("*.mp3"));
    if(files.isEmpty())
        return;

//    QMediaPlayer player;
//    QEventLoop lp;
    for(int i=0;i<files.count();i++)
    {
        QFileInfo info(files[i]);
        QString m_name=info.baseName();
        if(!m_playlist->getUrlList().contains(QUrl::fromLocalFile(files.value(i))))
        {
//            QString filePath=files.value(i);
//            // to get the infomation of music
//            player.setMedia(QUrl::fromLocalFile(filePath));
//            //prevent the loop dont stop
//            QTimer timer;
//            connect(&timer,&QTimer::timeout,[&](){
//                lp.quit();
//            });
//            timer.setSingleShot(true);
//            timer.start(2000);

//            connect(&player,SIGNAL(durationChanged(qint64)),&lp,SLOT(quit()));
//            lp.exec();
//            qint64 musicTime= player.duration();
//            QTime total_time(0, (musicTime/60000)%60, (musicTime/1000)%60);
//            QString duration=total_time.toString("mm:ss");

//            if(musicTime>0){
                addToPlayList(m_name,files.at(i)," ");
//            }
        }
    }
}

void middleLeftStackWidget0::slot_itemDoubleClick(int row,int)
{
    QUrl url= m_playlist->mediaUrl(row);
    if(!url.isEmpty())
    {
        m_mainwid->getPlayer()->setMedia(url);
        m_mainwid->getPlayer()->play();
    }
}

void middleLeftStackWidget0::updatePlayingItemStyle(QMediaContent content)
{
    QList<QUrl> urlList = m_playlist->getUrlList();
    if(m_curPlayingIndex!=-1)
    {
        m_table->item(m_curPlayingIndex,2)->setText(m_curPlayingDuration);
        m_table->setRowTextColor(m_curPlayingIndex,m_normalItemTextColor);

        m_table->setCurrentCell(-1,0);
        m_curPlayingIndex = -1;
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
        m_curPlayingDuration = m_table->item(index,2)->text();
        m_curPlayingSongName = m_table->item(index,1)->text();

        m_table->setRowTextColor(m_curPlayingIndex,m_PlayingItemTextColor);
        m_table->item(index,2)->setText(str_song_playing);

        m_table->setCurrentCell(index,0);
    }
}


// 头标识
playListHeader::playListHeader(QWidget*parent):baseWidget(parent)
{
    setFixedHeight(header_height);
    setStyleSheet("background:rgb(240,240,240)");
    setCursor(Qt::PointingHandCursor);
    initWidget();
    initMenu();
}

void playListHeader::initWidget()
{
    QHBoxLayout *lyout=new QHBoxLayout;

    m_listInfo=new QLabel(str_song_list+"[0]",this);

    m_btnmenu=new flatButton(this);
    m_btnmenu->setFixedSize(menu_width,menu_width);
    m_btnmenu->setStyleSheet("QPushButton{border-image:url(:/image/music/indicator_menu (1).png);}"
                             "QPushButton:hover{border-image:url(:/image/music/indicator_menu (2).png);}"
                             "QPushButton:pressed{border-image:url(:/image/music/indicator_menu (3).png);}");

    lyout->addSpacing(10);
    lyout->addWidget(m_listInfo,0,Qt::AlignVCenter);
    lyout->addSpacerItem(new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Fixed));
    lyout->addWidget(m_btnmenu,0,Qt::AlignVCenter);
    lyout->addSpacing(14);
    lyout->setContentsMargins(0,0,0,0);
    lyout->setSpacing(2);
    setLayout(lyout);
}

void playListHeader::initMenu()
{
    m_menu=new QMenu;
    QAction *act_addsong=new QAction(str_add_song,m_menu);
    QAction* act_emptyList=new QAction(str_clear_list,m_menu);

    m_menu->addAction(act_addsong);
    m_menu->addAction(act_emptyList);
    m_menu->addAction(new QAction("1111",m_menu));
    m_menu->addAction(new QAction("2222",m_menu));
    m_menu->addAction(new QAction("3333",m_menu));

    connect(act_addsong,SIGNAL(triggered(bool)),this,SIGNAL(sig_addSong()));
    connect(act_emptyList,SIGNAL(triggered(bool)),this,SIGNAL(sig_emptyList()));

    connect(m_btnmenu,SIGNAL(clicked(bool)),this,SLOT(slot_menuRequest()));
}
