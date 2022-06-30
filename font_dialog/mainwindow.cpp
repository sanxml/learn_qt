#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //������ť
    fontbutton = new QPushButton(this);
    //���ð�ťλ��
    fontbutton->setGeometry(QRect(50,150,80,25));
    //���ð�ť��ʾ����
    fontbutton->setText("font change");

    //����ť����Ӧ�¼�
    connect(fontbutton,SIGNAL(clicked()),this,SLOT(fontSelect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fontSelect()
{
    // ok���ڱ���Ƿ񵥻���OK��ť
    bool ok = false;
    // ��ȡ��ť���ֵ�����
    QFont initFont = fontbutton->font();
    // ѡ������
    QFont font=QFontDialog::getFont(&ok,initFont);
    // ������OK��ť������������Ϊѡ�������
    if (ok) {
        fontbutton->setFont(font);
    }
}