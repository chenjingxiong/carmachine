#include "settingwidgets.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

settingWidgets::settingWidgets(QWidget *parent):baseWidget(parent)
{
    setObjectName("settingWidgets");
    setStyleSheet("#settingWidgets{border-image: url(:/image/setting/setting_bg.jpg);}"
                  "QLabel{color:white;}");
    initLayout();
}


void settingWidgets::initLayout()
{
    QVBoxLayout *vmainlyout = new QVBoxLayout;

    m_topWid = new settingTopWidgets(this);
    m_middleWid = new settingMiddleWidgets(this);

    vmainlyout->addWidget(m_topWid);
    vmainlyout->addWidget(m_middleWid);
    vmainlyout->setContentsMargins(0,0,0,0);
    vmainlyout->setSpacing(0);

    setLayout(vmainlyout);
}
