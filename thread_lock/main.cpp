#include "mainwindow.h"
#include <QApplication>
#include "mythread.h"
#include "writethread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // [1]实例化线程类
    MyThread firstThread;
    MyThread secondThread;
    writeThread thridThread;

    // [2]设置线程名字
    firstThread.setObjectName("firsteThread");
    secondThread.setObjectName("secondThread");
    thridThread.setObjectName("thridThread");

    // [3]调用 start() 函数，启动线程
    thridThread.start();
    firstThread.start();
    // firstThread.wait();
    secondThread.start();


    return a.exec();
}
