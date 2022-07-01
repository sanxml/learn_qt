#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

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

    QPushButton *pushbutton;    //声明按钮
    QLineEdit   *lineEdit;      //声明文本框

//声明信号
signals:
    void signalShowText();

//声明槽
private slots:
    void showText();
};

#endif // MAINWINDOW_H
