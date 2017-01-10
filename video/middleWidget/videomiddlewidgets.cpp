#include "videomiddlewidgets.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

videoMiddleWidgets::videoMiddleWidgets(QWidget *parent):baseWidget(parent)
{
    initLayout();
}

void videoMiddleWidgets::initLayout()
{
    QHBoxLayout *hmainlyout = new QHBoxLayout;

    m_rightWid = new videoMiddleWidgetRight(this);
    m_leftWid = new videoMiddleWidgetLeft(this);

    hmainlyout->addWidget(m_leftWid,4);
    hmainlyout->addWidget(m_rightWid,1);
    hmainlyout->setContentsMargins(0,0,0,0);
    hmainlyout->setSpacing(0);

    setLayout(hmainlyout);
}

