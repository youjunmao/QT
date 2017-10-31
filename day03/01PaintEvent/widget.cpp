#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPen>
#include<QBrush>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *)
{
    //QPainter paint(this);

    QPainter p;//创建画家对象
    p.begin(this);//制定当前窗口为绘图设备

    //画背景图
    //paint.drawPixmap(0,0,width(),height(),QPixmap("../IMAGE/timg (3).jpg"));
    //paint.drawPixmap(rect(),QPixmap("../IMAGE/timg (3).jpg"));

    //定义画笔
    QPen pen;
    pen.setWidth(5);
    pen.setStyle(Qt::DashLine);

    p.setPen(pen);
    //画直线
    p.drawLine(50,50,150,50);
    p.drawLine(50,50,50,150);
    //创建画刷对象
    QBrush brush;
    //设置颜色
    brush.setColor(Qt::red);
    //设置样式
    brush.setStyle(Qt::Dense1Pattern);
    //把画刷交给画家
    p.setBrush(brush);
    //画矩形
    p.drawRect(150,150,100,150);
    //画圆形
    p.drawEllipse(QPoint(150,150),50,25);

    p.end();


}

Widget::~Widget()
{
    delete ui;
}
