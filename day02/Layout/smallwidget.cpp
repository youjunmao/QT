#include "smallwidget.h"
#include<QSpinBox>
#include<QSlider>
#include<QHBoxLayout>
smallWidget::smallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox    *spin=new QSpinBox(this);
    QSlider     *slider=new QSlider(Qt::Horizontal,this);

    //把控件添加到布局中
    QHBoxLayout *hLayer=new QHBoxLayout(this);
    hLayer->addWidget(slider);
    hLayer->addWidget(spin);

    connect(spin,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
    slider,&QSlider::setValue);

    connect(slider,&QSlider::valueChanged,spin,&QSpinBox::setValue);
}

smallWidget::~smallWidget()
{

}

