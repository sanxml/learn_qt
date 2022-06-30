#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [5]�ַ������밴ť
    informationButton = new QPushButton(this);
    //���ð�ťλ��
    informationButton->setGeometry(QRect(280,200,80,25));
    //���ð�ť��ʾ����
    informationButton->setText("information");

    // [6]�������밴ť
    warningButton = new QPushButton(this);
    //���ð�ťλ��
    warningButton->setGeometry(QRect(380,200,80,25));
    //���ð�ť��ʾ����
    warningButton->setText("warning");

    // [7]���������밴ť
    criticalButton = new QPushButton(this);
    //���ð�ťλ��
    criticalButton->setGeometry(QRect(280,250,80,25));
    //���ð�ť��ʾ����
    criticalButton->setText("critical");

    // [8]�б����밴ť
    aboutButton = new QPushButton(this);
    //���ð�ťλ��
    aboutButton->setGeometry(QRect(380,250,80,25));
    //���ð�ť��ʾ����
    aboutButton->setText("about");

   //����ť����Ӧ�¼�
    connect(informationButton,SIGNAL(clicked()),this,SLOT(informationMessage()));
    connect(warningButton,SIGNAL(clicked()),this,SLOT(warningMessage()));
    connect(criticalButton,SIGNAL(clicked()),this,SLOT(ctrticalMessage()));
    connect(aboutButton,SIGNAL(clicked()),this,SLOT(aboutMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [5]��Ϣ��ʾ
void MainWindow::informationMessage(){
    QMessageBox::information(this, "information message box", "this is a test program",
                                  QMessageBox::Ok,QMessageBox::NoButton);
}

// [6]������Ϣ
void MainWindow::warningMessage(){
    QMessageBox::warning(this, "warning message box", "this is a test program");
}

// [7]������Ϣ
void MainWindow::ctrticalMessage(){
    QMessageBox::critical(this, "critical message box", "this is a test program");
}

// [8]������Ϣ
void MainWindow::aboutMessage(){
    QMessageBox::about(this, "about message box", "this is a Qt program");
}