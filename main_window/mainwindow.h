#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>

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

    QMenu       *fileMenu;      // �ļ��˵�
    QMenu       *editMenu;      // �༭�˵�
    QMenu       *helpMenu;      // �����˵�
    QAction     *newAct;        // �½�
    QAction     *cutAct;        // ����
    QAction     *copyAct;       // ����
    QAction     *pasteAct;      // ճ��
    QAction     *aboutQtAct;    // ����Qt

    QToolBar    *fileToolBar;   // �ļ�������
    QToolBar    *editToolBar;   // �༭������
};

#endif // MAINWINDOW_H
