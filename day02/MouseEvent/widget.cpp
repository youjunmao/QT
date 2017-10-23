#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QKeyEvent>
#include<QMessageBox>
#include<QCloseEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[this](){
        qDebug()<<"被按下";
    });
}
void Widget::closeEvent(QCloseEvent * e)
{
    int ret=QMessageBox::question(this,"question","是否关闭界面");
    if(ret==QMessageBox::Yes)
    {
        e->accept();
        //接受事件，终止事件继续往下传递
    }
    else
    {
        e->ignore();

    }
}

void Widget::mousePressEvent(QMouseEvent *)
{
    qDebug()<<"XXXXXXXXXXXXXXXXXXXXXXX";
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    qDebug()<<(char)e->key();
    if(e->key()==Qt::Key_A)
    {
        qDebug()<<"Key_A";
    }
}
Widget::~Widget()
{
    delete ui;
}
