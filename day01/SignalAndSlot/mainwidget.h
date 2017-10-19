#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QDebug>
#include "subwidget.h"
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void dealSub();
    void dealSolt(int,QString);
    void changeWindows();
    void mySlot();
private:
    QPushButton b;
    QPushButton *b2;
    QPushButton b3;
    SubWidget   w;
};

#endif // MAINWIDGET_H
