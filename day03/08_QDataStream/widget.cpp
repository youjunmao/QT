#include "widget.h"
#include "ui_widget.h"
#include<QDataStream>
#include<QFile>
#include<QDebug>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //writeData();
    readData();
}

void Widget::writeData()
{
    QFile file("../test.txt");
    bool isOpen=file.open(QIODevice::WriteOnly);\
    if(isOpen)
    {
        //创建数据流，和file文件关联
        //往数据流中写数据，相当于往文件中写数据
        QDataStream stream(&file);
        stream<<"主要是帅气"<<250;

        file.close();
    }
}

void Widget::readData()
{
    QFile file("../test.txt");
    bool isOpen=file.open(QIODevice::ReadOnly);\
    if(isOpen)
    {
        //创建数据流，和file文件关联
        //往数据流中读数据，相当于往文件中读数据
        QDataStream stream(&file);
        QString str;
        int     age;

        stream>>str>>age;

        cout<<str.toUtf8().data()<<age;

        file.close();
    }
}

Widget::~Widget()
{
    delete ui;
}
