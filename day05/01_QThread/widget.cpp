#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&thread,&myThread::isDone,this,&Widget::backDone);
    connect(&timer,&QTimer::timeout,this,&Widget::backTimeout);
    connect(&thread,&myThread::destroyed,this,&Widget::backDestoryThread);
}

void Widget::backDestoryThread()
{
    //销毁线程时，停止线程
    thread.quit();

    thread.wait();

    qDebug()<<"Widget::backDestoryThread()";
}

void Widget::backTimeout()
{
    static int _value=0;
    _value++;
    ui->lcdNumber->display(_value);
}

void Widget::backDone()
{
    timer.stop();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(timer.isActive()==false)
    {
        timer.start(100);
    }
    //开启线程
    thread.start();
}
