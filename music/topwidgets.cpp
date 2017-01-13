#include "topwidgets.h"
#include <QHBoxLayout>
#include <QLabel>
#include "global_value.h"

topWidgets::topWidgets(QWidget *parent):baseWidget(parent)
{
    initWidget();
}

void topWidgets::initWidget()
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed); // 竖排固定
    QHBoxLayout *hmainyout=new QHBoxLayout;

    m_btnreturn=new FourStateButton(":/image/main/return.png",this);
    m_btnreturn->setFixedSize(181,60);

    m_btnicon=new flatButton(this);
    m_btnicon->setFixedSize(60,60);
    m_btnicon->setStyleSheet("QPushButton{background:transparent;border-image:url(:/image/music/music_top_icon.png)}");

//    m_btnexit=new flatButton(this);
//    m_btnmini=new flatButton(this);
//    m_btnmobile=new flatButton(this);
//    m_btnsetting=new flatButton(this);

//    m_btnexit->setFixedSize(18,18);
//    m_btnmini->setFixedSize(16,16);
//    m_btnmobile->setFixedSize(16,16);
//    m_btnsetting->setFixedSize(16,16);

//    m_btnexit->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_close (1).png);}"
//                             "QPushButton::hover{border-image:url(:/image/main/btn_close (2).png);}"
//                             "QPushButton::pressed{border-image:url(:/image/main/btn_close (3).png);}");
//    m_btnmini->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_mini (1).png);}"
//                             "QPushButton::hover{border-image:url(:/image/main/btn_mini (2).png);}"
//                             "QPushButton::pressed{border-image:url(:/image/main/btn_mini (3).png);}");
//    m_btnmobile->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_mobile (1).png);}"
//                               "QPushButton::hover{border-image:url(:/image/main/btn_mobile (2).png);}"
//                               "QPushButton::pressed{border-image:url(:/image/main/btn_mobile (3).png);}");
//    m_btnsetting->setStyleSheet("QPushButton{border-image:url(:/image/main/btn_setting (1).png);}"
//                                "QPushButton::hover{border-image:url(:/image/main/btn_setting (2).png);}"
//                                "QPushButton::pressed{border-image:url(:/image/main/btn_setting (3).png);}");

//    QLabel*label1=new QLabel("丨",this);
//    label1->setFixedSize(6,16);
//    label1->setStyleSheet("color:rgb(255,255,255,255);");
//    label1->adjustSize();

    //layou1
    QHBoxLayout *lyout1 = new QHBoxLayout;
    lyout1->addWidget(m_btnreturn);
    lyout1->addSpacing(30);
    lyout1->addWidget(m_btnicon);
    lyout1->addSpacing(100);

    QLabel*label2=new QLabel("Music Player",this);
    label2->setFont(QFont(Font_Family,Font_size_Middle,QFont::DemiBold));
    label2->setStyleSheet("color:rgb(0,0,0);");
    label2->adjustSize();

    //lyout2
    QHBoxLayout *lyout2 = new QHBoxLayout;
    lyout2->addStretch(0);

    hmainyout->addLayout(lyout1,1);
    hmainyout->addWidget(label2,1);
    hmainyout->addLayout(lyout2,1);
    hmainyout->setSpacing(12);
    hmainyout->setContentsMargins(0,0,0,0);
    setLayout(hmainyout);
}
