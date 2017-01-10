#ifndef CAMERAWIDGETS_H
#define CAMERAWIDGETS_H

#include "basewidget.h"
#include "cameratopwidgets.h"

//#include <QCamera>
//#include <QCameraViewfinder>
//#include <QCameraImageCapture>


class cameraWidgets:public baseWidget
{
public:
    cameraWidgets(QWidget *parent=0);

    cameraTopWidgets *m_topWid;
private:
//    QCamera *m_camera;
//    QCameraViewfinder *m_viewfinder;
//    QCameraImageCapture *m_imageCapture;

    void init();
    void initLayout();
};

#endif // CAMERAWIDGETS_H
