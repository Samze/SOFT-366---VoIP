#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup two threads for sending and receiving audio data
    recThread = new ReceiveThread(this);
    sendThread = new SendThread(this);

    //setup start connections
    connect(ui->btnCapture,SIGNAL(clicked()),sendThread,SLOT(recordSound()));
    connect(ui->btnCapture,SIGNAL(clicked()),recThread,SLOT(listen()));

    //setup stop connections
    connect(ui->btnStopCapture,SIGNAL(clicked()),sendThread,SLOT(quit()));
    connect(ui->btnStopCapture,SIGNAL(clicked()),recThread,SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete recThread;
    delete sendThread;
}
