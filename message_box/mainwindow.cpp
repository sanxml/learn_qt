#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [5]字符串输入按钮
    informationButton = new QPushButton(this);
    //设置按钮位置
    informationButton->setGeometry(QRect(280,200,80,25));
    //设置按钮显示文字
    informationButton->setText("information");

    // [6]整数输入按钮
    warningButton = new QPushButton(this);
    //设置按钮位置
    warningButton->setGeometry(QRect(380,200,80,25));
    //设置按钮显示文字
    warningButton->setText("warning");

    // [7]浮点数输入按钮
    criticalButton = new QPushButton(this);
    //设置按钮位置
    criticalButton->setGeometry(QRect(280,250,80,25));
    //设置按钮显示文字
    criticalButton->setText("critical");

    // [8]列表输入按钮
    aboutButton = new QPushButton(this);
    //设置按钮位置
    aboutButton->setGeometry(QRect(380,250,80,25));
    //设置按钮显示文字
    aboutButton->setText("about");

   //给按钮绑定响应事件
    connect(informationButton,SIGNAL(clicked()),this,SLOT(informationMessage()));
    connect(warningButton,SIGNAL(clicked()),this,SLOT(warningMessage()));
    connect(criticalButton,SIGNAL(clicked()),this,SLOT(ctrticalMessage()));
    connect(aboutButton,SIGNAL(clicked()),this,SLOT(aboutMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [5]消息提示
void MainWindow::informationMessage(){
    QMessageBox::information(this, "information message box", "this is a test program",
                                  QMessageBox::Ok,QMessageBox::NoButton);
}

// [6]警告信息
void MainWindow::warningMessage(){
    QMessageBox::warning(this, "warning message box", "this is a test program");
}

// [7]错误信息
void MainWindow::ctrticalMessage(){
    QMessageBox::critical(this, "critical message box", "this is a test program");
}

// [8]关于信息
void MainWindow::aboutMessage(){
    QMessageBox::about(this, "about message box", "this is a Qt program");
}