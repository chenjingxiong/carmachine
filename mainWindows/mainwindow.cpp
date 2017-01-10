#include "mainwindow.h"
#include <global_value.h>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include "global_value.h"


mainWindow::mainWindow(QWidget *parent):baseWindow(parent)
{
    // 设置布局只需要设置m_mainwid即可
    m_mainwid->setStyleSheet("QLabel{color:white;}");
    setMinimumSize(1000,700);

    initLayout();
    initAnimation();
    initConnection();
    mainwid = this;
}

void mainWindow::initLayout()
{
    m_mainwidup = new mainWidgetUp(m_mainwid);
    m_mainwidlow = new mainWidgetLow(m_mainwid);
    QVBoxLayout *vlyout=new QVBoxLayout;  // m_mainwid's layout(total)
    vlyout->addWidget(m_mainwidup,3);
    vlyout->addWidget(m_mainwidlow,1);
    vlyout->setContentsMargins(0,0,0,0);
    m_mainwid->setLayout(vlyout);

    m_stackedwid = new QStackedWidget(this);
    m_settingwid = new settingWidgets(m_stackedwid);
    m_musicwid  = new musicWidgets(m_stackedwid);
    m_camerawid = new cameraWidgets(m_stackedwid);
    m_videowid = new videoWidgets(m_stackedwid);

    m_stackedwid->addWidget(m_settingwid);
    m_stackedwid->addWidget(m_musicwid);
    m_stackedwid->addWidget(m_camerawid);
    m_stackedwid->addWidget(m_videowid);

    m_mainlyout=new QStackedLayout;
    m_mainlyout->addWidget(m_mainwid);
    m_mainlyout->addWidget(m_stackedwid);

    m_mainlyout->setContentsMargins(0,0,0,0);
    setLayout(m_mainlyout);
    m_mainlyout->setCurrentWidget(m_mainwid);
}

void mainWindow::initConnection()
{
    connect(m_mainwidup->m_btnmini,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));
    connect(m_mainwidup->m_btnexit,SIGNAL(clicked(bool)),this,SLOT(slot_appQuit()));

    connect(m_settingwid->m_topWid->m_btnmini,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));
    connect(m_settingwid->m_topWid->m_btnexit,SIGNAL(clicked(bool)),this,SLOT(slot_appQuit()));
    connect(m_musicwid->m_topwid->m_btnmini,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));
    connect(m_musicwid->m_topwid->m_btnexit,SIGNAL(clicked(bool)),this,SLOT(slot_appQuit()));
    connect(m_camerawid->m_topWid->m_btnmini,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));
    connect(m_camerawid->m_topWid->m_btnexit,SIGNAL(clicked(bool)),this,SLOT(slot_appQuit()));
    connect(m_videowid->m_topWid->m_btnmini,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));
    connect(m_videowid->m_topWid->m_btnexit,SIGNAL(clicked(bool)),this,SLOT(slot_appQuit()));

    connect(m_mainwidlow->m_btnsetting,SIGNAL(clicked()),this,SLOT(slot_showsetting()));
    connect(m_mainwidlow->m_btnmusic,SIGNAL(clicked()),this,SLOT(slot_showmusic()));
    connect(m_mainwidlow->m_btncamera,SIGNAL(clicked()),this,SLOT(slot_showcamera()));
    connect(m_mainwidlow->m_btnvideo,SIGNAL(clicked()),this,SLOT(slot_showvideo()));

    connect(m_upwidclose,SIGNAL(finished()),this,SLOT(slot_closeanimationfinished()));
    connect(m_lowwidclose,SIGNAL(finished()),this,SLOT(slot_closeanimationfinished()));

    // 返回键——返回主界面
    connect(m_musicwid->m_topwid->m_btnreturn,SIGNAL(clicked(bool)),this,SLOT(slot_returnanimation()));
    connect(m_camerawid->m_topWid->m_btnreturn,SIGNAL(clicked(bool)),this,SLOT(slot_returnanimation()));
    connect(m_videowid->m_topWid->m_btnreturn,SIGNAL(clicked(bool)),this,SLOT(slot_returnanimation()));
    connect(m_settingwid->m_topWid->m_btnreturn,SIGNAL(clicked(bool)),this,SLOT(slot_returnanimation()));
}

void mainWindow::slot_appQuit()
{
    m_musicwid->savaSetting();
    m_videowid->savaSetting();
    this->close();
}

void mainWindow::initAnimation()
{
    QDesktopWidget* desktopWidget = QApplication::desktop();

    m_upwidclose=new QPropertyAnimation(m_mainwidup,"pos");
    m_upwidclose->setStartValue(QPoint(0,0));
    m_upwidclose->setEndValue(QPoint(0,-desktopWidget->availableGeometry().height()/4*3));
    m_upwidclose->setDuration(300);

    m_lowwidclose=new QPropertyAnimation(m_mainwidlow,"pos");
    m_lowwidclose->setStartValue(QPoint(0,desktopWidget->availableGeometry().height()/4*3));
    m_lowwidclose->setEndValue(QPoint(0,desktopWidget->availableGeometry().height()));
    m_lowwidclose->setDuration(300);


    m_upwidopen=new QPropertyAnimation(m_mainwidup,"pos");
    m_upwidopen->setStartValue(QPoint(0,-desktopWidget->availableGeometry().height()/4*3));
    m_upwidopen->setEndValue(QPoint(0,0));
    m_upwidopen->setDuration(300);

    m_lowwidopen=new QPropertyAnimation(m_mainwidlow,"pos");
    m_lowwidopen->setStartValue(QPoint(0,desktopWidget->availableGeometry().height()));
    m_lowwidopen->setEndValue(QPoint(0,desktopWidget->availableGeometry().height()/4*3));
    m_lowwidopen->setDuration(300);
}

void mainWindow::slot_showsetting()
{
    m_stackedwid->setCurrentIndex(0);
    m_upwidclose->start();
    m_lowwidclose->start();
}

void mainWindow::slot_showmusic()
{
    m_stackedwid->setCurrentIndex(1);
    m_upwidclose->start();
    m_lowwidclose->start();
}

void mainWindow::slot_showcamera()
{
    m_stackedwid->setCurrentIndex(2);
    m_upwidclose->start();
    m_lowwidclose->start();
}

void mainWindow::slot_showvideo()
{
    m_stackedwid->setCurrentIndex(3);
    m_upwidclose->start();
    m_lowwidclose->start();
}

void mainWindow::slot_returnanimation()
{
    m_mainlyout->setCurrentWidget(m_mainwid);
    m_upwidopen->start();
    //    m_lowwidopen->start();
}

void mainWindow::slot_closeanimationfinished()
{
    m_mainlyout->setCurrentWidget(m_stackedwid);
}

// 解决无边框窗口在最小化之后子控件不刷新的问题
void mainWindow::showEvent(QShowEvent *e)
{
    this->setAttribute(Qt::WA_Mapped);
    QWidget::showEvent(e);
}


mainWindow::~mainWindow()
{
}
