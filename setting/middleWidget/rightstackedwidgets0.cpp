#include "rightstackedwidgets0.h"
#include <QVBoxLayout>

#include "global_value.h"

// about wifi
rightStackedWidgets0::rightStackedWidgets0(QWidget *parent):baseWidget(parent)
{
    setObjectName("rightStackedWidgets0");
    setStyleSheet("#rightStackedWidgets0{background:rgb(33,36,43)}");
    initData();
    initLayout();
    initConnection();  // 连接信号与槽
}

void rightStackedWidgets0::initData()
{
    m_netManager = wpaManager::getInstance(this);

    //    m_netManager->connectB();

}

void rightStackedWidgets0::initLayout()
{
    // 第一行布局，网卡适配器选择
    QHBoxLayout *hlyout1 = new QHBoxLayout;

    QLabel *m_lbladapter = new QLabel(str_wifi_adapter,this);
    m_lbladapter->setFont(QFont("Microsoft YaHei",12,QFont::Normal));

    m_adapterSeletor = new QComboBox(this);
    m_adapterSeletor->setFixedHeight(22);
    m_adapterSeletor->setObjectName(QStringLiteral("m_adapterSeletor"));

    hlyout1->addWidget(m_lbladapter,1);
    hlyout1->addStretch(1);
    hlyout1->addWidget(m_adapterSeletor,1);

    // 第二行布局 TableList
    m_table = new wlanListTable(this);

    QVBoxLayout *vmainlyout = new QVBoxLayout;
    vmainlyout->addSpacing(30);
    vmainlyout->addLayout(hlyout1);
    vmainlyout->addWidget(m_table);
    vmainlyout->addStretch(0);
    vmainlyout->setContentsMargins(0,0,0,0);

    // 空间太大显示不便，加一个横向的布局
    QHBoxLayout *hmainlyout = new QHBoxLayout;
    hmainlyout->addStretch(1);
    hmainlyout->addLayout(vmainlyout,2);
    hmainlyout->addStretch(1);
    setLayout(hmainlyout);

    insertIntoTable("WLan1","Locked","Signal1","Detail");
    insertIntoTable("WLan2","UnLocked","Signal4","Detail");
    insertIntoTable("WLan3","Locked","Signal4","Detail");
}

void rightStackedWidgets0::initConnection()
{
//    connect(m_switchWid->getSwitchButton(),SIGNAL(toggled(bool)),this,SLOT(slot_onToggled(bool)));
    connect(this,SIGNAL(sig_netOpened()),this,SLOT(slot_onNetOpened()));
}

// 点击开关之后触发
void rightStackedWidgets0::slot_onToggled(bool isChecked)
{
    //  打开开关

    //  在Wlan成功打开之后发送 信号:emit sig_netOpened();
}

void rightStackedWidgets0::slot_onNetOpened()
{
    insertIntoTable("WLan2","UnLocked","Signal4","Detail");
    insertIntoTable("WLan3","Locked","Signal4","Detail");
}

void rightStackedWidgets0::insertIntoTable(QString name, QString lock, QString siganl, QString detail)
{
    int rowCount = m_table->rowCount();
    m_table->insertRow(rowCount);
    m_table->setItem(rowCount,0,new QTableWidgetItem(name));
    m_table->setItem(rowCount,1,new QTableWidgetItem(lock));
    m_table->setItem(rowCount,2,new QTableWidgetItem(siganl));
    m_table->setItem(rowCount,3,new QTableWidgetItem(detail));
    m_table->item(rowCount,0)->setTextAlignment(Qt::AlignVCenter|Qt::AlignLeft);
}



//switchWidget::switchWidget(QWidget *parent):baseWidget(parent)
//{

//    m_lblState = new QLabel(str_open_wifi,this);
//    m_lblState->setFont(QFont("Microsoft YaHei",10,QFont::Normal));

//    m_btnSwitch = new switchButton(this);
//    m_btnSwitch->setCheckedColor(QColor(0, 160, 230));
//    m_btnSwitch->setFixedWidth(50);

//    QHBoxLayout *hmainlyout = new QHBoxLayout;
//    hmainlyout->addWidget(m_lblState);
//    hmainlyout->addWidget(m_btnSwitch);

//    setLayout(hmainlyout);
//}
