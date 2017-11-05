#include "mainwindow.h"
#include <QApplication>

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
