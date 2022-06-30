#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建行文本控件
    filename = new QLineEdit(this);
    //行文本框的位置
    filename->setGeometry(QRect(150,100,200,25));
    //创建按钮
    filebutton = new QPushButton(this);
    //设置按钮位置
    filebutton->setGeometry(QRect(50,100,80,25));
    //设置按钮显示文字
    filebutton->setText("file select");

    //给按钮绑定响应事件
    connect(filebutton,SIGNAL(clicked()),this,SLOT(showFiles()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFiles()
{
    //定义变量str 接收QFileDialog 对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");
    //将变量绑定QLineEdit 控件
    if (!str.isEmpty()){
        filename->setText(str.toUtf8());
    }
}