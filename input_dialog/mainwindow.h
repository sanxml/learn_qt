#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>

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

    QPushButton *inputStringButton; // �ַ������밴ť
    QPushButton *inputIntButton;    // �������밴ť
    QPushButton *inputFloatButton;  // ���������밴ť
    QPushButton *inputItemButton;   // �б����밴ť
    QLineEdit   *inputLineEdit;     // �������ı���

private slots:
    void inputString();             // �ַ�������
    void inputInt();                // ��������
    void inputFloat();              // ����������
    void inputItem();               // �б�����
};

#endif // MAINWINDOW_H
