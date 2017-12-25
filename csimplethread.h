#ifndef CSIMPLETHREAD_H
#define CSIMPLETHREAD_H
#include <QThread>
#include <QString>
class CSimpleThread:public QThread
{
public:
    CSimpleThread();
    bool run(QString data);
};

#endif // CSIMPLETHREAD_H
