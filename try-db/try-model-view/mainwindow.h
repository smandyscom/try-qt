#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QItemSelection>
#include <QModelIndex>

#include <QStyledItemDelegate>
#include <QWidget>
#include <QSqlRelationalTableModel>


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
    void currentChanged_handler(QModelIndex newone,QModelIndex oldone);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QAbstractItemModel* model1;
    QSqlRelationalTableModel* model2;
};


#endif // MAINWINDOW_H
