#include "mainwindow.h"
#include <QApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // [1]ʵ�����߳���
    MyThread firstThread;
    MyThread secondThread;

    // [2]�����߳�����
    firstThread.setObjectName("firsteThread");
    secondThread.setObjectName("secondThread");

    // [3]���� start() �����������߳�
    firstThread.start();
    secondThread.start();

    return a.exec();
}
