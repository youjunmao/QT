#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    resize(400,500);
    this->setWindowTitle("solider");
    b.setParent(this);
    b.setText("切换到主窗口咯");

    connect(&b,&QPushButton::clicked,this,&SubWidget::subChange);
}

void SubWidget::subChange()
{
    emit mySignals();
    emit mySignals(888,"我是solider");
}

SubWidget::~SubWidget()
{

}

