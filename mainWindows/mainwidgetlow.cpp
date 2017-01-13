#include "mainwidgetlow.h"
#include <QHBoxLayout>


mainWidgetLow::mainWidgetLow(QWidget *parent):baseWidget(parent)
{
    initLayout();
}

void mainWidgetLow::initLayout()
{
    //    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    m_btnsetting=new guideButton(":/image/main/icon_setting.png","radio",this);
    m_btnmusic=new guideButton(":/image/main/icon_music.png","music",this);
    m_btnvideo=new guideButton(":/image/main/icon_video.png","video",this);
    m_btncamera=new guideButton(":/image/main/icon_guide.png","camera",this);

    m_btnsetting->setMinimumSize(150,150);
    m_btnsetting->setMaximumSize(150,150);
    m_btnmusic->setMinimumSize(150,150);
    m_btnmusic->setMaximumSize(150,150);
    m_btnvideo->setMinimumSize(150,150);
    m_btnvideo->setMaximumSize(150,150);
    m_btncamera->setMinimumSize(150,150);
    m_btncamera->setMaximumSize(150,150);

    QHBoxLayout *hmianlyout = new QHBoxLayout;
    hmianlyout->addStretch(2);
    hmianlyout->addWidget(m_btnsetting,1);
    hmianlyout->addSpacing(20);
    hmianlyout->addWidget(m_btnmusic,1);
    hmianlyout->addSpacing(20);
    hmianlyout->addWidget(m_btnvideo,1);
    hmianlyout->addSpacing(20);
    hmianlyout->addWidget(m_btncamera,1);
    hmianlyout->addStretch(1);
    hmianlyout->setContentsMargins(50,0,25,0);
    hmianlyout->setSpacing(50);

    setLayout(hmianlyout);
}
