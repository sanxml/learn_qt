#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort> // 串口的类
#include <QLabel>      // 用于创建标签的类
#include <QPushButton> // 用于创建按钮的类
#include <QComboBox>   // 用于创建下拉框的类
#include <QTextEdit>   // 用于创建文本框的类
#include <QLineEdit>   // 用于创建行文本框的类
#include <QHBoxLayout> // 用于水平布局的类
#include <QVBoxLayout> // 用于垂直布局的类

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QSerialPort *serial_port; // 串口对象
    QTextEdit *text_edit;     // 声明文本框
    QTextEdit *input_edit;    // 声明文本框

    QPushButton *start_button; // 声明开启按钮
    QPushButton *send_button;  // 声明发送按钮

    QLabel *port_label;
    QLabel *baud_label;
    QLabel *bits_label;
    QLabel *stop_label;
    QLabel *parity_label;
};

#endif // MAINWINDOW_H
