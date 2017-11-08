#ifndef CLICENTWIDGET_H
#define CLICENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class ClicentWidget;
}

class ClicentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClicentWidget(QWidget *parent = 0);
    ~ClicentWidget();

private slots:
    void on_ButtonConnect_clicked();

    void on_sendButton_clicked();

    void on_closeButton_clicked();

private:
    QTcpSocket          *tcpSocket;
    Ui::ClicentWidget   *ui;
};

#endif // CLICENTWIDGET_H
