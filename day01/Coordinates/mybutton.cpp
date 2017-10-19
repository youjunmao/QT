#include "mybutton.h"

myButton::myButton(QWidget *parent) : QPushButton(parent)
{

}

myButton::~myButton()
{
    qDebug()<<"被析构";
}

