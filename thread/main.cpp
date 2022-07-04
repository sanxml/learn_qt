#include "mainwindow.h"
#include <QApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // [1]实例化线程类
    MyThread firstThread;
    MyThread secondThread;

    // [2]设置线程名字
    firstThread.setObjectName("firsteThread");
    secondThread.setObjectName("secondThread");

    // [3]调用 start() 函数，启动线程
    firstThread.start();
    secondThread.start();

    return a.exec();
}
