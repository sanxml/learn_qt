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

    QTextEdit *textEdit1;   //�����ı���1
    QTextEdit *textEdit2;   //�����ı���2
    QTextEdit *textEdit3;   //�����ı���3
};

#endif // MAINWINDOW_H
