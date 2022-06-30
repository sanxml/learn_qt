#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建一个标签
    label = new QLabel(this);
    // 设置标签显示的文字
    label->setText("hello world");
    // 设置标签在界面的位置和大小
    label->setGeometry(QRect(50,50,100,25));
}

MainWindow::~MainWindow()
{
    delete ui;
}
