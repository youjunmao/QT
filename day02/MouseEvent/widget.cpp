#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QKeyEvent>
#include<QMessageBox>
#include<QEvent>
#include<QCloseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[this](){
        qDebug()<<"被按下";
    });
    //安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(true);
}
bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==this->ui->label_2)
    {
        QMouseEvent* env=static_cast<QMouseEvent*>(e);
        if(e->type()==QEvent::MouseMove)
        {
            ui->label_2->setText(QString("Move move:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;//事件终止
        }
    }
    return QWidget::eventFilter(obj,e);
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
