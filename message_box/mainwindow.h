#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

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

    QPushButton *informationButton; // ��ʾ��ť
    QPushButton *warningButton;     // ���水ť
    QPushButton *criticalButton;       // ����ť
    QPushButton *aboutButton;       // ���ڰ�ť

private slots:
    void informationMessage();      // ��Ϣ��ʾ
    void warningMessage();          // ������Ϣ
    void ctrticalMessage();         // ������Ϣ
    void aboutMessage();            // ������Ϣ
};

#endif // MAINWINDOW_H
