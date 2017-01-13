#include "mainwindow.h"
#include<QDesktopWidget>
#include "singleApplication/qsingleapplication.h"

int main(int argc, char *argv[])
{
    QSingleApplication app(argc, argv); // 单例模式
    if(!app.isRunning())
    {
        mainWindow w;
        app.w=&w;
        // w.setGeometry(100,100,1000,700);
        // w.show();
        w.showMaximized();
        return app.exec();
    }
    return 0;
}
