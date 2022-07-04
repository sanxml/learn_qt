#include "mainwindow.h"
#include <QApplication>
#include "mythread.h"
#include "writethread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // [1]ʵ�����߳���
    MyThread firstThread;
    MyThread secondThread;
    writeThread thridThread;

    // [2]�����߳�����
    firstThread.setObjectName("firsteThread");
    secondThread.setObjectName("secondThread");
    thridThread.setObjectName("thridThread");

    // [3]���� start() �����������߳�
    thridThread.start();
    firstThread.start();
    // firstThread.wait();
    secondThread.start();


    return a.exec();
}
