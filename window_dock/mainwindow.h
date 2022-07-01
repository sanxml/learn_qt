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
    QLabel        *label;           // ����һ����ǩ
    QPushButton   *button1;         // ��ť1
    QPushButton   *button2;         // ��ť2
    QPushButton   *button3;         // ��ť3
    QTextEdit     *textEdit;        // �ı���

};

#endif // MAINWINDOW_H
