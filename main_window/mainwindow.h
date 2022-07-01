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

    QMenu       *fileMenu;      // 文件菜单
    QMenu       *editMenu;      // 编辑菜单
    QMenu       *helpMenu;      // 帮助菜单
    QAction     *newAct;        // 新建
    QAction     *cutAct;        // 剪切
    QAction     *copyAct;       // 复制
    QAction     *pasteAct;      // 粘贴
    QAction     *aboutQtAct;    // 关于Qt

    QToolBar    *fileToolBar;   // 文件工具栏
    QToolBar    *editToolBar;   // 编辑工具栏
};

#endif // MAINWINDOW_H
