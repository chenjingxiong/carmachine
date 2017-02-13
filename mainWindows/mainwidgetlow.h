#ifndef MAINWIDGETLOW_H
#define MAINWIDGETLOW_H
#include "basewidget.h"
#include "basepushbutton.h"


class mainWidgetLow:public baseWidget
{
public:
    mainWidgetLow(QWidget *parent = 0);
    // five guide button
    guideButton *m_btnSetUp;
    guideButton *m_btnMusic;
    guideButton *m_btnVideo;
    guideButton *m_btnGallery;
    guideButton *m_btnCamera;
private:
    void initLayout();

};

#endif // MAINWIDGETLOW_H
