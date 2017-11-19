#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);
    ~myThread();
protected:
    void run();
signals:
    void isDone();
public slots:
};

#endif // MYTHREAD_H
