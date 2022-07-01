#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pushbutton = new QPushButton(this);             // 按钮实例化
    pushbutton->setText("show message");            // 设置按钮上面显示的文字
    pushbutton->setGeometry(QRect(50,50,100,25));   // 设置按钮位置

    lineEdit = new QLineEdit(this);                 // 文本框实例化
    lineEdit->setGeometry(QRect(200,50,200,25));    // 设置文本框位置

    // QPushButton 的clickd()信号与我们自定义的信号绑定，只是为了演示信号与信号的绑定
    // 实际使用时可以直接将clicked()信号与我们自定的槽绑定
    connect(pushbutton,SIGNAL(clicked()),this,SIGNAL(signalShowText()));
    // 自定义信号与槽绑定
    connect(this,SIGNAL(signalShowText()),this,SLOT(showText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText()
{
    lineEdit->setText("Push button is clicked");
}

