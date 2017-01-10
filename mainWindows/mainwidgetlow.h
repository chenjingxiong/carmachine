#ifndef MAINWIDGETLOW_H
#define MAINWIDGETLOW_H
#include "basewidget.h"
#include "basepushbutton.h"


class mainWidgetLow:public baseWidget
{
public:
    mainWidgetLow(QWidget *parent = 0);
    // 导航图标，收音机、音乐、视频、相机
    guideButton *m_btnsetting;
    guideButton *m_btnmusic;
    guideButton *m_btnvideo;
    guideButton *m_btncamera;
private:
    void  initLayout();

};

#endif // MAINWIDGETLOW_H
