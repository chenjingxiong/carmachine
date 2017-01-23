#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStackedWidget>
#include <QObject>

#include "basewindow.h"
#include "mainwidgetup.h"
#include "mainwidgetlow.h"
#include "musicwidgets.h"
#include "camerawidgets.h"
#include "videowidgets.h"
#include "settingwidgets.h"

#include <QPropertyAnimation>
#include <QStackedLayout>

class mainWindow : public baseWindow
{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

    musicWidgets* getMusicWidget(){return m_musicwid;}
private:
    QStackedWidget *m_stackedwid;
    musicWidgets *m_musicwid;
    cameraWidgets *m_camerawid;
    videoWidgets *m_videowid;
    settingWidgets *m_settingwid;

    mainWidgetUp *m_mainwidup;
    mainWidgetLow *m_mainwidlow;

    QStackedLayout *m_mainlyout;     // 主界面的堆栈式布局，包含两个元素: m_mainwid和m_stackedwid

    // 进入具体板块的动画效果
    QPropertyAnimation *m_upwidclose;
    QPropertyAnimation *m_lowwidclose;
    QPropertyAnimation *m_upwidopen;
    QPropertyAnimation *m_lowwidopen;

    void initLayout();
    void initConnection();
    void initAnimation();

private:
protected:
    // 解决无边框窗口在最小化之后子控件不刷新的问题
    void showEvent(QShowEvent *e);
private slots:
    void slot_appQuit();
    void slot_showsetting();
    void slot_showmusic();
    void slot_showvideo();
    void slot_showcamera();
    void slot_returnanimation();
    void slot_closeanimationfinished();
};
#endif // MAINWINDOW_H
