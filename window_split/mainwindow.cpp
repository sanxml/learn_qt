#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]����3���ı���
    textEdit1 = new QTextEdit();
    textEdit2 = new QTextEdit();
    textEdit3 = new QTextEdit();
    // [2]��������������
    QSplitter* splitter = new QSplitter;
    // [3]�����ڲ����ˮƽ���򲼾�
    splitter->setOrientation(Qt::Horizontal);
    // [4]��������У�������
    splitter->addWidget(textEdit1);
    splitter->addWidget(textEdit2);
    splitter->addWidget(textEdit3);
    /*
     * [5]����3���ָ�ڵ���ʾ���� 1��1��2
     * setStretchFactor������
     *  ��һ��������������������0��ʼ
     *  �ڶ����������������
     * ��һ����������0������1
     * �ڶ�����������1������1
     * ��������������2������2
    */
    splitter->setStretchFactor(0,1);
    splitter->setStretchFactor(1,1);
    splitter->setStretchFactor(2,2);
    /*
     * [6]�ѷ�������ӵ�������
     * ����һ��layout
     * �������ķ�ʽ��layout��ӷ�����
     * ���� layout Ϊ�����layout
    */
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(splitter);
    this->setContentsMargins(5,5,5,5);

    QWidget* widget = new QWidget(this);
    widget->setLayout(hlayout);
    this->setCentralWidget(widget);

    // ���ô��ڴ�С
    this->setFixedSize(800,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
