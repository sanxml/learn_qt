#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体标题
    this->setWindowTitle("title of my mainwindow");
    //窗体最大200*200
    this->setMaximumSize(400,400);
    //窗体最小200*200
    this->setMinimumSize(200,200);
    //修改窗体显示的初始位置
    this->move(100,200);
    //窗体ICO图片
    this->setWindowIcon(QIcon(":/ico/Iconsmind-Outline-Bear.ico"));

    newAct = new QAction(tr( "New" ), this );           // 创建newAction
    newAct->setShortcut(tr("Ctrl+N" ));                 // 设置快捷键
    newAct->setStatusTip(tr("create a new file" ));     // 设置状态栏提示信息

    cutAct = new QAction(tr( "Cut" ), this );           // 创建cutAction
    cutAct->setShortcut(tr("Ctrl+X" ));                 // 设置快捷键
    cutAct->setStatusTip(tr("cut contents" ));          // 设置状态栏提示信息

    copyAct = new QAction( tr( "Copy" ), this );        // 创建copyAction
    copyAct->setShortcut(tr("Ctrl+C" ));                // 设置快捷键
    copyAct->setStatusTip(tr("copy contents" ));        // 设置状态栏提示信息

    pasteAct = new QAction(tr( "Paste" ), this );       // 创建pasteAction
    pasteAct->setShortcut(tr("Ctrl+V" ));               // 设置快捷键
    pasteAct->setStatusTip(tr("paste contents" ));      // 设置状态栏提示信息

    aboutQtAct = new QAction(tr( "about Qt" ), this );          // 创建newAction
    aboutQtAct->setStatusTip(tr("about Qt information" ));      // 设置状态栏提示信息
    aboutQtAct->setIcon(QIcon(":/ico/Iconsmind-Outline-Bear.ico"));     // 菜单action添加图片
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));    // 绑定一个Qt自带的槽

    fileMenu = new QMenu(this);                         // 创建菜单项
    fileMenu = menuBar()->addMenu(tr( "File" ));        // 增加菜单项到菜单栏上
    fileMenu->addAction(newAct);                        // 增加 newAction 到File菜单上
    fileMenu->addSeparator();                           // 增加菜单分隔符

    editMenu = new QMenu(this);                         // 创建菜单项
    editMenu = menuBar()->addMenu(tr("Edit" ));         // 增加菜单项到菜单栏上
    editMenu->addAction(cutAct);                        // 增加 cutAction 到Edit菜单上
    editMenu->addAction(copyAct);                       // 增加 copyAction 到Edit菜单上
    editMenu->addAction(pasteAct);                      // 增加 pasteAction 到Edit菜单上
    menuBar()->addSeparator();                          // 增加菜单分隔符

    helpMenu = new QMenu(this);                         // 创建菜单项
    helpMenu = menuBar()->addMenu(tr("Help" ));         // 增加菜单项到菜单栏上
    helpMenu->addAction(aboutQtAct);                    // 增加 aboutAction 到Edit菜单上

    fileToolBar = addToolBar(tr("New"));                // 创建新建工具栏
    fileToolBar->addAction(newAct);                     // 给工具栏增加 newAction

    editToolBar = addToolBar(tr("Edit"));               // 创建编辑工具栏
    editToolBar->addAction(cutAct);                     // 给工具栏增加 cutAction
    editToolBar->addAction(copyAct);                    // 给工具栏增加 copyAction
    editToolBar->addAction(pasteAct);                   // 给工具栏增加 pasteAction
}

MainWindow::~MainWindow()
{
    delete ui;
}
