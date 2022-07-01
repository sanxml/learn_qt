#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pushbutton = new QPushButton(this);             // ��ťʵ����
    pushbutton->setText("show message");            // ���ð�ť������ʾ������
    pushbutton->setGeometry(QRect(50,50,100,25));   // ���ð�ťλ��

    lineEdit = new QLineEdit(this);                 // �ı���ʵ����
    lineEdit->setGeometry(QRect(200,50,200,25));    // �����ı���λ��

    // QPushButton ��clickd()�ź��������Զ�����źŰ󶨣�ֻ��Ϊ����ʾ�ź����źŵİ�
    // ʵ��ʹ��ʱ����ֱ�ӽ�clicked()�ź��������Զ��Ĳ۰�
    connect(pushbutton,SIGNAL(clicked()),this,SIGNAL(signalShowText()));
    // �Զ����ź���۰�
    connect(this,SIGNAL(signalShowText()),this,SLOT(showText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText()
{
    lineEdit->setText("Push button is clicked");
}

