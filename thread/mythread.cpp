#include "mythread.h"

MyThread::MyThread()
{

}

// �������ܣ�ÿ��һ�룬���һ����Ϣ
void MyThread::run(){
    qDebug() << "the thread" << objectName() << "start";
    for (int i = 0; i<10; i++){
        qDebug() << "The current thread is " << objectName()
                 << " is running :" << i << "times";
        sleep(1);
    }
    qDebug() << "the thread" << objectName() << "end";

}