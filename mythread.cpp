#include "mythread.h"

MyThread::MyThread()
{
    this->stop = false;
}

void MyThread::run()
{
    QTime t;
    t.start();

    long long size = 80000000000000;

    #pragma omp parallel for
    for(int n=0; n<size; ++n)
    {
        QMutex mutex;
        mutex.lock();
        if(this->stop)
            this->terminate();
        mutex.unlock();
        double m = std::sin(2 * M_PI * n / size);
    }

    qDebug("Time elapsed: %d ms", t.elapsed());
    emit finished(t.elapsed());
}
