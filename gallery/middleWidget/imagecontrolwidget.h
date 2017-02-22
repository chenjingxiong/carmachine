#ifndef IMAGECONTROLWIDGET_H
#define IMAGECONTROLWIDGET_H

#include "basewidget.h"
#include "basepushbutton.h"

class imageControlWidget:public baseWidget
{
public:
    imageControlWidget(QWidget *parent = 0);

private:
    void initLayout();

public:
    flatButton *m_detailBtn;
    flatButton *m_expandBtn;
    flatButton *m_rotateBtn;
    flatButton *m_deleteBtn;

};

#endif // IMAGECONTROLWIDGET_H
