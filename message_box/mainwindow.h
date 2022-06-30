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

    QPushButton *informationButton; // 提示按钮
    QPushButton *warningButton;     // 警告按钮
    QPushButton *criticalButton;       // 错误按钮
    QPushButton *aboutButton;       // 关于按钮

private slots:
    void informationMessage();      // 消息提示
    void warningMessage();          // 警告信息
    void ctrticalMessage();         // 错误信息
    void aboutMessage();            // 关于信息
};

#endif // MAINWINDOW_H
