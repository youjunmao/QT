#ifndef WIDGET_H
#define WIDGET_H
#include<QTextEdit>
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
private slots:
    void setClipboardContent();
    void getClipboardContent();
private:
    QTextEdit *editor;
    Ui::Widget *ui;
};

#endif // WIDGET_H
