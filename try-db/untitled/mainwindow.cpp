#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QSqlError>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //sql table
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:\\Users\\jlai10\\Github\\try-qt\\try-db\\motion_paramters.db"); // set path only , no server served
        bool isOK = db.open();

        QSqlQuery qy;
        isOK =  qy.exec("CREATE TEMP VIEW IF NOT EXISTS V13 AS SELECT * FROM PRESET_POSITION_SINGLE A LEFT JOIN PRESET_POSITION_ATTR B ON A.BANK_ID = B.BANK_ID LEFT JOIN PRESET_POSITION_TAGS C ON A.BANK_ID = C.BANK_ID; ");
        QString mes = qy.lastError().text();
        isOK = qy.exec("CREATE TRIGGER IF NOT EXISTS T1T INSTEAD OF UPDATE OF COORD ON V13 FOR EACH ROW BEGIN UPDATE PRESET_POSITION_SINGLE SET COORD = NEW.COORD WHERE BANK_ID = NEW.BANK_ID; END;" );
        mes = qy.lastError().text();

        model = new QSqlRelationalTableModel(this);
        model->setTable("V13");
        model->select();

        ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool isOK = model->database().transaction();
        if (!model->submitAll()){
            ui->statusBar->showMessage(model->lastError().text());
            model->database().rollback();
        }
        else{
            isOK = model->database().commit();
        }

}
