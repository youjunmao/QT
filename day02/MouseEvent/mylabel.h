#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();
protected:
    void mouseMoveEvent(QMouseEvent * me) ;
    void mousePressEvent(QMouseEvent * me) ;
    void mouseReleaseEvent(QMouseEvent * me) ;
signals:

public slots:
};

#endif // MYLABEL_H
