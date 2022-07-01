#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ������ť1
    button1 = new QPushButton("One");
    // ������ť2
    button2 = new QPushButton("Two");
    // ������ť3
    button3 = new QPushButton("Three");
    // ������ť4
    button4 = new QPushButton("Four");
    // ������ť5
    button5 = new QPushButton("Five");

    // ������ť6
    button6 = new QPushButton("Six");
    // ������ť7
    button7 = new QPushButton("Seven");
    // ������ť8
    button8 = new QPushButton("Eight");
    // ������ť9
    button9 = new QPushButton("Nine");
    // ������ť10
    button10 = new QPushButton("Ten");

    // ������ť11
    button11 = new QPushButton("Eleven");
    // ������ť12
    button12 = new QPushButton("Twelve");
    // �����ı���
    gridTextEdit = new QTextEdit();

    // �������ı���
    nameLineEdit = new QLineEdit();
    emailLineEdit = new QLineEdit();

    // [1]����ˮƽҳ�沼�ֹ������
    QHBoxLayout *hlayout = new QHBoxLayout;
    // ��ˮƽ�������� ��ť1
    hlayout->addWidget(button1);
    // ��ˮƽ�������� ��ť2
    hlayout->addWidget(button2);
    // ��ˮƽ�������� ��ť3
    hlayout->addWidget(button3);
    // ��ˮƽ�������� ��ť4
    hlayout->addWidget(button4);
    // ��ˮƽ�������� ��ť5
    hlayout->addWidget(button5);

   // ��ʾˮƽ����֮�����Ӽ��
    hlayout->setSpacing(20);

    // [2]������ֱҳ�沼�ֹ������
    QVBoxLayout *vlayout = new QVBoxLayout;
    // ��ֱ�������� ��ť6
    vlayout->addWidget(button6);
    // ��ֱ�������� ��ť7
    vlayout->addWidget(button7);
    // ��ֱ�������� ��ť8
    vlayout->addWidget(button8);
    // ��ʾ�ڰ�ť֮������һ��ռλ
    vlayout->addStretch();
    // ��ֱ�������� ��ť9
    vlayout->addWidget(button9);
    // ��ֱ�������� ��ť10
    vlayout->addWidget(button10);

    // [4]����դ��ҳ�沼�ֹ������
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(button11,0,0,1,1);
    gridLayout->addWidget(button12,0,1,1,1);
    gridLayout->addWidget(gridTextEdit,2,0,4,2);

    // [6]������ҳ�沼�ֹ������
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("&Name:"), nameLineEdit);
    formLayout->addRow(tr("&Email:"), emailLineEdit);

    // [7.1]��һ����׼��3��ҳ�棬ÿ��ҳ�����һЩ���
    QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    QWidget *thirdPageWidget = new QWidget;
    // ׼��ҳ�����������6����ť��ÿ��ҳ�����һ����ť
    button13 = new QPushButton("Page 1 button13");
    button14 = new QPushButton("Page 1 button14");
    button15 = new QPushButton("Page 2 button15");
    button16 = new QPushButton("Page 2 button16");
    button17 = new QPushButton("Page 3 button17");
    button18 = new QPushButton("Page 3 button18");
    // ����3��ҳ�沼�֣�ÿ��ҳ��һ������
    QVBoxLayout *page1layout = new QVBoxLayout;
    QHBoxLayout *page2layout = new QHBoxLayout;
    QVBoxLayout *page3layout = new QVBoxLayout;
    // ����ҳ����������
    page1layout->addWidget(button13);
    page1layout->addWidget(button14);
    page2layout->addWidget(button15);
    page2layout->addWidget(button16);
    page3layout->addWidget(button17);
    page3layout->addWidget(button18);
    // ���÷�ҳ����
    firstPageWidget->setLayout(page1layout);
    secondPageWidget->setLayout(page2layout);
    thirdPageWidget->setLayout(page3layout);

    // [7.2]�ڶ��������� QStackedLayout ҳ�沼�ֹ�����󣬰ѷ�ҳ��ӵ����������
    QStackedLayout *stackedLayout = new QStackedLayout;
    // ���ҳ���ֶ������ҳ��
    stackedLayout->addWidget(firstPageWidget);
    stackedLayout->addWidget(secondPageWidget);
    stackedLayout->addWidget(thirdPageWidget);

    // [7.3]�����������÷�ҳ�л�������ʹ�� QComboBox��QListWidget ʵ��
    QComboBox *pageComboBox = new QComboBox;
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));
    pageComboBox->addItem(tr("Page 3"));
    connect(pageComboBox, SIGNAL(activated(int)),stackedLayout, SLOT(setCurrentIndex(int)));

    // [5]����ˮƽҳ�沼�ֹ���
    QHBoxLayout *gridhlayout = new QHBoxLayout;
    gridhlayout->addLayout(vlayout);
    gridhlayout->addLayout(gridLayout);

    // [3]������ֱҳ�沼�ֹ������
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(formLayout);
    layout->addLayout(hlayout);
    layout->addLayout(gridhlayout);
    // layout->addLayout(vlayout);

    // [7.4]���Ĳ����� QStackedLayout ������ӵ��������ϣ�����ҳ�л������ӵ�һ��������
    vlayout->addWidget(pageComboBox);
    layout->addLayout(stackedLayout); // ����ҳ����ӷ�ҳ����

    // ��ʾ���ֹ��������߽�ľ���
    layout->setContentsMargins(10,10,10,10);

    // ���ô��ڲ���
    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);
    this->setCentralWidget(widget);
    // ���ô���Ϊ�̶��ߴ磬sizeHint()�����������Ǳ��ִ���Ϊ�����С�ĳߴ�
    // this->setFixedSize(sizeHint());// ���ú�ҳ���С���ɵ�����һֱ����ϵͳ�Ƽ���С��״̬

}

MainWindow::~MainWindow()
{
    delete ui;
}
