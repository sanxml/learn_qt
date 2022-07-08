#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    text_edit = new QTextEdit();
    text_edit->setGeometry(QRect(50, 50, 100, 25));
    input_edit = new QTextEdit();

    start_button = new QPushButton("Start");
    send_button = new QPushButton("Send");

    port_label = new QLabel("Port");
    baud_label = new QLabel("Baud rate");
    bits_label = new QLabel("Data bits");
    stop_label = new QLabel("Stop bits");
    parity_label = new QLabel("Parity");

    QComboBox *port_comboBox = new QComboBox;
    port_comboBox->addItem(tr("ttyACM0"));
    port_comboBox->addItem(tr("ttyACM1"));
    port_comboBox->addItem(tr("ttyACM2"));
    QComboBox *baud_comboBox = new QComboBox;
    baud_comboBox->addItem(tr("9600"));
    baud_comboBox->addItem(tr("19200"));
    baud_comboBox->addItem(tr("38400"));
    baud_comboBox->addItem(tr("57600"));
    baud_comboBox->addItem(tr("115200"));
    QComboBox *bits_comboBox = new QComboBox;
    bits_comboBox->addItem(tr("5"));
    bits_comboBox->addItem(tr("6"));
    bits_comboBox->addItem(tr("7"));
    bits_comboBox->addItem(tr("8"));
    QComboBox *stop_comboBox = new QComboBox;
    stop_comboBox->addItem(tr("1"));
    stop_comboBox->addItem(tr("2"));
    QComboBox *parity_comboBox = new QComboBox;
    parity_comboBox->addItem(tr("None"));
    parity_comboBox->addItem(tr("Odd"));
    parity_comboBox->addItem(tr("Even"));

    // 创建垂直页面布局管理对象
    QVBoxLayout *comboBox_layout = new QVBoxLayout;
    comboBox_layout->addWidget(port_comboBox);
    comboBox_layout->addWidget(baud_comboBox);
    comboBox_layout->addWidget(bits_comboBox);
    comboBox_layout->addWidget(stop_comboBox);
    comboBox_layout->addWidget(parity_comboBox);

    // 创建垂直页面布局管理对象
    QVBoxLayout *label_layout = new QVBoxLayout;
    label_layout->addWidget(port_label);
    label_layout->addWidget(baud_label);
    label_layout->addWidget(bits_label);
    label_layout->addWidget(stop_label);
    label_layout->addWidget(parity_label);

    // 创建水平页面布局管理
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(text_edit);
    hlayout->addLayout(label_layout);
    hlayout->addLayout(comboBox_layout);

    // 创建垂直页面布局管理对象
    QVBoxLayout *vlayout1 = new QVBoxLayout;
    vlayout1->addWidget(start_button);
    vlayout1->addWidget(send_button);

    // 创建水平页面布局管理
    QHBoxLayout *hlayout1 = new QHBoxLayout;
    hlayout1->addLayout(vlayout1);
    hlayout1->addWidget(input_edit);

    // 创建垂直页面布局管理对象
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(hlayout);
    layout->addLayout(hlayout1);
    // 演示布局管理器到边界的距离
    layout->setContentsMargins(10, 10, 10, 10);

    // 设置窗口布局
    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
