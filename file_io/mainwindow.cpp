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
    textEdit->setGeometry(50,50,700,500);

    // 实例化QFile，并指定文件名
    QFile file("/home/geo/Desktop/learn_qt/file_io/test.txt");
    // 以只读的方式打开文件，如果打开文件出现错误，程序退出
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // 读取文件内容，直到全部内容读出
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        // 将读取的每一个数据显示在文本框上
        textEdit->insertPlainText(line);
    }

    // 文件操作结束后，关闭文件
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
