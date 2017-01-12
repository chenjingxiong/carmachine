#include "settingtopwidgets.h"
#include <QLabel>
#include <QHBoxLayout>

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
    m_btnreturn->setFixedSize(115,40);

    m_btnicon=new flatButton(this);
    m_btnicon->setFixedSize(40,40);
    m_btnicon->setStyleSheet("QPushButton{background:transparent;border-image:url(:/image/setting/setting_icon.png)}");

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

    QLabel*label2=new QLabel("Setting",this);
    label2->setFont(QFont("Microsoft YaHei",12,QFont::DemiBold));
    label2->setStyleSheet("color:rgb(255,255,255,255);");
    label2->adjustSize();

    hmainyout->addWidget(m_btnreturn);
    hmainyout->addSpacing(30);
    hmainyout->addWidget(m_btnicon);
    hmainyout->addSpacing(100);
    hmainyout->addWidget(label2);
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
