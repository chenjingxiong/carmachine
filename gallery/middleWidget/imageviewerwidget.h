#ifndef IMAGEVIEWERWIDGET_H
#define IMAGEVIEWERWIDGET_H

#include "basewidget.h"
#include "basepushbutton.h"
#include "gallerymiddlewidgets.h"
#include "imagecontrolwidget.h"
#include "imagedetailwidget.h"
#include "moveablewidget.h"

#include <QLabel>

class galleryMiddleWidgets;

class imageViewerWidget:public baseWidget
{
    Q_OBJECT
public:
    imageViewerWidget(QWidget *parent = 0);

    void updateRes(QString imagePath,QImage image);
    ImageDetailWidget *m_detailWidget;
private:
    void initLayout();
    void initConnection();
private:
    galleryMiddleWidgets *m_middleWidgets;

    QMap<QString,QImage> m_imagesRes;
    QString m_imagePath;
    QImage m_image;

    flatButton *m_lastImgBtn;
    flatButton *m_nextImgBtn;
    QLabel *m_imageLabel;
    // control layout
    imageControlWidget *m_controlWid;
protected:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
private slots:
    void slot_onImagesResChanged(QMap<QString,QImage>);
    void lastImage();
    void nextImage();
    void slot_viewDetail();
    void slot_deleteImage();
signals:
    void imagesResChanged(QMap<QString,QImage>);
};

#endif // IMAGEVIEWERWIDGET_H
