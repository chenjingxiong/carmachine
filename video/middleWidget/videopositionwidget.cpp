#include "videopositionwidget.h"
#include <QHBoxLayout>
#include "global_value.h"

videoPositionWidget::videoPositionWidget(QWidget *parent):baseWidget(parent)
{
    setFixedHeight(110);
    setStyleSheet("background:rgb(31,31,31)");
    initWidget();
}

void videoPositionWidget::initWidget()
{
    QHBoxLayout *lyout = new QHBoxLayout;

    m_slider = new videoSlider(Qt::Horizontal,this);
    m_slider->setRange(0,0);

    m_currentTime = new QLabel("00:00",this);
    m_currentTime->setFont(QFont(Font_Family,Font_size_Small,QFont::Normal));
    m_currentTime->setStyleSheet("color:rgb(150,150,150);");
    m_currentTime->setAlignment(Qt::AlignVCenter);


    m_totalTime = new QLabel("00:00",this);
    m_totalTime->setFont(QFont(Font_Family,Font_size_Small,QFont::Normal));
    m_totalTime->setStyleSheet("color:rgb(150,150,150);");
    m_totalTime->setAlignment(Qt::AlignVCenter);

    lyout->addSpacing(10);
    lyout->addWidget(m_currentTime);
    lyout->addWidget(m_slider);
    lyout->addWidget(m_totalTime);
    lyout->addSpacing(10);
    lyout->setSpacing(10);
    lyout->setContentsMargins(0,0,0,0);

    QVBoxLayout *mainlyout = new QVBoxLayout;

    QWidget *fillWidget = new QWidget(this);
    fillWidget->setFixedHeight(50);
    fillWidget->setStyleSheet("background:rgb(0,0,0)");

    mainlyout->addWidget(fillWidget);
    mainlyout->addLayout(lyout);
    mainlyout->setSpacing(0);
    mainlyout->setContentsMargins(0,0,0,0);

    setLayout(mainlyout);
}

void videoPositionWidget::mousePressEvent(QMouseEvent *event)
{
    if(m_slider->x() < event->x() && event->x() < (m_slider->x()+m_slider->width())){
        int dur = m_slider->maximum() - m_slider->minimum();
        int pos = m_slider->minimum() + dur * (((double)event->x()-m_slider->x())/ m_slider->width());
        if(pos != m_slider->sliderPosition()){
            m_slider->setValue(pos);
            emit m_slider->sig_sliderPositionChanged(pos);
        }
    }
}
