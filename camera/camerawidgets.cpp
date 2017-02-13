#include "camerawidgets.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

cameraWidgets::cameraWidgets(QWidget *parent):baseWidget(parent)
{
    setObjectName("cameraWidgets");
    setStyleSheet("#cameraWidgets{border-image: url(:/image/camera/camera_bg.jpg);}");
    init();
    initLayout();
}

void cameraWidgets::init()
{
//    m_camera = new QCamera(this);
//    m_viewfinder=new QCameraViewfinder(this);
//    m_imageCapture=new QCameraImageCapture(m_camera);


//    m_camera->setViewfinder(m_viewfinder);
//    m_camera->start();
}

void cameraWidgets::initLayout()
{
    QVBoxLayout *vmainlyout = new QVBoxLayout;

    m_topWid = new cameraTopWidgets(this);

    // 下半部分布局
    QHBoxLayout *hmiddlelyout = new QHBoxLayout;
//    hmiddlelyout->addWidget(m_viewfinder);
    hmiddlelyout->setContentsMargins(0,0,0,0);
    hmiddlelyout->setSpacing(0);


    vmainlyout->addWidget(m_topWid);
    vmainlyout->addLayout(hmiddlelyout);
    vmainlyout->addStretch(0);
    vmainlyout->setContentsMargins(0,0,0,0);
    vmainlyout->setSpacing(0);

    setLayout(vmainlyout);
}
