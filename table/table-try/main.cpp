#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //ENABLE virtual keyboard module
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    data_cell dc;

    dc.title = "TITLE";
    dc.field1 = INT16_MAX;

    int __size = sizeof(dc);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
