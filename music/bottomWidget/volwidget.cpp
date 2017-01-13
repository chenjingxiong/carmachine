#include "volwidget.h"
#include <QHBoxLayout>
#include "basepushbutton.h"


volWidget::volWidget(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *lyout=new QHBoxLayout;
    m_slider_vol=new mySlider(Qt::Horizontal,this);
    m_slider_vol->setFixedSize(100,60);
    m_slider_vol->setStyleSheet("QSlider::groove:horizontal{border-radius:2px;height:10px;}"
                                "QSlider::sub-page:horizontal{background:rgb(27,157,255);}"
                                "QSlider::add-page:horizontal{background:rgb(209,209,209);}"
                                "QSlider::handle:horizontal{background:rgb(255,255,255);width:8px;border-radius:4px;margin:-3px 0px -3px 0px;}");
    m_slider_vol->setCursor(Qt::PointingHandCursor);
    volButton *btn=new volButton(":/image/music/menu_vol.png",this);
    btn->setParentSlider(m_slider_vol);
    btn->setFixedSize(70,70);

    lyout->addWidget(btn,0,Qt::AlignRight|Qt::AlignVCenter);
    lyout->addWidget(m_slider_vol,0,Qt::AlignLeft|Qt::AlignVCenter);
    lyout->setContentsMargins(0,0,0,0);
    lyout->setSpacing(0);
    setLayout(lyout);

    connect(m_slider_vol,SIGNAL(valueChanged(int)),btn,SLOT(setButtonPixmap(int)));
    connect(m_slider_vol,SIGNAL(valueChanged(int)),this,SIGNAL(sig_valueChanged(int)));
    connect(btn,SIGNAL(setMute(int)),m_slider_vol,SLOT(setValue(int)));
    m_slider_vol->setValue(80);
}
