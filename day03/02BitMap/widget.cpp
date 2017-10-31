#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QBitmap>
#include<QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,200,200,QPixmap("../IMAGE/timg (3).jpg"));
    painter.drawPixmap(200,0,200,200,QBitmap("../IMAGE/timg (3).jpg"));
}

Widget::~Widget()
{
    delete ui;
}
