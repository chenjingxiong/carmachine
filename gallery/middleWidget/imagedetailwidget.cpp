#include "imagedetailwidget.h"
#include <QHBoxLayout>
#include "global_value.h"

#ifdef DEVICE_EVB
int detail_widget_width = 650;
int detail_widget_height = 900;
int confirm_button_width = 130;
int confirm_button_hieght = 60;
int title_width = 200;


#else
int detail_widget_width = 350;
int detail_widget_height = 470;

int confirm_button_width = 60;
int confirm_button_hieght = 30;
int title_width = 80;

#endif

ImageDetailWidget::ImageDetailWidget(QWidget *parent):QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(detail_widget_width,detail_widget_height);
    setObjectName("ImageDetailWidget");
    setStyleSheet("#ImageDetailWidget{background:rgb(56,58,66);border-radius:10px}"
                  "QLabel{color:white;}");
    QFont font = this->font();
    font.setPixelSize(font_size_big);
    setFont(font);
    initLayout();
    initConnection();
}

void ImageDetailWidget::initLayout()
{
    QVBoxLayout *mainLyout = new QVBoxLayout;

    QFrame *underLine=new QFrame(this);
    underLine->setFixedHeight(1);
    underLine->setStyleSheet("QFrame{border:1px solid rgb(255,255,255);}");
    underLine->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    // header
    QHBoxLayout *headerLyout = new QHBoxLayout;

    QLabel *titleLabel = new QLabel(str_image_information,this);
    QFont font = titleLabel->font();
    font.setBold(true);
    titleLabel->setFont(font);
    titleLabel->setAlignment(Qt::AlignLeft);

    m_btnClose =  new flatButton(this);
    m_btnClose->setFixedSize(16,16);
    m_btnClose->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_close (1).png);}"
                              "QPushButton::hover{border-image:url(:/image/main/btn_close (2).png);}"
                              "QPushButton::pressed{border-image:url(:/image/main/btn_close (3).png);}");

    headerLyout->addSpacing(10);
    headerLyout->addWidget(titleLabel);
    headerLyout->addStretch(0);
    headerLyout->addWidget(m_btnClose);
    headerLyout->addSpacing(10);

    // image infomation
    QVBoxLayout *infoLyout = new QVBoxLayout;

    nameItem = new ImageItem(this);
    patternItem = new ImageItem(this);
    resolutionItem = new ImageItem(this);
    locationItem = new ImageItem(this);
    sizeItem = new ImageItem(this);
    createTimeItem = new ImageItem(this);

    infoLyout->addWidget(nameItem);
    infoLyout->addWidget(patternItem);
    infoLyout->addWidget(resolutionItem);
    infoLyout->addWidget(locationItem);
    infoLyout->addWidget(sizeItem);
    infoLyout->addWidget(createTimeItem);

    // confirm cancel button
    QHBoxLayout *controlLyout = new QHBoxLayout;

    m_btnConfirm = new flatButton(str_confirm,this);
    m_btnConfirm->setStyleSheet("QPushButton{background:rgb(36,184,71);color:white;border-radius:5px}"
                                "QPushButton::hover{background:rgb(25,166,58)}"
                                "QPushButton::pressed{background:rgb(25,166,58)}");
    m_btnConfirm->setFixedSize(confirm_button_width,confirm_button_hieght);

    controlLyout->addStretch(0);
    controlLyout->addWidget(m_btnConfirm);
    controlLyout->setContentsMargins(10,10,20,10);


    mainLyout->addLayout(headerLyout);
    mainLyout->addWidget(underLine);
    mainLyout->addSpacing(20);
    mainLyout->addLayout(infoLyout);
    mainLyout->addStretch(0);
    mainLyout->addLayout(controlLyout);
    mainLyout->setContentsMargins(0,10,0,10);

    setLayout(mainLyout);
}

void ImageDetailWidget::initConnection()
{
    connect(m_btnClose,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(m_btnConfirm,SIGNAL(clicked(bool)),this,SLOT(close()));
}

QString getImageResolution(QString imagePath)
{
    QString result;
    QImage image;
    if(image.load(imagePath)){
        result.append(QString::number(image.width())).append("×").append(QString::number(image.height())).append(str_resolution_tip);
    }
    return result;
}

/**
 * @brief convert size form B to other
 * @param size
 * @return
 */
QString convertFileSize(qint64 size) {
    QString unit = "B";
    qint64 curSize = size;
    double curSize2 =0;
    if(curSize > 1024)
    {
        curSize /= 1024;
        unit = "KB";
        if(curSize > 1024)
        {
            curSize2 = curSize/1024.00;
            unit = "MB";
            return QString::number(curSize2,'f',2).append(unit);
        }
    }
    return QString::number(curSize).append(unit);
}

void ImageDetailWidget::updateImageInfo(QString imagePath)
{
    QFileInfo *info = new QFileInfo(imagePath);
    if(info->exists())
    {
        nameItem->updateItem(str_image_name,info->baseName());
        patternItem->updateItem(str_image_pattern,info->completeSuffix());
        resolutionItem->updateItem(str_image_resolution,getImageResolution(imagePath));
        locationItem->updateItem(str_image_location,info->absolutePath());
        sizeItem->updateItem(str_image_size,convertFileSize(info->size()));
        createTimeItem->updateItem(str_image_create_time,info->created().toString("yyyy-MM-dd hh:mm"));
    }
}

ImageItem::ImageItem(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *lyout = new QHBoxLayout;

    titleLabel = new QLabel(this);
    titleLabel->setAlignment(Qt::AlignRight);
    titleLabel->setFixedWidth(title_width);

    textLabel = new QLabel(this);

    lyout->addWidget(titleLabel);
    lyout->addWidget(textLabel);
    lyout->addStretch(0);
    lyout->setSpacing(10);
    lyout->setContentsMargins(0,0,0,0);

    setLayout(lyout);
}

void ImageItem::updateItem(QString title, QString text)
{
    titleLabel->setText(title+":");
    textLabel->setText(text);
}
