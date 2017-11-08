#ifndef WIDGETSERVER_H
#define WIDGETSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
namespace Ui {
class WidgetServer;
}

class WidgetServer : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetServer(QWidget *parent = 0);
    ~WidgetServer();
    void    backReadyRead();
    void    backNewConnection();
private slots:
    void on_send_clicked();
    void on_btnClose_clicked();

private:
    QTcpServer          *tcpServer;//监听套接字
    QTcpSocket          *tcpSocket;//通信套接字
    Ui::WidgetServer    *ui;
};

#endif // WIDGETSERVER_H
