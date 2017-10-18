#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QItemSelection>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
private slots:
    void on_tableView_activated(const QModelIndex &index);
    void refresh_status_bar();
    void selectionChanged_handler(QItemSelection newone,QItemSelection oldone);
private:
    Ui::MainWindow *ui;
    QAbstractItemModel* model;

};

#endif // MAINWINDOW_H
