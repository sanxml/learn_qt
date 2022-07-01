#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]创建一个中心区域显示的文本框
    textEdit = new QTextEdit;
    textEdit->setText("main widget");
    // 设置文本框的大小
    textEdit->setFixedSize(300,300);
    // 把文本框设置为程序中心窗口
    this->setCentralWidget(textEdit);
    // 设置组件与程序边框的距离
    this->setContentsMargins(15,15,15,15);
    //　设置程序界面大小
    this->setFixedSize(450,330);

    // [2]创建组件
    label = new QLabel;
    label->setText("widget1");
    button1 = new QPushButton("aboutQt");
    button2 = new QPushButton("button2");
    button3 = new QPushButton("close");
    // 给两个按钮绑定槽，实现简单的功能
    connect(button1,SIGNAL(clicked()),qApp,SLOT(aboutQt()));// 关于QT
    connect(button3,SIGNAL(clicked()),this,SLOT(close()));  // 关闭程序

    // [3]创建页面布局,用于标签和按钮的布局
    QVBoxLayout *docklayout_1 = new QVBoxLayout;
    // 向布局添加组件
    docklayout_1->addWidget(label);
    docklayout_1->addStretch();
    docklayout_1->addWidget(button1);
    QVBoxLayout *docklayout_2 = new QVBoxLayout;
    // 向布局添加组件
    docklayout_2->addStretch();
    docklayout_2->addWidget(button2);
    docklayout_2->addWidget(button3);

    // [4]创建窗口组件
    QWidget *widget1 = new QWidget;
    QWidget *widget2 = new QWidget;

    // [5]设置窗口组件的布局
    widget1->setLayout(docklayout_1);
    widget2->setLayout(docklayout_2);

    // [6]创建停靠窗口，并把上面两个窗口添加到停靠窗口中
    QDockWidget *dock = new QDockWidget(tr("myDockWindow"), this);
    // 设置停靠区域
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // 设置停靠窗口的属性
    dock->setFeatures(QDockWidget::DockWidgetMovable); //停靠窗口可移动属性
    // 窗口 widget1 设置为停靠窗口
    dock->setWidget(widget1);
    // 设置停靠窗口的大小
    dock->setFixedSize(100,100);
    // 设置边框颜色
    dock->setStyleSheet((QString::fromUtf8("border:1px solid gray")));
    // 向程序主界面添加停靠窗口
    this->addDockWidget(Qt::RightDockWidgetArea,dock);

    QDockWidget *dock1 = new QDockWidget(tr("myDockWindow"), this);
    // 设置停靠区域
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // 设置停靠窗口的属性
    dock1->setFeatures(QDockWidget::AllDockWidgetFeatures); //具有停靠窗口的全部特性
    // 窗口 widget2 设置为停靠窗口
    dock1->setWidget(widget2);
    // 设置停靠窗口的大小
    dock1->setFixedSize(100,200);
    // 设置边框颜色
    dock1->setStyleSheet((QString::fromUtf8("border:1px solid gray")));
    // 向程序主界面添加停靠窗口
    this->addDockWidget(Qt::RightDockWidgetArea,dock1);

    // [7]设置两个停靠窗口的位置，垂直排列
    splitDockWidget(dock,dock1,Qt::Vertical);
}

MainWindow::~MainWindow()
{
    delete ui;
}
