#include "mainwindow.h"
#include<QDesktopWidget>
#include "singleApplication/qsingleapplication.h"

int main(int argc, char *argv[])
{
    QSingleApplication app(argc, argv); // 单例模式
    if(!app.isRunning())
    {
        app.setStyleSheet("QMenu{background-color: white;border: 1px solid rgb(214,214,214);}"
                          "QMenu::item{height: 28px;padding: 0px 20px 0px 40px;font-size : 12px;color: rgb(102, 102, 102);font-family: 微软雅黑;}"
                          "QMenu::item:focus{padding: -1;}"
                          "QMenu::item:!enabled{color:rgb(150,150,150);}"
                          "QMenu::item:selected{color: white;background-color: rgb(22, 154, 243);}"
                          "QMenu::icon{position: absolute;left: 12px;}"
                          "QMenu::separator{height:1px;background: rgb(209,209,209);margin:4px 0px 4px 0px;}"
                          "QPushButton:focus{padding: -1;}"
                          "QLabel:focus{padding: -1;}");
        mainWindow w;
        app.w=&w;
        //        w.setGeometry(100,100,1000,700);
        //        w.show();
        w.showMaximized();
        return app.exec();
    }
    return 0;
}
