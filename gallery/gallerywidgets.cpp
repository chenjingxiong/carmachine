#include "gallerywidgets.h"
#include <QVBoxLayout>
#include <QHBoxLayout>


galleryWidgets::galleryWidgets(QWidget *parent):baseWidget(parent)
{
    init();
    initLayout();
}


void galleryWidgets::init()
{

}

void galleryWidgets::initLayout()
{
    QVBoxLayout *vmainlyout = new QVBoxLayout;

    // the top widget of gallery page
    m_topWid = new galleryTopWidgets(this);
    // the middle widget of gallery page
    m_middleWid = new galleryMiddleWidgets(this);


    vmainlyout->addWidget(m_topWid);
    vmainlyout->addWidget(m_middleWid);
    vmainlyout->setContentsMargins(0,0,0,0);
    vmainlyout->setSpacing(0);

    setLayout(vmainlyout);
}

