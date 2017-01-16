#include "settingtopwidgets.h"
#include <QLabel>
#include <QHBoxLayout>

#include "global_value.h"

settingTopWidgets::settingTopWidgets(QWidget *parent):baseWidget(parent)
{
    setStyleSheet("QWidget{background:rgb(42,48,61)}");
    initWidget();
}

void settingTopWidgets::initWidget()
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed); // 竖排固定
    QHBoxLayout *hmainyout=new QHBoxLayout;

    m_btnreturn=new FourStateButton(":/image/main/return.png",this);
    m_btnreturn->setFixedSize(212,70);

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


    QLabel *titleText=new QLabel("Setting",this);
    titleText->setFont(QFont(Font_Family,Font_size_Middle,QFont::DemiBold));
    titleText->setStyleSheet("color:rgb(255,255,255);");
    titleText->setAlignment(Qt::AlignCenter);

    //layou1
    QHBoxLayout *lyout1 = new QHBoxLayout;
    lyout1->addWidget(m_btnreturn);
    lyout1->addSpacing(30);
    lyout1->addWidget(m_btnicon);
    lyout1->addStretch(0);

    //lyout2
    QHBoxLayout *lyout2 = new QHBoxLayout;
    lyout2->addStretch(0);

    hmainyout->addLayout(lyout1);
    hmainyout->addWidget(titleText);
    hmainyout->addStretch(0);
    hmainyout->setContentsMargins(0,0,0,0);
    setLayout(hmainyout);
}
