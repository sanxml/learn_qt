#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]�ַ������밴ť
    inputStringButton = new QPushButton(this);
    //���ð�ťλ��
    inputStringButton->setGeometry(QRect(50,200,80,25));
    //���ð�ť��ʾ����
    inputStringButton->setText("input string");

    // [2]�������밴ť
    inputIntButton = new QPushButton(this);
    //���ð�ťλ��
    inputIntButton->setGeometry(QRect(150,200,80,25));
    //���ð�ť��ʾ����
    inputIntButton->setText("input int");

    // [3]���������밴ť
    inputFloatButton = new QPushButton(this);
    //���ð�ťλ��
    inputFloatButton->setGeometry(QRect(50,250,80,25));
    //���ð�ť��ʾ����
    inputFloatButton->setText("input float");

    // [4]�б����밴ť
    inputItemButton = new QPushButton(this);
    //���ð�ťλ��
    inputItemButton->setGeometry(QRect(150,250,80,25));
    //���ð�ť��ʾ����
    inputItemButton->setText("input item");

    // �������ı���
    inputLineEdit = new QLineEdit(this);
    //���ı����λ��
    inputLineEdit->setGeometry(QRect(50,300,180,25));

    //����ť����Ӧ�¼�
    connect(inputStringButton,SIGNAL(clicked()),this,SLOT(inputString()));
    connect(inputIntButton,SIGNAL(clicked()),this,SLOT(inputInt()));
    connect(inputFloatButton,SIGNAL(clicked()),this,SLOT(inputFloat()));
    connect(inputItemButton,SIGNAL(clicked()),this,SLOT(inputItem()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [1]�ַ�������
void MainWindow::inputString(){
    bool ok=false;
    QString string = QInputDialog::getText(this,"input string dialog",
                                           "please input file name",QLineEdit::Normal,"admin",&ok);

    if (ok && !string.isEmpty()){
        inputLineEdit->setText(string);
    }
}

// [2]��������
void MainWindow::inputInt(){
    bool ok=false;
    int intValue = QInputDialog::getInt(this,"input int dialog","please input a number of -100~100 ",
                                        100,-100,100,10,&ok);

    if (ok){
        inputLineEdit->setText(QString::number(intValue));  // ��������ת�����ַ�����ʾ
    }
}

// [3]����������
void MainWindow::inputFloat(){
    bool ok=false;
    float floatValue = QInputDialog::getDouble(this,"inpt float dialog","input a number of -100~100",
                                               0.00,-100,100,2,&ok);
    if (ok){
        inputLineEdit->setText(QString::number(floatValue));
    }
}

// [4]�б�����
void MainWindow::inputItem(){
    // ������Ŀ�б�
    QStringList items;
    items <<"item1" <<"item2" <<"item3";
    bool ok=false;
    QString item = QInputDialog::getItem(this,"input item dialog","please select a item",
                                         items,0,true,&ok);
    if (ok && !item.isEmpty()){
        inputLineEdit->setText(item);
    }
}