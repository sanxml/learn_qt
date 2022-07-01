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
    textEdit->setGeometry(50,50,700,500);

    // ʵ����QFile����ָ���ļ���
    QFile file("/home/geo/Desktop/learn_qt/file_io/test.txt");
    // ��ֻ���ķ�ʽ���ļ���������ļ����ִ��󣬳����˳�
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // ��ȡ�ļ����ݣ�ֱ��ȫ�����ݶ���
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        // ����ȡ��ÿһ��������ʾ���ı�����
        textEdit->insertPlainText(line);
    }

    // �ļ����������󣬹ر��ļ�
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
