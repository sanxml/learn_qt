#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //������ť
    QPushButton *button = new QPushButton(this);
    //���ð�ťλ��
    button->setGeometry(QRect(50,50,100,25));
    //���ð�ť��ʾ����
    button->setText("change color");

    //������ǩ
    QLabel *label = new QLabel(this);
    //label λ��
    label->setGeometry(QRect(170,50,220,25));
    //label ֵ
    label->setText("the test of text color change");

    //����ť����Ӧ�¼�
    connect(button,SIGNAL(clicked()),this,SLOT(editText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editText()
{

    // ��ȡ��ǰlabel����ɫ
    QPalette pal = label->palette();
    QColor initColor = pal.color(QPalette::WindowText);
    // ������ɫ�Ի���
    QColor color = QColorDialog::getColor(initColor,this,"select color");
    // �ж���ɫѡ����Ч��
    if (color.isValid()) {
        pal.setColor(QPalette::WindowText,QColor(color));  //��ɫ�������ɫ
        label->setPalette(pal); //��label ����ɫ
    }

}