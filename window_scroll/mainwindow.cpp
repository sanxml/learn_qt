#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]����һ����ǩ
    scrollArealabel = new QLabel;
    // ���ñ�ǩ����С�ߴ磬�ǳ���Ҫ�������п����޷�������ʾ������
    scrollArealabel->setMinimumSize(500,500);
    // ���ñ�ǩ��ʾ�����ݣ����д�㶫��
    scrollArealabel->setText("The scroll bars appearance depends on the currently set scroll bar policies. ");

    // [2]������������
    QScrollArea *scrollArea = new QScrollArea;
    // �ѱ�ǩ�ӵ���������ʹ�� setWidget() ����
    scrollArea->setWidget(scrollArealabel);
    // ���ù�������ı���ɫ
    scrollArea->setBackgroundRole(QPalette::Dark);

    // [3]����һ������
    QHBoxLayout *hlayout = new QHBoxLayout;
    // �ѹ�������ӵ�������
    hlayout->addWidget(scrollArea);
    // ʹ������Ч
    QWidget* widget = new QWidget(this);
    widget->setLayout(hlayout);
    this->setCentralWidget(widget);
    // ���ô��ڵĴ�С���ȱ�ǩ����С�ߴ�С����������ʾ��������
    this->setFixedSize(400,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}
