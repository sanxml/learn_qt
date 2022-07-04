#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ʵ�����ı���
    textEdit = new QTextEdit(this);
    // �����ı����λ�úʹ�С
    textEdit->setGeometry(50,50,300,200);

    // ʵ����QFile����ָ���ļ���
    QFile file("/home/geo/Desktop/learn_qt/file_io/test.txt");
    // ��ֻ���ķ�ʽ���ļ���������ļ����ִ��󣬳����˳�
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    // �����ı��������������ļ�д����
    QTextStream out(&file);
    // д�ַ���
    out <<"this is line1. " << "write and read text file." << endl
        <<"this is line2. " << "hello text file." << endl
        <<"this is line3. " << "hello world." << endl ;
    // ע���ʱ�ļ��Ĺ��λ�����ļ�ĩβ

    // �����ı����������ڶ�ȡ�ļ�����
    QTextStream in(&file);
    // ����һ�����������մ��ļ���ȡ������
    QString readString;
    // �ƶ���굽�ļ���ͷ������������ļ�����
    in.seek(0);
    // ��ȡ�ļ�����
    // ��ȡ�ļ����ݣ�ֱ��ȫ�����ݶ���
    while (!in.atEnd()) {
        readString = in.readLine();
        // ����ȡ��ÿһ��������ʾ���ı�����
        textEdit->insertPlainText(readString + '\n');
    }

    // �ļ����������󣬹ر��ļ�
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
