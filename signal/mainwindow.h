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

    QPushButton *pushbutton;    //������ť
    QLineEdit   *lineEdit;      //�����ı���

//�����ź�
signals:
    void signalShowText();

//������
private slots:
    void showText();
};

#endif // MAINWINDOW_H
