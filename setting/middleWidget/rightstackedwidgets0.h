#ifndef RIGHTSTACKEDWIDGETS0_H
#define RIGHTSTACKEDWIDGETS0_H

#include <QLabel>
#include <QComboBox>
#include "basewidget.h"
#include "commonwidgets.h"
#include "wlanlisttable.h"
#include "wpa_supplicant/wpamanager.h"

class switchWidget;

class rightStackedWidgets0:public baseWidget
{
    Q_OBJECT
public:
    rightStackedWidgets0(QWidget *parent);

    void insertIntoTable(QString name,QString lock,QString siganl,QString detail);

    QComboBox *m_adapterSeletor;
private:
    void initData();
    void initLayout();
    void initConnection();

    //    switchWidget *m_switchWid;
    wlanListTable *m_table;

    wpaManager *m_netManager; // 网络管理类
public slots:
    void slot_onToggled(bool);
    void slot_onNetOpened();
signals:
    void sig_netOpened();
};


//// 控制开关Widget:包含一个开关控件和一个开关状态提示字体
//class switchWidget:public baseWidget
//{
//public:
//    switchWidget(QWidget *parent);
//    switchButton* getSwitchButton(){return m_btnSwitch;}
//private:
//    QLabel *m_lblState;
//    switchButton *m_btnSwitch;

//};



#endif // RIGHTSTACKEDWIDGETS0_H
