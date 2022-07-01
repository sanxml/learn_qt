#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTextEdit>
#include <QKeyEvent>
#include <QTimerEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;

    QPoint offset;  //用来存储鼠标指针位置与窗口位置的差值
    QTextEdit *textEdit; //声明一个文本框

    int timerId1;   // 定时器Id1
    int timerId2;   // 定时器Id2
    int timerId3;   // 定时器Id3
};

#endif // MAINWINDOW_H
