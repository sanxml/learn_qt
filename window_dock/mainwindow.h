#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

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
    QLabel        *label;           // 设置一个标签
    QPushButton   *button1;         // 按钮1
    QPushButton   *button2;         // 按钮2
    QPushButton   *button3;         // 按钮3
    QTextEdit     *textEdit;        // 文本框

};

#endif // MAINWINDOW_H
