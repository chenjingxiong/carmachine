#include "videoslider.h"

videoSlider::videoSlider(Qt::Orientation orientation,QWidget*parent):QSlider(orientation,parent)
{
    setStyleSheet("QSlider::groove:horizontal{border-radius:2px;height:9px;}"
                  "QSlider::sub-page:horizontal{background:rgb(26,158,255);}"
                  "QSlider::add-page:horizontal{background:rgb(200,200,209);}"
                  "QSlider::handle:horizontal{background:rgb(255, 255, 160);width:8px;border-radius:4px;margin:-3px 0px -3px 0px;}");

    setCursor(Qt::PointingHandCursor);
    setMouseTracking(true);
}

void videoSlider::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)	{
        int dur = maximum() - minimum();
        int pos = minimum() + dur * ((double)event->x() / width());
        if(pos != sliderPosition()){
            setValue(pos);
            emit sig_sliderPositionChanged(pos);
        }
    }
}
