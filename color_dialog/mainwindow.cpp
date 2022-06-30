#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建按钮
    QPushButton *button = new QPushButton(this);
    //设置按钮位置
    button->setGeometry(QRect(50,50,100,25));
    //设置按钮显示文字
    button->setText("change color");

    //创建标签
    QLabel *label = new QLabel(this);
    //label 位置
    label->setGeometry(QRect(170,50,220,25));
    //label 值
    label->setText("the test of text color change");

    //给按钮绑定响应事件
    connect(button,SIGNAL(clicked()),this,SLOT(editText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editText()
{

    // 获取当前label的颜色
    QPalette pal = label->palette();
    QColor initColor = pal.color(QPalette::WindowText);
    // 设置颜色对话框
    QColor color = QColorDialog::getColor(initColor,this,"select color");
    // 判断颜色选择有效性
    if (color.isValid()) {
        pal.setColor(QPalette::WindowText,QColor(color));  //调色板接收颜色
        label->setPalette(pal); //给label 绑定颜色
    }

}