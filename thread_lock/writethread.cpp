#include "writethread.h"

QReadWriteLock lock;

writeThread::writeThread()
{

}

void writeThread::run(){
    // д��
    lock.lockForWrite();

    qDebug() << "the thread" << objectName() << "start";
    for (int i = 0; i<10; i++){
        qDebug() << "The current thread is " << objectName()
                 << " is running :" << i << "times";
        sleep(1);
    }
    qDebug() << "the thread" << objectName() << "end";

    // ����
    lock.unlock();
}