#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort> // ���ڵ���
#include <QLabel>      // ���ڴ�����ǩ����
#include <QPushButton> // ���ڴ�����ť����
#include <QComboBox>   // ���ڴ������������
#include <QTextEdit>   // ���ڴ����ı������
#include <QLineEdit>   // ���ڴ������ı������
#include <QHBoxLayout> // ����ˮƽ���ֵ���
#include <QVBoxLayout> // ���ڴ�ֱ���ֵ���

namespace Ui
{
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

    QSerialPort *serial_port; // ���ڶ���
    QTextEdit *text_edit;     // �����ı���
    QTextEdit *input_edit;    // �����ı���

    QPushButton *start_button; // ����������ť
    QPushButton *send_button;  // �������Ͱ�ť

    QLabel *port_label;
    QLabel *baud_label;
    QLabel *bits_label;
    QLabel *stop_label;
    QLabel *parity_label;
};

#endif // MAINWINDOW_H
