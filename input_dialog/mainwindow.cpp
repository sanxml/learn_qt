#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]字符串输入按钮
    inputStringButton = new QPushButton(this);
    //设置按钮位置
    inputStringButton->setGeometry(QRect(50,200,80,25));
    //设置按钮显示文字
    inputStringButton->setText("input string");

    // [2]整数输入按钮
    inputIntButton = new QPushButton(this);
    //设置按钮位置
    inputIntButton->setGeometry(QRect(150,200,80,25));
    //设置按钮显示文字
    inputIntButton->setText("input int");

    // [3]浮点数输入按钮
    inputFloatButton = new QPushButton(this);
    //设置按钮位置
    inputFloatButton->setGeometry(QRect(50,250,80,25));
    //设置按钮显示文字
    inputFloatButton->setText("input float");

    // [4]列表输入按钮
    inputItemButton = new QPushButton(this);
    //设置按钮位置
    inputItemButton->setGeometry(QRect(150,250,80,25));
    //设置按钮显示文字
    inputItemButton->setText("input item");

    // 输入行文本框
    inputLineEdit = new QLineEdit(this);
    //行文本框的位置
    inputLineEdit->setGeometry(QRect(50,300,180,25));

    //给按钮绑定响应事件
    connect(inputStringButton,SIGNAL(clicked()),this,SLOT(inputString()));
    connect(inputIntButton,SIGNAL(clicked()),this,SLOT(inputInt()));
    connect(inputFloatButton,SIGNAL(clicked()),this,SLOT(inputFloat()));
    connect(inputItemButton,SIGNAL(clicked()),this,SLOT(inputItem()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [1]字符串输入
void MainWindow::inputString(){
    bool ok=false;
    QString string = QInputDialog::getText(this,"input string dialog",
                                           "please input file name",QLineEdit::Normal,"admin",&ok);

    if (ok && !string.isEmpty()){
        inputLineEdit->setText(string);
    }
}

// [2]整数输入
void MainWindow::inputInt(){
    bool ok=false;
    int intValue = QInputDialog::getInt(this,"input int dialog","please input a number of -100~100 ",
                                        100,-100,100,10,&ok);

    if (ok){
        inputLineEdit->setText(QString::number(intValue));  // 整型数据转换成字符串显示
    }
}

// [3]浮点数输入
void MainWindow::inputFloat(){
    bool ok=false;
    float floatValue = QInputDialog::getDouble(this,"inpt float dialog","input a number of -100~100",
                                               0.00,-100,100,2,&ok);
    if (ok){
        inputLineEdit->setText(QString::number(floatValue));
    }
}

// [4]列表输入
void MainWindow::inputItem(){
    // 定义项目列表
    QStringList items;
    items <<"item1" <<"item2" <<"item3";
    bool ok=false;
    QString item = QInputDialog::getItem(this,"input item dialog","please select a item",
                                         items,0,true,&ok);
    if (ok && !item.isEmpty()){
        inputLineEdit->setText(item);
    }
}