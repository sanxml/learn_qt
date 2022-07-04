#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 实例化文本框
    textEdit = new QTextEdit(this);
    // 设置文本框的位置和大小
    textEdit->setGeometry(50,50,300,200);

    // 实例化QFile，并指定文件名
    QFile file("/home/geo/Desktop/learn_qt/file_io/test.txt");
    // 以只读的方式打开文件，如果打开文件出现错误，程序退出
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    // 创建文本流对象，用于向文件写操作
    QTextStream out(&file);
    // 写字符串
    out <<"this is line1. " << "write and read text file." << endl
        <<"this is line2. " << "hello text file." << endl
        <<"this is line3. " << "hello world." << endl ;
    // 注意此时文件的光标位置在文件末尾

    // 创建文本流对象，用于读取文件内容
    QTextStream in(&file);
    // 创建一个变量，接收从文件读取的内容
    QString readString;
    // 移动光标到文件开头，否则读不到文件内容
    in.seek(0);
    // 读取文件内容
    // 读取文件内容，直到全部内容读出
    while (!in.atEnd()) {
        readString = in.readLine();
        // 将读取的每一个数据显示在文本框上
        textEdit->insertPlainText(readString + '\n');
    }

    // 文件操作结束后，关闭文件
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
