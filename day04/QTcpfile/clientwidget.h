#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include<QFile>
#include<QTcpSocket>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();

private slots:
    void on_pushButton_clicked();

private:
    QFile   file;
    bool    isStart;
    QString fileName;
    qint16  fileSize;
    qint16  recvSize;
    QTcpSocket  *tcpSocket;
    Ui::ClientWidget *ui;
};

#endif // CLIENTWIDGET_H
