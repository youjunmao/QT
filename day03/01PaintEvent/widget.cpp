#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    //画背景图
    //paint.drawPixmap(0,0,width(),height(),QPixmap("../IMAGE/timg (3).jpg"));
    paint.drawPixmap(rect(),QPixmap("../IMAGE/timg (3).jpg"));
}

Widget::~Widget()
{
    delete ui;
}
