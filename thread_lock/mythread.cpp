#include "mythread.h"
#include "writethread.h"
extern QReadWriteLock lock;
MyThread::MyThread()
{

}

// 函数功能：每隔一秒，输出一条信息
void MyThread::run(){

    lock.lockForRead();
    qDebug() << "the thread" << objectName() << "start";
    for (int i = 0; i<10; i++){
        qDebug() << "The current thread is " << objectName()
                 << " is running :" << i << "times";
        sleep(1);
    }
    qDebug() << "the thread" << objectName() << "end";

    lock.unlock();
}