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

    QPoint offset;  //�����洢���ָ��λ���봰��λ�õĲ�ֵ
    QTextEdit *textEdit; //����һ���ı���

    int timerId1;   // ��ʱ��Id1
    int timerId2;   // ��ʱ��Id2
    int timerId3;   // ��ʱ��Id3
};

#endif // MAINWINDOW_H
