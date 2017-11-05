#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>

#include <QStringListModel>
#include "customdelegate.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList qsl;
    qsl << "First" << "Second" << "Third" << "4" << "5";
     model1 = new QStringListModel(qsl);

     //0. open connection
     //sql table
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("/Users/Apple/Github/try-qt/try-db/motion_paramters.db"); // set path only , no server served
     bool isOK = db.open();

     QSqlQuery qe;
     bool res = qe.exec("SELECT * FROM AXIS_POOL");
     qe.next();
     QVariant vv = qe.value(0);
     QString v = qe.lastError().text(); // done

   model2 = new QSqlRelationalTableModel(this);
     QSqlRelationalTableModel* sq = static_cast<QSqlRelationalTableModel*>(model2);
    QSqlDatabase db2 = sq->database();
    sq->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
     //sq->setTable("AXIS_POOL");

    sq->setTable("PRESET_POSITION_ALL_2");
    isOK= sq->select();

    connect(model2,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),this,SLOT(refresh_status_bar())); //raise event when data in model changed

    ui->tableView->setModel(model2);

    //ui->tableView->setItemDelegate(new customdelegate(this));
    //ui->tableView->selectionModel()->select(null, QItemSelectionModel::Current);
    QItemSelectionModel* ism = ui->tableView->selectionModel();

    //connect(ism,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(selectionChanged_handler(QItemSelection,QItemSelection))); // selection practice
    //connect(ism,SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(currentChanged_handler(QModelIndex,QModelIndex))); //current selection practice
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh_status_bar()
{
    QModelIndex index = model1->index(0,0);
    QVariant variant;
    variant = model1->data(index,Qt::DisplayRole);//assignment

    ui->statusBar->showMessage(tr("changed,%1").arg(variant.toString()));
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::selectionChanged_handler(QItemSelection newone, QItemSelection oldone)
{
    QVariant __var;
    //show up which one selected
    if (newone.indexes().count()!=0)
        __var = model1->data(newone.indexes().first(),Qt::DisplayRole);

    ui->statusBar->showMessage(tr("%1 items selected, 1st is %2").arg(QString::number(newone.indexes().count()),__var.toString()));
}
void MainWindow::currentChanged_handler(QModelIndex newone, QModelIndex oldone)
{
    //no multiple selection
    //show up which one selected
    QVariant __var = newone.model()->data(newone,Qt::DisplayRole);
    ui->textBrowser->setText(tr("%1 current selected").arg(__var.toString()));
}

void MainWindow::on_pushButton_clicked()
{
    //submit changes
    bool isOK = model2->database().transaction();
    isOK = model2->submitAll();
    ui->statusBar->showMessage(model2->lastError().text());
    isOK = model2->database().commit();
}
