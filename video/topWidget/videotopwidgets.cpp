#include "videotopwidgets.h"

#include <QHBoxLayout>
#include <QLabel>

#include "global_value.h"

videoTopWidgets::videoTopWidgets(QWidget *parent):baseWidget(parent)
{
    setObjectName("videoTopWidgets");
    setStyleSheet("#videoTopWidgets{background:rgb(56,58,66)}");
    initWidget();
}

void videoTopWidgets::initWidget()
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed); // 竖排固定
    QHBoxLayout *hmainyout=new QHBoxLayout;

    m_btnreturn=new FourStateButton(":/image/main/return.png",this);
    m_btnreturn->setFixedSize(115,40);

    m_btnicon=new flatButton(this);
    m_btnicon->setFixedSize(40,40);
    m_btnicon->setStyleSheet("QPushButton{background:transparent;border-image:url(:/image/video/video_icon.png)}");

    m_btnexit=new flatButton(this);
    m_btnmini=new flatButton(this);
    m_btnmobile=new flatButton(this);
    m_btnsetting=new flatButton(this);

    m_btnexit->setFixedSize(18,18);
    m_btnmini->setFixedSize(16,16);
    m_btnmobile->setFixedSize(16,16);
    m_btnsetting->setFixedSize(16,16);

    m_btnexit->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_close (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/main/btn_close (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/main/btn_close (3).png);}");
    m_btnmini->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_mini (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/main/btn_mini (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/main/btn_mini (3).png);}");
    m_btnmobile->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_mobile (1).png);}"
                               "QPushButton::hover{border-image:url(:/image/main/btn_mobile (2).png);}"
                               "QPushButton::pressed{border-image:url(:/image/main/btn_mobile (3).png);}");
    m_btnsetting->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_setting (1).png);}"
                                "QPushButton::hover{border-image:url(:/image/main/btn_setting (2).png);}"
                                "QPushButton::pressed{border-image:url(:/image/main/btn_setting (3).png);}");

    QLabel*label1=new QLabel("丨",this);
    label1->setFixedSize(6,16);
    label1->setStyleSheet("color:rgb(255,255,255,255);");
    label1->adjustSize();

    m_playingVideoName=new QLabel(str_videoName_default,this);
    m_playingVideoName->setFont(QFont("Microsoft YaHei",12,QFont::DemiBold));
    m_playingVideoName->setStyleSheet("color:rgb(255,255,255,255);");
    m_playingVideoName->adjustSize();

    hmainyout->addWidget(m_btnreturn);
    hmainyout->addSpacing(30);
    hmainyout->addWidget(m_btnicon);
    hmainyout->addSpacing(100);
    hmainyout->addWidget(m_playingVideoName);
    hmainyout->addStretch(0);
    hmainyout->addWidget(label1);
    hmainyout->addWidget(m_btnmobile);
    hmainyout->addWidget(m_btnsetting);
    hmainyout->addWidget(m_btnmini);
    hmainyout->addWidget(m_btnexit);
    hmainyout->setSpacing(12);
    hmainyout->setContentsMargins(0,0,10,0);
    setLayout(hmainyout);
}
