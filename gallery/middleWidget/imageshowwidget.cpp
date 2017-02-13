#include "imageshowwidget.h"

#include <QHBoxLayout>
#include <QIcon>
#include <qdebug.h>

#include "global_value.h"

imageShowWidget::imageShowWidget(QWidget *parent):QScrollArea(parent)
{
    setStyleSheet("background:transparent");
    initLayout();
}

void imageShowWidget::initLayout()
{

}

void imageShowWidget::updateList(QList<QImage> images)
{
    m_images.clear();
    m_images = images;

    QVBoxLayout *lyout = new QVBoxLayout;
    lyout->setContentsMargins(0,0,0,0);
    lyout->setSpacing(0);

    imagesItemWidget *itemWidget = new imagesItemWidget(this,"",m_images);
    lyout->addWidget(itemWidget);

    setLayout(lyout);
}


imagesItemWidget::imagesItemWidget(QWidget *parent,QString catalog,QList<QImage> imageList):baseWidget(parent)
{
    m_catalog = catalog;
    m_imageList = imageList;

    initLayout();
    m_header->updateTitleText(imageList.size());
}

void imagesItemWidget::initLayout()
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_header = new ImageItemHeader(this,m_catalog);

    m_imageListWid = new QListWidget(this);
    m_imageListWid->setIconSize(QSize(130,130));
    m_imageListWid->setStyleSheet("QListWidget::item:selected{background: transparent;}");
    /* cancel the border in ListWidget */
    m_imageListWid->setFrameShape(QListWidget::NoFrame);
    /* set QListWidget be IconMode to show image thumnail and unable to drag */
    m_imageListWid->setViewMode(QListView::IconMode);
    m_imageListWid->setMovement(QListView::Static);
    m_imageListWid->setSpacing(20);
    m_imageListWid->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_imageListWid->setFocusPolicy(Qt::NoFocus);


    QVBoxLayout *lyout = new QVBoxLayout;
    lyout->addWidget(m_header);
    lyout->addWidget(m_imageListWid);
    lyout->setContentsMargins(0,0,0,0);
    lyout->setSpacing(0);

    setLayout(lyout);

    updateWidget(m_imageList);
}

void imagesItemWidget::updateWidget(QList<QImage> imageList)
{
    for(int i=0;i<imageList.size();i++)
    {
        QListWidgetItem *listItem =
                new QListWidgetItem(QIcon(QPixmap::fromImage(imageList.at(i)).scaled(130,130)),NULL);
        m_imageListWid ->insertItem(i,listItem);
    }
}

ImageItemHeader::ImageItemHeader(QWidget *parent,QString titleText):baseWidget(parent)
{
    setStyleSheet("background:rgb(73,77,86)");
    setFixedHeight(40);

    m_titleText = new QLabel(titleText,this);
    m_titleText->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);
    QFont font = m_titleText->font();
    font.setPixelSize(font_size_big);
    m_titleText->setFont(font);

    QHBoxLayout *lyout = new QHBoxLayout;
    lyout->addSpacing(20);
    lyout->addWidget(m_titleText);

    setLayout(lyout);
}

void ImageItemHeader::updateTitleText(int size)
{
    m_titleText->setText("～图片与预览("+QString::number(size)+")");
}


