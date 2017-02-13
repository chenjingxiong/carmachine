#ifndef GALLERYTOPWIDGETS_H
#define GALLERYTOPWIDGETS_H

#include "basewidget.h"
#include "basepushbutton.h"

class galleryTopWidgets:public baseWidget
{
public:
    galleryTopWidgets(QWidget *parent);

    FourStateButton *m_btnreturn;
    flatButton *m_btnicon;
    flatButton *m_btnmobile;
    flatButton *m_btnsetting;
    flatButton *m_btnmini;
    flatButton *m_btnexit;
private:
    void initWidget();
};

#endif // GALLERYTOPWIDGETS_H
