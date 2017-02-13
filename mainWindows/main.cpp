#include "mainwindow.h"
#include <QDesktopWidget>
#include "singleApplication/qsingleapplication.h"
#include <mainWindows/global_value.h>
#include <global_value.h>

int main(int argc, char *argv[])
{
    QSingleApplication app(argc, argv);
    if(!app.isRunning())    /* application run in single mode */
    {
        app.setStyleSheet("QLabel{color:white;}"
                          "QScrollBar{background:transparent; width: 10px;margin: 0px 2px 0px 0px;}"
                          "QScrollBar::handle{background:rgb(217,217,217);border-radius:4px;}"
                          "QScrollBar::handle:hover{background: rgb(191,191,191);}"
                          "QScrollBar::add-line:vertical{border:1px rgb(230,230,230);height: 1px;}"
                          "QScrollBar::sub-line:vertical{border:1px rgb(230,230,230);height: 1px;}"
                          "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:transparent;}");
        // change app font family and size to supprot all device
        QFont appFont = app.font();
        appFont.setFamily("Microsoft YaHei");
        appFont.setPixelSize(font_size);
        app.setFont(appFont);

        mainWindow w;
        app.w=&w;

        //w.setGeometry(100,100,1000,700);
        //w.show();
        w.showMaximized();
        return app.exec();
    }
    return 0;
}
