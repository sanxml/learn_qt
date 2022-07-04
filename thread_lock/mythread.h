#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>
#include <QReadWriteLock>

class MyThread : public QThread
{
public:
    MyThread();
protected:
    void run();
};

#endif // MYTHREAD_H