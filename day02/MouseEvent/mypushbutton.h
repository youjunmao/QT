#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(QWidget *parent = 0);
    ~myPushButton();
protected:
    void mousePressEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
