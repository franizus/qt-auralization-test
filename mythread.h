#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTime>
#include <omp.h>
#include <cmath>
#include <QMutex>

class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread();
    void run() override;
    bool stop;

signals:
    void finished(int);
};

#endif // MYTHREAD_H
