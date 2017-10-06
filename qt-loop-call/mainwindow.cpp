#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,MainWindow::stateFunction); //link
    timer->start(1000);

    //state machine
    fsm = new QStateMachine(this);
    QState* s1 = new QState();
    QState* s2 = new QState();
    s1->addTransition(timer,SIGNAL(timeout()),s2);
    s1->setObjectName(tr("S1"));
    connect(s1,SIGNAL(entered()),this,SLOT(showMessage()));

    s2->addTransition(timer,SIGNAL(timeout()),s1);
    s2->setObjectName(tr("S2"));
    connect(s2,SIGNAL(entered()),this,SLOT(showMessage()));

    fsm->addState(s1);
    fsm->addState(s2);
    fsm->setInitialState(s1);
    fsm->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::stateFunction()
{
    ui->statusBar->showMessage(tr("current state:%1").arg(state));
    state+=1;
    if (state>=INT_MAX)
        state =0;//reset
    return 0;
}

MainWindow::showMessage()
{
    ui->statusBar->showMessage(tr("current state%1").arg(sender()->objectName()));
}
