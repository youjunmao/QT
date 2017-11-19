#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#include"mythread.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void backTimeout();
    void backDone();
    void backDestoryThread();
private slots:
    void on_pushButton_clicked();

private:
    myThread    thread;
    QTimer      timer;
    Ui::Widget  *ui;
};

#endif // WIDGET_H
