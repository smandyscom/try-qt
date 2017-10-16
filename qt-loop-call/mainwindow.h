#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStateMachine>
#include <QModbusServer>

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
    QModbusServer* modbusdevice;

    public slots:

    int showMessage();

    int modbusSlaveInit();//initializing procedure of modbus slave
};

#endif // MAINWINDOW_H
