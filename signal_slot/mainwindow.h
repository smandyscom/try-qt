#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>


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
    void on_textBrowser_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_clicked(bool checked);

    void on_pushButton_pressed();

    void on_pushButton_toggled(bool checked);

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    QTextBrowser* textBrowser;

};

#endif // MAINWINDOW_H
