#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //绘图设备
    QPixmap pixmap(400,300);

    QPainter p(&pixmap);

    pixmap.fill(Qt::white);

    p.drawPixmap(0,0,400,400,QPixmap("../IMAGE/timg (3).jpg"));

    pixmap.save("../kawaiyi.png");
}

Widget::~Widget()
{
    delete ui;
}
