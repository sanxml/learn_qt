#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //�������ı��ؼ�
    filename = new QLineEdit(this);
    //���ı����λ��
    filename->setGeometry(QRect(150,100,200,25));
    //������ť
    filebutton = new QPushButton(this);
    //���ð�ťλ��
    filebutton->setGeometry(QRect(50,100,80,25));
    //���ð�ť��ʾ����
    filebutton->setText("file select");

    //����ť����Ӧ�¼�
    connect(filebutton,SIGNAL(clicked()),this,SLOT(showFiles()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFiles()
{
    //�������str ����QFileDialog �Ի����ȡ���ļ�·��
    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");
    //��������QLineEdit �ؼ�
    if (!str.isEmpty()){
        filename->setText(str.toUtf8());
    }
}