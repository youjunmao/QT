#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer=new QTimer(this);
    connect(myTimer,&QTimer::timeout,
            [=](){
        static int i=0;
        i++;
        ui->text->setFontWeight(36);
        ui->text->setText(QString::number(i));
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startBtn_clicked()
{
    if(false==myTimer->isActive())
    {
        myTimer->start(100);
    }
}

void Widget::on_stopBtn_clicked()
{
    if(true==myTimer->isActive())
    {
        myTimer->stop();
    }
}
