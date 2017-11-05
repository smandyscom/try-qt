#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../try-db/motion_paramters.db"); // set path only , no server served
    bool isOK = db.open();

    QSqlQuery qe;
    bool res = qe.exec("SELECT * FROM AXIS_POOL");
    qe.next();
    QVariant vv = qe.value(0);
    QString v = qe.lastError().text(); // done
    return 0;
}
