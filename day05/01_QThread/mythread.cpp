#include "mythread.h"

myThread::myThread(QObject *parent) : QThread(parent)
{

}

void myThread::run()
{
    //非常复杂的数据耗时太长
    sleep(5);
    emit isDone();
}

myThread::~myThread()
{

}

