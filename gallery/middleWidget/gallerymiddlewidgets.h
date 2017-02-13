#ifndef GALLERYMIDDLEWIDGETS_H
#define GALLERYMIDDLEWIDGETS_H

#include "basewidget.h"
#include "emptyimageswidget.h"
#include "imageshowwidget.h"

#include <QStackedLayout>
#include <QListWidget>
#include <QFileInfoList>

class galleryMiddleWidgets:public baseWidget
{
    Q_OBJECT
public:
    galleryMiddleWidgets(QWidget *parent);
private:
    QFileInfoList m_imagesInfoList;
    QMap<QString,QList<QImage> > m_imageMap;
    QList<QImage> m_imageRes;

    QStackedLayout *m_stackedMainLyout;  // the middle page's main layout
    emptyImagesWidget *m_emptyImgWid;
    imageShowWidget *m_imageShowWid;

private:
    void initRes();
    void initLayout();
    void initConnection();

signals:
    void imageEmpty();
private slots:
    void slot_showEmptyImageTip();
};

#endif // GALLERYMIDDLEWIDGETS_H
