#ifndef VIDEOMIDDLEWIDGETLEFT_H
#define VIDEOMIDDLEWIDGETLEFT_H

#include "basewidget.h"
#include "videocontentwidget.h"
#include "videoslider.h"

#include <QLabel>
#include <QVBoxLayout>


class videoMiddleWidgetLeft:public baseWidget
{
    Q_OBJECT
public:
    videoMiddleWidgetLeft(QWidget *parent);

    videoContentWidget* getContentWidget(){return m_contentWid;}
    void addPositionWidget();
    void removePositionWidget();
    void onDurationChanged(qint64 duration);
    void onMediaPositionChanged(qint64);
private:
    QVBoxLayout *vmainlyout;

    videoContentWidget *m_contentWid;
    QWidget *m_positionWid;
    videoSlider *m_slider;
    QLabel *m_currentTime;
    QLabel *m_totalTime;

    void initLayout();
signals:
    void sig_sliderPositionChanged(int);
};

#endif // VIDEOMIDDLEWIDGETLEFT_H
