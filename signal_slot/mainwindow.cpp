#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->textBrowser =  this->findChild<QTextBrowser*>("textBrowser");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textBrowser_textChanged()
{

}

void MainWindow::on_pushButton_clicked()
{
//   QWidget* __w =  this->centralWidget();
//   QTextBrowser* __o =  __w->findChild<QTextBrowser*>("textBrowser");
  // __o->setText("Push Button Clicked");
}

void MainWindow::on_pushButton_clicked(bool checked)
{
//    QWidget* __w =  this->centralWidget();
//    QTextBrowser* __o =  __w->findChild<QTextBrowser*>("textBrowser");
//    if (checked)
//        __o->setText("Push Button Clicked");
//    else
//        __o->setText("Push Button Unclicked");
}

void MainWindow::on_pushButton_pressed()
{
    this->textBrowser->setText("Pressed");

}

void MainWindow::on_pushButton_toggled(bool checked)
{

}

void MainWindow::on_pushButton_released()
{
    this->textBrowser->setText("Released");

}
