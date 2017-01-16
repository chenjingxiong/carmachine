#include "mainwindow.h"
#include <QDesktopWidget>
#include "singleApplication/qsingleapplication.h"

int main(int argc, char *argv[])
{
    QSingleApplication app(argc, argv); // 单例模式
    if(!app.isRunning())
    {
        mainWindow w;
        app.w=&w;
        w.showMaximized();
        return app.exec();
    }
    return 0;
}
