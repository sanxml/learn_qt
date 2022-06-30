#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>

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

    QPushButton *inputStringButton; // 字符串输入按钮
    QPushButton *inputIntButton;    // 整数输入按钮
    QPushButton *inputFloatButton;  // 浮点数输入按钮
    QPushButton *inputItemButton;   // 列表输入按钮
    QLineEdit   *inputLineEdit;     // 输入行文本框

private slots:
    void inputString();             // 字符串输入
    void inputInt();                // 整数输入
    void inputFloat();              // 浮点数输入
    void inputItem();               // 列表输入
};

#endif // MAINWINDOW_H
