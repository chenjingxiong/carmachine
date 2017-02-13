#ifndef GALLERYWIDGETS_H
#define GALLERYWIDGETS_H

#include "basewidget.h"
#include "gallerytopwidgets.h"
#include "middleWidget/gallerymiddlewidgets.h"

class galleryWidgets:public baseWidget
{
public:
    galleryWidgets(QWidget *parent);

    galleryTopWidgets *m_topWid;
    galleryMiddleWidgets *m_middleWid;
private:
    void init();
    void initLayout();
};

#endif // GALLERYWIDGETS_H
