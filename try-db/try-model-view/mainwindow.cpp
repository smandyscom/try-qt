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
     model = new QStringListModel(qsl);

     //0. open connection
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // driver selection
     db.setHostName("../");
     bool isOk = db.open();
     //sql table
     model = new QSqlTableModel(this);
     QSqlTableModel* sq = static_cast<QSqlTableModel*>(model);


    //ui->statusBar->showMessage(variant.toString());
    //ui->statusBar->showMessage(model->data(index,Qt::DisplayRole).toString());

    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),this,SLOT(refresh_status_bar())); //raise event when data in model changed

    ui->tableView->setModel(model);

    ui->tableView->setItemDelegate(new customdelegate(this));
    //ui->tableView->selectionModel()->select(null, QItemSelectionModel::Current);
    QItemSelectionModel* ism = ui->tableView->selectionModel();

    connect(ism,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(selectionChanged_handler(QItemSelection,QItemSelection))); // selection practice
    connect(ism,SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(currentChanged_handler(QModelIndex,QModelIndex))); //current selection practice
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh_status_bar()
{
    QModelIndex index = model->index(0,0);
    QVariant variant;
    variant = model->data(index,Qt::DisplayRole);//assignment

    ui->statusBar->showMessage(variant.toString());
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::selectionChanged_handler(QItemSelection newone, QItemSelection oldone)
{
    QVariant __var;
    //show up which one selected
    if (newone.indexes().count()!=0)
        __var = model->data(newone.indexes().first(),Qt::DisplayRole);

    ui->statusBar->showMessage(tr("%1 items selected, 1st is %2").arg(QString::number(newone.indexes().count()),__var.toString()));
}
void MainWindow::currentChanged_handler(QModelIndex newone, QModelIndex oldone)
{
    //no multiple selection
    //show up which one selected
    QVariant __var = newone.model()->data(newone,Qt::DisplayRole);
    ui->textBrowser->setText(tr("%1 current selected").arg(__var.toString()));
}
