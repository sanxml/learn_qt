#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ģ̬�Ի���
    // QDialog dialog(this);
    // dialog.exec();

    //��ģ̬�Ի���
    QDialog *myDialog = new QDialog(this);
    myDialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
