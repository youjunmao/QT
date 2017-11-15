#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();

private:
    QTimer  *myTimer;
    Ui::Widget *ui;
};

#endif // WIDGET_H
