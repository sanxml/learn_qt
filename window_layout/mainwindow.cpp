#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建按钮1
    button1 = new QPushButton("One");
    // 创建按钮2
    button2 = new QPushButton("Two");
    // 创建按钮3
    button3 = new QPushButton("Three");
    // 创建按钮4
    button4 = new QPushButton("Four");
    // 创建按钮5
    button5 = new QPushButton("Five");

    // 创建按钮6
    button6 = new QPushButton("Six");
    // 创建按钮7
    button7 = new QPushButton("Seven");
    // 创建按钮8
    button8 = new QPushButton("Eight");
    // 创建按钮9
    button9 = new QPushButton("Nine");
    // 创建按钮10
    button10 = new QPushButton("Ten");

    // 创建按钮11
    button11 = new QPushButton("Eleven");
    // 创建按钮12
    button12 = new QPushButton("Twelve");
    // 创建文本框
    gridTextEdit = new QTextEdit();

    // 创建行文本框
    nameLineEdit = new QLineEdit();
    emailLineEdit = new QLineEdit();

    // [1]创建水平页面布局管理对象
    QHBoxLayout *hlayout = new QHBoxLayout;
    // 向水平布局增加 按钮1
    hlayout->addWidget(button1);
    // 向水平布局增加 按钮2
    hlayout->addWidget(button2);
    // 向水平布局增加 按钮3
    hlayout->addWidget(button3);
    // 向水平布局增加 按钮4
    hlayout->addWidget(button4);
    // 向水平布局增加 按钮5
    hlayout->addWidget(button5);

   // 演示水平布局之间增加间隔
    hlayout->setSpacing(20);

    // [2]创建垂直页面布局管理对象
    QVBoxLayout *vlayout = new QVBoxLayout;
    // 向垂直布局增加 按钮6
    vlayout->addWidget(button6);
    // 向垂直布局增加 按钮7
    vlayout->addWidget(button7);
    // 向垂直布局增加 按钮8
    vlayout->addWidget(button8);
    // 演示在按钮之间增加一个占位
    vlayout->addStretch();
    // 向垂直布局增加 按钮9
    vlayout->addWidget(button9);
    // 向垂直布局增加 按钮10
    vlayout->addWidget(button10);

    // [4]创建栅格页面布局管理对象
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(button11,0,0,1,1);
    gridLayout->addWidget(button12,0,1,1,1);
    gridLayout->addWidget(gridTextEdit,2,0,4,2);

    // [6]创建表单页面布局管理对象
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("&Name:"), nameLineEdit);
    formLayout->addRow(tr("&Email:"), emailLineEdit);

    // [7.1]第一步：准备3个页面，每个页面放置一些组件
    QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    QWidget *thirdPageWidget = new QWidget;
    // 准备页面组件：创建6个按钮，每个页面放置一个按钮
    button13 = new QPushButton("Page 1 button13");
    button14 = new QPushButton("Page 1 button14");
    button15 = new QPushButton("Page 2 button15");
    button16 = new QPushButton("Page 2 button16");
    button17 = new QPushButton("Page 3 button17");
    button18 = new QPushButton("Page 3 button18");
    // 创建3个页面布局，每个页面一个布局
    QVBoxLayout *page1layout = new QVBoxLayout;
    QHBoxLayout *page2layout = new QHBoxLayout;
    QVBoxLayout *page3layout = new QVBoxLayout;
    // 给分页布局添加组件
    page1layout->addWidget(button13);
    page1layout->addWidget(button14);
    page2layout->addWidget(button15);
    page2layout->addWidget(button16);
    page3layout->addWidget(button17);
    page3layout->addWidget(button18);
    // 设置分页布局
    firstPageWidget->setLayout(page1layout);
    secondPageWidget->setLayout(page2layout);
    thirdPageWidget->setLayout(page3layout);

    // [7.2]第二步：创建 QStackedLayout 页面布局管理对象，把分页添加到这个对象上
    QStackedLayout *stackedLayout = new QStackedLayout;
    // 向分页布局对象添加页面
    stackedLayout->addWidget(firstPageWidget);
    stackedLayout->addWidget(secondPageWidget);
    stackedLayout->addWidget(thirdPageWidget);

    // [7.3]第三步：设置分页切换方法，使用 QComboBox或QListWidget 实现
    QComboBox *pageComboBox = new QComboBox;
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));
    pageComboBox->addItem(tr("Page 3"));
    connect(pageComboBox, SIGNAL(activated(int)),stackedLayout, SLOT(setCurrentIndex(int)));

    // [5]创建水平页面布局管理
    QHBoxLayout *gridhlayout = new QHBoxLayout;
    gridhlayout->addLayout(vlayout);
    gridhlayout->addLayout(gridLayout);

    // [3]创建垂直页面布局管理对象
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(formLayout);
    layout->addLayout(hlayout);
    layout->addLayout(gridhlayout);
    // layout->addLayout(vlayout);

    // [7.4]第四步：将 QStackedLayout 布局添加到主布局上，将分页切换组件添加到一个布局上
    vlayout->addWidget(pageComboBox);
    layout->addLayout(stackedLayout); // 向主页面添加分页布局

    // 演示布局管理器到边界的距离
    layout->setContentsMargins(10,10,10,10);

    // 设置窗口布局
    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);
    this->setCentralWidget(widget);
    // 设置窗口为固定尺寸，sizeHint()函数的作用是保持窗口为理想大小的尺寸
    // this->setFixedSize(sizeHint());// 设置后页面大小不可调整，一直处于系统推荐大小的状态

}

MainWindow::~MainWindow()
{
    delete ui;
}
