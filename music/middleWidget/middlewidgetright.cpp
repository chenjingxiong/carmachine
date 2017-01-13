#include "middlewidgetright.h"
#include <QVBoxLayout>

middleWidgetRight::middleWidgetRight(QWidget *parent):baseWidget(parent)
{
    setStyleSheet("background:transparent");
    initLayout();
}

void middleWidgetRight::initLayout()
{
    QVBoxLayout *vlyout = new QVBoxLayout;

    m_lblTip=new QLabel("",this);
    m_lblTip->setAlignment(Qt::AlignCenter);
    m_lblTip->setFont(QFont("Microsoft YaHei",18,QFont::Normal));
    m_lblTip->setStyleSheet("color:red");
    m_lblTip->adjustSize();

    vlyout->addWidget(m_lblTip);

    setLayout(vlyout);
}
