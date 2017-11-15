#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QFile>
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
private:
    void sendData();
private slots:
    void on_selectedBtn_clicked();

    void on_sendBtn_clicked();

private:
    QFile   file;
    QTimer  timer;
    QString fileName;
    qint16  fileSize;
    qint16  sendSize;
    QTcpServer  *tcpServer;
    QTcpSocket  *tcpSocket;
    Ui::Widget *ui;
};

#endif // WIDGET_H
