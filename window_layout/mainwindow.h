#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>      // 用于创建按钮的类
#include <QHBoxLayout>      // 用于水平布局的类
#include <QVBoxLayout>      // 用于垂直布局的类
#include <QTextEdit>        // 用于创建文本框的类
#include <QGridLayout>      // 用于栅格布局的类
#include <QLineEdit>        // 用于创建行文本框的类
#include <QFormLayout>      // 用于表单布局的类
#include <QStackedLayout>   // 用于分页布局的类
#include <QComboBox>        // 用于下拉框的类

namespace Ui {
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

    QPushButton *button1;       // 声明按钮1
    QPushButton *button2;       // 声明按钮2
    QPushButton *button3;       // 声明按钮3
    QPushButton *button4;       // 声明按钮4
    QPushButton *button5;       // 声明按钮5

    QPushButton *button6;       // 声明按钮6
    QPushButton *button7;       // 声明按钮7
    QPushButton *button8;       // 声明按钮8
    QPushButton *button9;       // 声明按钮9
    QPushButton *button10;      // 声明按钮10

    QPushButton *button11;      // 声明按钮11
    QPushButton *button12;      // 声明按钮12
    QTextEdit   *gridTextEdit;  // 声明文本框

    QLineEdit   *nameLineEdit;  // 声明 name 文本框
    QLineEdit   *emailLineEdit; // 声明 email 文本框

    QPushButton *button13;      // 声明按钮13
    QPushButton *button14;      // 声明按钮14
    QPushButton *button15;      // 声明按钮15
    QPushButton *button16;      // 声明按钮16
    QPushButton *button17;      // 声明按钮17
    QPushButton *button18;      // 声明按钮18
};

#endif // MAINWINDOW_H
