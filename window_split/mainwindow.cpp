#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]创建3个文本框
    textEdit1 = new QTextEdit();
    textEdit2 = new QTextEdit();
    textEdit3 = new QTextEdit();
    // [2]创建分离器对象
    QSplitter* splitter = new QSplitter;
    // [3]设置内部组件水平方向布局
    splitter->setOrientation(Qt::Horizontal);
    // [4]向分离器中，添加组件
    splitter->addWidget(textEdit1);
    splitter->addWidget(textEdit2);
    splitter->addWidget(textEdit3);
    /*
     * [5]调整3个分割窗口的显示比例 1：1：2
     * setStretchFactor函数：
     *  第一个参数：窗口索引，从0开始
     *  第二个参数：拉伸比例
     * 第一个窗口索引0，拉伸1
     * 第二个窗口索引1，拉伸1
     * 第三个窗口索引2，拉伸2
    */
    splitter->setStretchFactor(0,1);
    splitter->setStretchFactor(1,1);
    splitter->setStretchFactor(2,2);
    /*
     * [6]把分离器添加到窗口上
     * 创建一个layout
     * 添加组件的方式向layout添加分离器
     * 设置 layout 为程序的layout
    */
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(splitter);
    this->setContentsMargins(5,5,5,5);

    QWidget* widget = new QWidget(this);
    widget->setLayout(hlayout);
    this->setCentralWidget(widget);

    // 设置窗口大小
    this->setFixedSize(800,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
