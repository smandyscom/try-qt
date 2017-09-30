#include "mainwindow.h"
#include "ui_mainwindow.h"

enum myEnum : int{
    A=0,
    B,
    C,
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //wrong , unable to add widget
    this->tableWidget = this->findChild<QTableWidget*>("tableWidget");
    this->tableWidget->setItem(0,0,new QTableWidgetItem(tr("%1").arg(pow(3,2)))); //add a te
    this->tableWidget->setItem(0,1,new QTableWidgetItem(QTableWidgetItem::UserType));

    //corrected , layout widgets in some form
    this->vboxLayout = this->findChild<QVBoxLayout*>("verticalLayout");
    for(int i=0;i<10;i++)
    {
        this->vboxLayout->addWidget(new QPushButton(tr("&Cancel%1").arg(i),this));
    }

    //adding customed widgets
    this->vboxLayout2 = this->findChild<QVBoxLayout*>("verticalLayout_2");
    for(int i=0;i<10;i++)
    {
        this->vboxLayout2->addWidget(new myWidget(this));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
