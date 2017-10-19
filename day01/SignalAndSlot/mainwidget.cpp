#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,500);
    b.setParent(this);
    b.setText("close");
    b.move(200,200);

    b2=new QPushButton(this);
    b2->setText("kkk");

    connect(&b,&QPushButton::pressed,this,&MainWidget::close);

    connect(b2,&QPushButton::released,this,&MainWidget::mySlot);

    connect(b2,&QPushButton::released,&b,&MainWidget::hide);

    setWindowTitle("BOSS");

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);

    connect(&b3,&QPushButton::clicked,this,&MainWidget::changeWindows);
    void (SubWidget::*function1)()=&SubWidget::mySignals;
    connect(&w,function1,this,&MainWidget::dealSub);
    void (SubWidget::*function2)(int,QString)=&SubWidget::mySignals;
    connect(&w,function2,this,&MainWidget::dealSolt);

    QPushButton* p4=new QPushButton(this);
    p4->setText("lambda");
    p4->move(110,120);
    connect(p4,&QPushButton::clicked,[p4](bool click){
        qDebug()<<click;
        p4->setText("oooo");
    });
}

void MainWidget::dealSolt(int args1,QString args2)
{
    qDebug()<<args1<<args2.toUtf8().data();
}

void MainWidget::dealSub()
{
    show();
    w.hide();
}

void MainWidget::changeWindows()
{
    w.show();
    hide();
}

void MainWidget::mySlot()
{
    b2->setText("llll");
}
MainWidget::~MainWidget()
{

}
