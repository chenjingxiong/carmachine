#include "gallerymiddlewidgets.h"
#include <QDir>
#include <qdebug.h>
#include <QApplication>
#include <QDirIterator>
#include <QDateTime>

#include "global_value.h"

galleryMiddleWidgets::galleryMiddleWidgets(QWidget *parent):baseWidget(parent)
{
    setObjectName("galleryMiddleWidgets");
    setStyleSheet("#galleryMiddleWidgets{background:rgb(43,45,51)}");
    initLayout();
    initConnection();
    initRes(); // init m_images
}

/**
 * @brief used to find all image file in path
 * @param path
 * @return
 */
QFileInfoList findImgFiles(const QString& path = QString(""))
{
    QFileInfoList imageFiles;

    QDirIterator it(path,QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
    while (it.hasNext())
    {
        QString name = it.next();
        QFileInfo info(name);
        if (info.isDir())
        {
            imageFiles.append(findImgFiles(name));
        }
        else
        {
            if (info.suffix() == "jpg" || info.suffix() == "bmp" || info.suffix() == "png")
            {
                imageFiles.append(info);
            }
        }
    }
    return imageFiles;
}


void galleryMiddleWidgets::initRes()
{
    m_imageMap.clear();
    m_imagesInfoList.clear();

    // get all image files and user class QImage to get thumbnail
    m_imagesInfoList = findImgFiles(MUSIC_SEARCH_PATH);
    qDebug("gallery: the size of images is %d",m_imagesInfoList.size());
    QImage tempImage;
    for(int i = 0;i < m_imagesInfoList.size();i++)
    {
        if(tempImage.load(m_imagesInfoList.at(i).absoluteFilePath()))
        {
            if(!m_imageMap.contains(m_imagesInfoList.at(i).absolutePath()))
            {
                m_imageMap.insert(m_imagesInfoList.at(i).absolutePath(),QList<QImage>());
            }
            /* used to insert value into list that is the value of map */
            QList<QImage> tempList =m_imageMap.value(m_imagesInfoList.at(i).absolutePath());
            tempList.append(tempImage);
            m_imageMap.insert(m_imagesInfoList.at(i).absolutePath(),tempList);
            m_imageRes.append(tempImage);
        }
    }
    if(m_imageMap.size()>0)
    {
        m_imageShowWid->updateList(m_imageRes);
    }
    else
    {
        emit imageEmpty();
    }
}

void galleryMiddleWidgets::initConnection()
{
    connect(this,SIGNAL(imageEmpty()),this,SLOT(slot_showEmptyImageTip()));
}

void galleryMiddleWidgets::initLayout()
{
    m_stackedMainLyout = new QStackedLayout(this);

    m_emptyImgWid = new emptyImagesWidget(this);


    m_imageShowWid = new imageShowWidget(this);

    m_stackedMainLyout->addWidget(m_emptyImgWid);
    m_stackedMainLyout->addWidget(m_imageShowWid);
    m_stackedMainLyout->setCurrentWidget(m_imageShowWid);

    setLayout(m_stackedMainLyout);
}

void galleryMiddleWidgets::slot_showEmptyImageTip()
{
    m_stackedMainLyout->setCurrentWidget(m_emptyImgWid);

}
