#include "imageviewerwidget.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include "global_value.h"

int labelWidth;
int labelHeight;

#ifdef DEVICE_EVB
int button_last_image_width = 100;
int layout_spacing = 50;

#else
int button_last_image_width = 40;
int layout_spacing = 30;

#endif

imageViewerWidget::imageViewerWidget(QWidget *parent):baseWidget(parent)
{
    m_middleWidgets = (galleryMiddleWidgets*)parent;
    initLayout();
    initConnection();
}

void imageViewerWidget::initLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    m_imageLabel = new QLabel;
    m_imageLabel->adjustSize();
    m_imageLabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_imageLabel->setAlignment(Qt::AlignCenter);

    m_lastImgBtn = new flatButton(this);
    m_lastImgBtn->setFixedSize(button_last_image_width,button_last_image_width);
    m_lastImgBtn->setStyleSheet("QPushButton{border-image:url(:/image/gallery/ic_last_image.png);}");

    m_nextImgBtn = new flatButton(this);
    m_nextImgBtn->setFixedSize(button_last_image_width,button_last_image_width);
    m_nextImgBtn->setStyleSheet("QPushButton{border-image:url(:/image/gallery/ic_next_image.png);}");

    QHBoxLayout *imageLayout = new QHBoxLayout;
    imageLayout->addWidget(m_lastImgBtn);
    imageLayout->addWidget(m_imageLabel);
    imageLayout->addWidget(m_nextImgBtn);
    imageLayout->setContentsMargins(layout_spacing,0,layout_spacing,0);
    imageLayout->setSpacing(layout_spacing);


    // image control layout
    QHBoxLayout *controlLyout = new QHBoxLayout;

    m_controlWid = new imageControlWidget(this);

    controlLyout->addStretch(0);
    controlLyout->addWidget(m_controlWid);
    controlLyout->addStretch(0);


    mainLayout->setAlignment(Qt::AlignHCenter);
    mainLayout->addSpacing(layout_spacing);
    mainLayout->addLayout(imageLayout);
    mainLayout->addLayout(controlLyout);
    mainLayout->addSpacing(layout_spacing);
    mainLayout->setSpacing(layout_spacing);

    setLayout(mainLayout);
}

void imageViewerWidget::initConnection()
{
    connect(this,SIGNAL(imagesResChanged(QMap<QString,QImage>)),this,SLOT(slot_onImagesResChanged(QMap<QString,QImage>)));

    connect(m_lastImgBtn,SIGNAL(clicked(bool)),this,SLOT(lastImage()));
    connect(m_nextImgBtn,SIGNAL(clicked(bool)),this,SLOT(nextImage()));
    // control
    connect(m_controlWid->m_detailBtn,SIGNAL(clicked(bool)),this,SLOT(slot_viewDetail()));
    connect(m_controlWid->m_deleteBtn,SIGNAL(clicked(bool)),this,SLOT(slot_deleteImage()));
}

void imageViewerWidget::resizeEvent(QResizeEvent *)
{
    labelWidth = m_imageLabel->width();
    labelHeight = m_imageLabel->height();
}

void imageViewerWidget::mousePressEvent(QMouseEvent *event)
{
    if(m_detailWidget)
    {
        m_detailWidget->close();
    }
    QWidget::mousePressEvent(event);
}

void imageViewerWidget::updateRes(QString imagePath, QImage image)
{
    m_imagePath = imagePath;
    m_image = image;
    if(image.width()>labelWidth||image.height()>labelHeight)
    {
        m_imageLabel->setPixmap(QPixmap::fromImage(image.scaled(labelWidth,labelHeight,Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    }else{
        m_imageLabel->setPixmap(QPixmap::fromImage(image));
    }
    emit m_middleWidgets->viewerResChanged(imagePath);
}

void imageViewerWidget::slot_onImagesResChanged(QMap<QString,QImage> imagesRes)
{
    m_imagesRes = imagesRes;
}

void imageViewerWidget::lastImage()
{
    QMap<QString,QImage>::Iterator  it = m_imagesRes.begin();
    while(it != m_imagesRes.end())
    {
        if(it.key() == m_imagePath)
        {
            if(it != m_imagesRes.begin()){
                --it;
            }else{
                it = m_imagesRes.end()-1;
            }
            updateRes(it.key(),it.value());
            break;
        }
        ++it;
    }
}

void imageViewerWidget::nextImage()
{
    QMap<QString,QImage>::Iterator  it = m_imagesRes.begin();
    while(it!=m_imagesRes.end())
    {
        if(it.key() == m_imagePath)
        {
            if(it != (m_imagesRes.end()-1)){
                ++it;
            }else{
                it = m_imagesRes.begin();
            }
            updateRes(it.key(),it.value());
            break;
        }
        ++it;
    }
}

void imageViewerWidget::slot_viewDetail()
{
    if(m_detailWidget)
    {
        m_detailWidget->close();
    }
    m_detailWidget = new ImageDetailWidget();
    m_detailWidget->updateImageInfo(m_imagePath);
    m_detailWidget->show();
}

void imageViewerWidget::slot_deleteImage()
{
    QMessageBox::StandardButton rb = QMessageBox::question(NULL,str_question_Tip,
                                                          str_question_delete_image ,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        nextImage();
        // delete images
        m_imagesRes.remove(m_imagePath);
        m_middleWidgets->imagesResChanged(m_imagesRes);
    }
}

