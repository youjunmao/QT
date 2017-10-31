#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    //窗口绘图事件
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_clicked();

private:
    int x;
    Ui::Widget *ui;
};

#endif // WIDGET_H
