#ifndef QTHREAD_H
#define QTHREAD_H

#include <QThread>

class Mythread : public QThread
{
public:
    Mythread();
    void run();
};

#endif // QTHREAD_H
