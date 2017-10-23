#include "mypushbutton.h"
#include<QMouseEvent>
#include<QDebug>
myPushButton::myPushButton(QWidget *parent) : QPushButton(parent)
{

}
void myPushButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
    {
        qDebug()<<"右键被按下";
        //事件接受，终止传递
        e->ignore();//忽略，事件给父组件传递，不是给父类传递
    }
    else
    {
        //事件忽略，事件往下传递
        QPushButton::mousePressEvent(e);
    }
}
myPushButton::~myPushButton()
{

}

