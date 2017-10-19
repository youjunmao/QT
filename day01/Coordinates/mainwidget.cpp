#include "mainwidget.h"
#include "mybutton.h"
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,500);
    move(0,0);
    /*符合以下两点
     * 1）指定父对象后
     * 2）直接或间接继承于QObject
     * 子对象如果是动态分配空间的new，不需要手动释放delete
     * 系统会自动释放
    */
    myButton* p=new myButton(this);
    p->setText("heihei");
    p->move(50,50);
}

MainWidget::~MainWidget()
{

}
