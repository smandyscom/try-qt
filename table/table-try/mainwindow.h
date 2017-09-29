#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//apt-cache rdepends packagename
// check if somebody had done this , depends on libmodbus
// defined the object view from datas gained from modbus
class modbusRegisterObjectViewBase
{
    //is_auto_update
  int virtual update(); //modbus layer -> object
  int virtual write(); //object -> modbus layer
};

struct data_cell{
    QString title;
    int16_t field1;
    //int16_t* field2; // point to register from modbus layer

};

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
};




#endif // MAINWINDOW_H
