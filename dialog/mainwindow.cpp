#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //模态对话框
    // QDialog dialog(this);
    // dialog.exec();

    //非模态对话框
    QDialog *myDialog = new QDialog(this);
    myDialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
