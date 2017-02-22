#include "imagecontrolwidget.h"

#include <QHBoxLayout>



#ifdef DEVICE_EVB
int image_width = 100;
int image_spacing = 100;

#else
int image_width = 40;
int image_spacing = 50;

#endif

imageControlWidget::imageControlWidget(QWidget *parent):baseWidget(parent)
{
    setFixedSize(image_width*5+image_spacing*4,image_width);
    setStyleSheet("QWidget{background-color:gray;border-radius:5px}");
    initLayout();
}

void imageControlWidget::initLayout()
{
    QHBoxLayout *lyout = new QHBoxLayout;

    m_detailBtn = new flatButton(this);
    m_detailBtn->setFixedSize(image_width,image_width);
    m_detailBtn->setStyleSheet("QPushButton{border-image:url(:/image/gallery/ic_detail.png);}");

    m_expandBtn = new flatButton(this);
    m_expandBtn->setFixedSize(image_width,image_width);
    m_expandBtn->setStyleSheet("QPushButton{border-image:url(:/image/gallery/ic_expand.png);}");

    m_rotateBtn = new flatButton(this);
    m_rotateBtn->setFixedSize(image_width,image_width);
    m_rotateBtn->setStyleSheet("QPushButton{border-image:url(:/image/gallery/ic_rotate.png);}");

    m_deleteBtn = new flatButton(this);
    m_deleteBtn->setFixedSize(image_width,image_width);
    m_deleteBtn->setStyleSheet("QPushButton{border-image:url(:/image/gallery/ic_delete.png);}");

    lyout->addStretch(0);
    lyout->addWidget(m_detailBtn);
    lyout->addWidget(m_expandBtn);
    lyout->addWidget(m_rotateBtn);
    lyout->addWidget(m_deleteBtn);
    lyout->addStretch(0);
    lyout->setContentsMargins(0,0,0,0);
    lyout->setSpacing(image_spacing);

    setLayout(lyout);
}
