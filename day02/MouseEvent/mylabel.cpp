#include "mylabel.h"
#include<QMouseEvent>
#include<QDebug>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

MyLabel::~MyLabel()
{

}

void MyLabel::mouseMoveEvent(QMouseEvent * me)
{

    QString text=QString("<center><h1>Mouse Move:(%1,%2)</h1></center>").arg(me->x()).arg(me->y());
    this->setText(text);
}
void MyLabel::mousePressEvent(QMouseEvent * me)
{
    if(me->button()==Qt::LeftButton)
    {
        qDebug()<<"LeftButton";
    }
    else if(me->button()==Qt::RightButton)
    {
        qDebug()<<"RightButton";
    }
    else if(me->button()==Qt::MidButton)
    {
        qDebug()<<"MidButton";
    }
    QString text=QString("<center><h1>Mouse Press:(%1,%2)</h1></center>").arg(me->x()).arg(me->y());
    this->setText(text);
}
void MyLabel::mouseReleaseEvent(QMouseEvent * me)
{
    QString text=QString("<center><h1>Mouse Release:(%1,%2)</h1></center>").arg(me->x()).arg(me->y());
    this->setText(text);
}
