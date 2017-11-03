#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,400);
    //去窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    //去背景
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,QPixmap("../IMAGE/kawaiyi.png"));
}

Widget::~Widget()
{
    delete ui;
}
