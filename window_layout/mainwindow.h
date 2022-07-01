#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>      // ���ڴ�����ť����
#include <QHBoxLayout>      // ����ˮƽ���ֵ���
#include <QVBoxLayout>      // ���ڴ�ֱ���ֵ���
#include <QTextEdit>        // ���ڴ����ı������
#include <QGridLayout>      // ����դ�񲼾ֵ���
#include <QLineEdit>        // ���ڴ������ı������
#include <QFormLayout>      // ���ڱ����ֵ���
#include <QStackedLayout>   // ���ڷ�ҳ���ֵ���
#include <QComboBox>        // �������������

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

    QPushButton *button1;       // ������ť1
    QPushButton *button2;       // ������ť2
    QPushButton *button3;       // ������ť3
    QPushButton *button4;       // ������ť4
    QPushButton *button5;       // ������ť5

    QPushButton *button6;       // ������ť6
    QPushButton *button7;       // ������ť7
    QPushButton *button8;       // ������ť8
    QPushButton *button9;       // ������ť9
    QPushButton *button10;      // ������ť10

    QPushButton *button11;      // ������ť11
    QPushButton *button12;      // ������ť12
    QTextEdit   *gridTextEdit;  // �����ı���

    QLineEdit   *nameLineEdit;  // ���� name �ı���
    QLineEdit   *emailLineEdit; // ���� email �ı���

    QPushButton *button13;      // ������ť13
    QPushButton *button14;      // ������ť14
    QPushButton *button15;      // ������ť15
    QPushButton *button16;      // ������ť16
    QPushButton *button17;      // ������ť17
    QPushButton *button18;      // ������ť18
};

#endif // MAINWINDOW_H
