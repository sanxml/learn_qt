#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ����һ����ǩ
    label = new QLabel(this);
    // ���ñ�ǩ��ʾ������
    label->setText("hello world");
    // ���ñ�ǩ�ڽ����λ�úʹ�С
    label->setGeometry(QRect(50,50,100,25));
}

MainWindow::~MainWindow()
{
    delete ui;
}
