#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]创建一个标签
    scrollArealabel = new QLabel;
    // 设置标签的最小尺寸，非常重要，否则有可能无法正常显示滚动条
    scrollArealabel->setMinimumSize(500,500);
    // 设置标签显示的内容，随便写点东西
    scrollArealabel->setText("The scroll bars appearance depends on the currently set scroll bar policies. ");

    // [2]创建滚动区域
    QScrollArea *scrollArea = new QScrollArea;
    // 把标签加到滚动区域，使用 setWidget() 函数
    scrollArea->setWidget(scrollArealabel);
    // 设置滚动区域的背景色
    scrollArea->setBackgroundRole(QPalette::Dark);

    // [3]创建一个布局
    QHBoxLayout *hlayout = new QHBoxLayout;
    // 把滚动区域加到布局上
    hlayout->addWidget(scrollArea);
    // 使布局生效
    QWidget* widget = new QWidget(this);
    widget->setLayout(hlayout);
    this->setCentralWidget(widget);
    // 设置窗口的大小，比标签的最小尺寸小，这样能显示滚动区域
    this->setFixedSize(400,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}
