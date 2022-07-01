#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // [1]����һ������������ʾ���ı���
    textEdit = new QTextEdit;
    textEdit->setText("main widget");
    // �����ı���Ĵ�С
    textEdit->setFixedSize(300,300);
    // ���ı�������Ϊ�������Ĵ���
    this->setCentralWidget(textEdit);
    // ������������߿�ľ���
    this->setContentsMargins(15,15,15,15);
    //�����ó�������С
    this->setFixedSize(450,330);

    // [2]�������
    label = new QLabel;
    label->setText("widget1");
    button1 = new QPushButton("aboutQt");
    button2 = new QPushButton("button2");
    button3 = new QPushButton("close");
    // ��������ť�󶨲ۣ�ʵ�ּ򵥵Ĺ���
    connect(button1,SIGNAL(clicked()),qApp,SLOT(aboutQt()));// ����QT
    connect(button3,SIGNAL(clicked()),this,SLOT(close()));  // �رճ���

    // [3]����ҳ�沼��,���ڱ�ǩ�Ͱ�ť�Ĳ���
    QVBoxLayout *docklayout_1 = new QVBoxLayout;
    // �򲼾�������
    docklayout_1->addWidget(label);
    docklayout_1->addStretch();
    docklayout_1->addWidget(button1);
    QVBoxLayout *docklayout_2 = new QVBoxLayout;
    // �򲼾�������
    docklayout_2->addStretch();
    docklayout_2->addWidget(button2);
    docklayout_2->addWidget(button3);

    // [4]�����������
    QWidget *widget1 = new QWidget;
    QWidget *widget2 = new QWidget;

    // [5]���ô�������Ĳ���
    widget1->setLayout(docklayout_1);
    widget2->setLayout(docklayout_2);

    // [6]����ͣ�����ڣ�������������������ӵ�ͣ��������
    QDockWidget *dock = new QDockWidget(tr("myDockWindow"), this);
    // ����ͣ������
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // ����ͣ�����ڵ�����
    dock->setFeatures(QDockWidget::DockWidgetMovable); //ͣ�����ڿ��ƶ�����
    // ���� widget1 ����Ϊͣ������
    dock->setWidget(widget1);
    // ����ͣ�����ڵĴ�С
    dock->setFixedSize(100,100);
    // ���ñ߿���ɫ
    dock->setStyleSheet((QString::fromUtf8("border:1px solid gray")));
    // ��������������ͣ������
    this->addDockWidget(Qt::RightDockWidgetArea,dock);

    QDockWidget *dock1 = new QDockWidget(tr("myDockWindow"), this);
    // ����ͣ������
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // ����ͣ�����ڵ�����
    dock1->setFeatures(QDockWidget::AllDockWidgetFeatures); //����ͣ�����ڵ�ȫ������
    // ���� widget2 ����Ϊͣ������
    dock1->setWidget(widget2);
    // ����ͣ�����ڵĴ�С
    dock1->setFixedSize(100,200);
    // ���ñ߿���ɫ
    dock1->setStyleSheet((QString::fromUtf8("border:1px solid gray")));
    // ��������������ͣ������
    this->addDockWidget(Qt::RightDockWidgetArea,dock1);

    // [7]��������ͣ�����ڵ�λ�ã���ֱ����
    splitDockWidget(dock,dock1,Qt::Vertical);
}

MainWindow::~MainWindow()
{
    delete ui;
}
