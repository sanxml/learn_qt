#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建按钮
    fontbutton = new QPushButton(this);
    //设置按钮位置
    fontbutton->setGeometry(QRect(50,150,80,25));
    //设置按钮显示文字
    fontbutton->setText("font change");

    //给按钮绑定响应事件
    connect(fontbutton,SIGNAL(clicked()),this,SLOT(fontSelect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fontSelect()
{
    // ok用于标记是否单击了OK按钮
    bool ok = false;
    // 获取按钮文字的字体
    QFont initFont = fontbutton->font();
    // 选择字体
    QFont font=QFontDialog::getFont(&ok,initFont);
    // 如果点击OK按钮，则文字设置为选择的字体
    if (ok) {
        fontbutton->setFont(font);
    }
}