#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QTextEdit>
#include <QHBoxLayout>

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

    QTextEdit *textEdit1;   //声明文本框1
    QTextEdit *textEdit2;   //声明文本框2
    QTextEdit *textEdit3;   //声明文本框3
};

#endif // MAINWINDOW_H
