#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStateMachine>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QTimer* timer;

    int state =0;
    int stateFunction();

    QStateMachine* fsm;

    public slots:

    int showMessage();
};

#endif // MAINWINDOW_H
