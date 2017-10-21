#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel{"
                             "color:rgb(0,255,255);"
                             "background:red;"
                             "}");

    ui->label->setStyleSheet("QLabel{"
                             "color:rgb(0,255,255);"
                             "background-color:red;"
                             "border-image:url(:/new/prefix1/IMAGE/timg (3).jpg)"
                             "}");

    ui->label_2->setStyleSheet("QLabel{"
                             "color:rgb(0,255,255);"
                             "background:blue;"
                             "background-image:url(:/new/prefix1/IMAGE/timg.jpg)"
                             "}");

    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border: 2px outset green;"
                                  "border-image:url(:/new/prefix1/IMAGE/timg (2).jpg);"
                                  "}"
                                  "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/IMAGE/timg (1).jpg);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "border-image:url(:/new/prefix1/IMAGE/timg (3).jpg);"
                                  "}"
                                  );
}

Widget::~Widget()
{
    delete ui;
}
