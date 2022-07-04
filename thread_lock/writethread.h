#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QThread>
#include <QDebug>
#include <QReadWriteLock>

class writeThread : public QThread
{
public:
    writeThread();
protected:
    void run();
};

#endif // MYTHREAD_H