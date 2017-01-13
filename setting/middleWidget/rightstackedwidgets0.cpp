#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

//#include <stdlib.h>
//#include <fcntl.h>
//#include <dirent.h>
//#include <sys/socket.h>
//#include <sys/stat.h>
//#include <unistd.h>
//#include <poll.h>
//#include <stdbool.h>
#include "rightstackedwidgets0.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QThread>
#include "netconfigdialog.h"
#include "global_value.h"

#define DEBUG_INFO qDebug
#define DEBUG_ERR qDebug

static const char WPA_SUPPLICANT_CONF_DIR[] = "/tmp/wpa_supplicant.conf";
int creat_supplicant_file();
int is_supplicant_running();

// about wifi
rightStackedWidgets0::rightStackedWidgets0(QWidget *parent):baseWidget(parent)
{
    setObjectName("rightStackedWidgets0");
    setStyleSheet("#rightStackedWidgets0{background:rgb(33,36,43)}");
    initLayout();
    initData();
    initConnection();  // 连接信号与槽
}

void rightStackedWidgets0::initData()
{
//    wifiWid = this;
//    m_netManager = wpaManager::getInstance(this);
//    m_wifiSwitch->getSwitchButton()->setToggle(is_supplicant_running());
//    if(is_supplicant_running())
//    {
//        m_netManager->openCtrlConnection("wlan0");
//    }
}

void rightStackedWidgets0::initLayout()
{
//    // 第1行布局 开关
//    m_wifiSwitch = new switchWidget(this);


//    // 第2部分布局 TabWidget 包含2部分内容:Current status、WifiList
//    m_tab = new QTabWidget(this);
//    m_tab->setStyleSheet("background:rgb(33,36,43)");

//    m_tabCurrentStatus = new tabCurrentStatus(this);
//    m_tabScanResult = new tabScanResult(this);
//    m_tab->addTab(m_tabScanResult,QString("scan result"));
//    m_tab->addTab(m_tabCurrentStatus,QString("Current Status"));
//    m_tab->setCurrentIndex(0);


//    QVBoxLayout *vmainlyout = new QVBoxLayout;
//    vmainlyout->addSpacing(30);
//    //    vmainlyout->addLayout(hlyout1);
//    vmainlyout->addWidget(m_wifiSwitch);
//    vmainlyout->addWidget(m_tab);
//    vmainlyout->addStretch(0);
//    vmainlyout->setContentsMargins(0,0,0,0);
//    vmainlyout->setSpacing(12);

//    // 空间太大显示不便，加一个横向的布局
//    QHBoxLayout *hmainlyout = new QHBoxLayout;
//    hmainlyout->addStretch(1);
//    hmainlyout->addLayout(vmainlyout,3);
//    hmainlyout->addStretch(1);
//    setLayout(hmainlyout);
}

void rightStackedWidgets0::initConnection()
{
//    if (access(WPA_SUPPLICANT_CONF_DIR, F_OK) < 0) {
//        creat_supplicant_file();
//    }
//    //    connect(m_adapterSeletor,SIGNAL(activated(const QString&)),m_netManager,SLOT(selectAdapter(const QString&)));

//    connect(m_tabCurrentStatus->connectButton,SIGNAL(clicked(bool)),m_netManager,SLOT(connectB()));
//    connect(m_tabCurrentStatus->disconnectButton,SIGNAL(clicked(bool)),m_netManager,SLOT(disconnectB()));
//    connect(m_tabScanResult->scanButton,SIGNAL(clicked(bool)),m_netManager,SLOT(scan()));

//    connect(m_tabScanResult->m_table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(slot_showItemDetail(int,int)));

//    connect(m_wifiSwitch->getSwitchButton(),SIGNAL(toggled(bool)),this,SLOT(slot_onToggled(bool)));
}

void rightStackedWidgets0::slot_showItemDetail(int row,int)
{
//    netConfigDialog *dialog = new netConfigDialog(this);
//    if (dialog == NULL)
//        return;
//    dialog->paramsFromScanResults(m_tabScanResult->m_netWorks[row]);
//    dialog->show();
//    dialog->exec();
}

const bool console_run(const char *cmdline) {
    DEBUG_INFO("cmdline = %s\n",cmdline);

#if 0
    FILE *fp = popen(cmdline, "r");
    if (!fp) {
        DEBUG_INFO("Running cmdline failed: %s\n", cmdline);
        return false;
    }

    pclose(fp);
#else
    system(cmdline);
#endif

    return true;
}

int get_pid(char *Name) {
    int len;
    char name[20] = {0};
    len = strlen(Name);
    strncpy(name,Name,len);
    name[len] ='\0';
    char cmdresult[256] = {0};
    char cmd[20] = {0};
    FILE *pFile = NULL;
    int  pid = 0;

    sprintf(cmd, "pidof %s", name);
    pFile = popen(cmd, "r");
    if (pFile != NULL)  {
        while (fgets(cmdresult, sizeof(cmdresult), pFile)) {
            pid = atoi(cmdresult);
            DEBUG_INFO("--- %s pid = %d ---\n",name,pid);
            break;
        }
    }
    pclose(pFile);
    return pid;
}

int is_supplicant_running()
{
    int ret;
    ret = get_pid("wpa_supplicant");
    return ret;
}

int creat_supplicant_file()
{
    FILE* fp;
    fp = fopen(WPA_SUPPLICANT_CONF_DIR, "wt+");

    if (fp != 0) {
        fputs("ctrl_interface=/var/run/wpa_supplicant\n", fp);
        fputs("ap_scan=1\n", fp);
        fclose(fp);
        return 0;
    }
    return -1;
}

int wifi_start_supplicant()
{
    int count = 200;
    //if (access(WPA_SUPPLICANT_CONF_DIR, F_OK) < 0) {
    //    creat_supplicant_file();
    //usleep(2000000);
    //}
    if (is_supplicant_running()) {
        return 0;
    }

    console_run("/usr/sbin/wpa_supplicant -Dnl80211 -iwlan0 -c /tmp/wpa_supplicant.conf -B");
    /*
    while (count-- > 0) {
        if (is_supplicant_running()){
            usleep(2000000);
            return 0;
        }
        usleep(100000);
    }
*/

    return 0;
}

int wifi_stop_supplicant()
{
//    int count = 50; /* wait at most 5 seconds for completion */
//    int pid;
//    char *cmd = NULL;

//    /* Check whether supplicant already stopped */
//    if (!is_supplicant_running()) {
//        return 0;
//    }

//    //    while (count-- > 0) {
//    //stop wpa_supplicant here
//    pid = get_pid("wpa_supplicant");
//    asprintf(&cmd, "kill %d", pid);
//    console_run(cmd);
//    free(cmd);
//    //      if (!is_supplicant_running())
//    //          return 0;
//    //      usleep(100000);
//    //   }
//    //   DEBUG_ERR("Failed to stop supplicant");
//    //    return -1;*/
    return 0;
}

void rightStackedWidgets0::wifiOn()
{
    myNetThread *thread = new myNetThread;
    thread->start();
    m_netManager->openCtrlConnection("wlan0");
}

void rightStackedWidgets0::wifiOff()
{
    wifi_stop_supplicant();
    m_tabScanResult->clearTable();
}

void myNetThread::run()
{
    wifi_start_supplicant();
}

void rightStackedWidgets0::slot_onToggled(bool isChecked)
{
    if(isChecked){
        qDebug("=======wifiOn========\n");
        wifiOn();
    }else{
        qDebug("=======wifiOff========\n");
        wifiOff();
    }

}

switchWidget::switchWidget(QWidget *parent):baseWidget(parent)
{
    QHBoxLayout *mainlyout = new QHBoxLayout;

    m_lblState = new QLabel(this);
    m_lblState->setFont(QFont("Microsoft YaHei",11,QFont::Normal));
    m_lblState->setText("Wlan Swicth:");

    m_btnSwitch = new switchButton(this);
    m_btnSwitch->setFixedSize(40,20);

    mainlyout->addWidget(m_lblState);
    mainlyout->addWidget(m_btnSwitch);
    mainlyout->setContentsMargins(0,0,0,0);
    mainlyout->setSpacing(0);

    setLayout(mainlyout);
}

// tabWidget中current status布局的初始化
tabCurrentStatus::tabCurrentStatus(QWidget *parent):baseWidget(parent)
{
    QVBoxLayout *vmainlyout = new QVBoxLayout;

    // lyout1_Status
    QHBoxLayout *lyout1 = new QHBoxLayout;
    QLabel *statusLabel = new QLabel(this);
    statusLabel->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    statusLabel->setText("Status:");

    textStatus = new QLabel(this);
    textStatus->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    textStatus->setText(QString("connected"));
    lyout1->addWidget(statusLabel,1);
    lyout1->addWidget(textStatus,2);

    //lyout2_Last Message
    QHBoxLayout *lyout2 = new QHBoxLayout;
    QLabel *lastMessageLabel = new QLabel(this);
    lastMessageLabel->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    lastMessageLabel->setText("Last message:");

    textLastMsg = new QLabel(this);
    textLastMsg->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    textLastMsg->setText(QString());
    lyout2->addWidget(lastMessageLabel,1);
    lyout2->addWidget(textLastMsg,2);

    // lyou3_Authenticant
    QHBoxLayout *lyout3 = new QHBoxLayout;
    QLabel *authenticationLabel = new QLabel(this);
    authenticationLabel->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    authenticationLabel->setText("Authentication:");

    textAuthentication = new QLabel(this);
    textAuthentication->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    textAuthentication->setText(QString("None"));
    lyout3->addWidget(authenticationLabel,1);
    lyout3->addWidget(textAuthentication,2);

    //lyout4_Encryption
    QHBoxLayout *lyout4 = new QHBoxLayout;
    QLabel *encryptionLabel = new QLabel(this);
    encryptionLabel->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    encryptionLabel->setText("EncryptionLabel:");

    textEncryption = new QLabel(this);
    textEncryption->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    textEncryption->setText(QString("None"));
    lyout4->addWidget(encryptionLabel,1);
    lyout4->addWidget(textEncryption,2);

    //lyout5_SSID
    QHBoxLayout *lyout5 = new QHBoxLayout;
    QLabel *ssidLabel = new QLabel(this);
    ssidLabel->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    ssidLabel->setText("SSID:");

    textSSID = new QLabel(this);
    textSSID->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    textSSID->setText(QString("None"));
    lyout5->addWidget(ssidLabel,1);
    lyout5->addWidget(textSSID,2);


    //lyout6_BSSID
    QHBoxLayout *lyout6 = new QHBoxLayout;
    QLabel *bssidLabel = new QLabel(this);
    bssidLabel->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    bssidLabel->setText("BSSID:");

    textBSSID = new QLabel(this);
    textBSSID->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    textBSSID->setText(QString("None"));
    lyout6->addWidget(bssidLabel,1);
    lyout6->addWidget(textBSSID,2);

    //lyout7_IP address
    QHBoxLayout *lyout7 = new QHBoxLayout;
    QLabel *ipAddressLabel = new QLabel(this);
    ipAddressLabel->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    ipAddressLabel->setText("IP Address:");

    textIPAddress = new QLabel(this);
    textIPAddress->setFont(QFont("Microsoft YaHei",10,QFont::Normal));
    textIPAddress->setText(QString("None"));
    lyout7->addWidget(ipAddressLabel,1);
    lyout7->addWidget(textIPAddress,2);

    //lyout8 connect and disconnect button
    QHBoxLayout *lyout8 = new QHBoxLayout;
    connectButton = new QPushButton("Connect",this);
    connectButton->setStyleSheet("QPushButton{background:rgb(85,92,108)}"
                                 "QPushButton{color:white}"
                                 "QPushButton{border-radius:5px}");
    connectButton->setFixedSize(90,30);
    disconnectButton = new QPushButton("Disconnect",this);
    disconnectButton->setStyleSheet("QPushButton{background:rgb(85,92,108)}"
                                    "QPushButton{color:white}"
                                    "QPushButton{border-radius:5px}");
    disconnectButton->setFixedSize(90,30);
    lyout8->addStretch(0);
    lyout8->addWidget(connectButton);
    lyout8->addSpacing(30);
    lyout8->addWidget(disconnectButton);
    lyout8->addStretch(0);

    vmainlyout->addLayout(lyout1);
    vmainlyout->addLayout(lyout2);
    vmainlyout->addLayout(lyout3);
    vmainlyout->addLayout(lyout4);
    vmainlyout->addLayout(lyout5);
    vmainlyout->addLayout(lyout6);
    vmainlyout->addLayout(lyout7);
    vmainlyout->addSpacing(40);
    vmainlyout->addLayout(lyout8);
    vmainlyout->addStretch(0);
    vmainlyout->setContentsMargins(10,10,10,10);

    setLayout(vmainlyout);
}

// tabWigdet中Scan Result布局的初始化
tabScanResult::tabScanResult(QWidget *parent):baseWidget(parent)
{
    QVBoxLayout *vmainlyout = new QVBoxLayout;

    // lyout1
    QLabel *tipLabel = new QLabel("the scan result:",this);
    tipLabel->setFont(QFont("Microsoft YaHei",12,QFont::Normal));

    // lyout2
    m_table = new wlanListTable(this);

    // lyout3
    QHBoxLayout *lyout1 = new QHBoxLayout;
    scanButton = new QPushButton("reScan",this);
    scanButton->setStyleSheet("QPushButton{background:rgb(85,92,108)}"
                              "QPushButton{color:white}"
                              "QPushButton{border-radius:5px}");
    scanButton->setFixedSize(70,28);

    lyout1->addStretch(0);
    lyout1->addWidget(scanButton);
    lyout1->addStretch(0);

    vmainlyout->addWidget(tipLabel);
    vmainlyout->addWidget(m_table);
    vmainlyout->addSpacing(15);
    vmainlyout->addLayout(lyout1);
    vmainlyout->setContentsMargins(20,10,20,20);
    vmainlyout->setSpacing(5);
    setLayout(vmainlyout);
}

void tabScanResult::clearTable()
{
    int iLen = m_table->rowCount();
    for(int i=0;i<iLen;i++)
    {
        m_table->removeRow(0);
    }
    m_table->clear();
}

void tabScanResult::insertIntoTable(QString ssid, QString bssid, QString siganl, QString flags)
{
    int rowCount = m_table->rowCount();
    m_table->insertRow(rowCount);
    // 设置Wifi等级图标
    int siganlValue = siganl.toInt();
    QLabel *label = new QLabel("");
    if(siganlValue>=(-55)){
        label->setPixmap(QPixmap(":/image/setting/ic_wifi_signal_4_dark.png").scaled(25,25));
    }else if(siganlValue>=(-70)){
        label->setPixmap(QPixmap(":/image/setting/ic_wifi_signal_3_dark.png").scaled(25,25));
    }else if(siganlValue>=(-85)){
        label->setPixmap(QPixmap(":/image/setting/ic_wifi_signal_2_dark.png").scaled(25,25));
    }else{
        label->setPixmap(QPixmap(":/image/setting/ic_wifi_signal_1_dark.png").scaled(25,25));
    }
    QTableWidgetItem *siganlItem = new QTableWidgetItem();
    siganlItem->setData(Qt::DisplayRole,siganlValue); // 排序
    m_table->setItem(rowCount,2,siganlItem);
    m_table->setCellWidget(rowCount,2,label);


    // 设置安全性图标
    QString auth;
    if (flags.indexOf("[WPA2-EAP") >= 0)
        auth = "WPA2_EAP";
    else if (flags.indexOf("[WPA-EAP") >= 0)
        auth = "WPA_EAP";
    else if (flags.indexOf("[WPA2-PSK") >= 0)
        auth = "WPA2_PSK";
    else if (flags.indexOf("[WPA-PSK") >= 0)
        auth = "WPA_PSK";
    else
        auth = "OPEN";

    if(auth.compare("OPEN")==0)
    {
        m_table->setItem(rowCount,3,new QTableWidgetItem(QIcon(":/image/setting/ic_wifi_unlocked.png"),auth));
    }else{
        m_table->setItem(rowCount,3,new QTableWidgetItem(QIcon(":/image/setting/ic_wifi_locked.png"),auth));
    }

    m_table->setItem(rowCount,0,new QTableWidgetItem(ssid));
    m_table->setItem(rowCount,1,new QTableWidgetItem(bssid));
    m_table->item(rowCount,0)->setTextAlignment(Qt::AlignVCenter|Qt::AlignLeft);
    m_table->item(rowCount,1)->setTextAlignment(Qt::AlignVCenter|Qt::AlignLeft);
    // 数据存入结构体数组中
    m_netWorks[rowCount].SSID = ssid;
    m_netWorks[rowCount].BSSID = bssid;
    m_netWorks[rowCount].signal = siganl;
    m_netWorks[rowCount].flags = flags;

    m_table->sortByColumn(2);
}


