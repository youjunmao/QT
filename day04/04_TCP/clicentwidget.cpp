#include "clicentwidget.h"
#include "ui_clicentwidget.h"
#include<QHostAddress>
ClicentWidget::ClicentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClicentWidget)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    tcpSocket=NULL;
    tcpSocket=new QTcpSocket(this);

    connect(tcpSocket,&QTcpSocket::connected,
            [=](){
        ui->readEdit->setText("和服务器连接成功");
    });

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=](){
        QString text=tcpSocket->readAll();
        ui->readEdit->append(text);
    });
}

ClicentWidget::~ClicentWidget()
{
    delete ui;
}

void ClicentWidget::on_ButtonConnect_clicked()
{
    //获取服务器端口和ip
    qint16      port=ui->lineEditPort->text().toInt();
    QString     ip=ui->lineEditIp->text();
    //主动和服务器连接
    tcpSocket->connectToHost(QHostAddress(ip),port);
}

void ClicentWidget::on_sendButton_clicked()
{
    QString strText=ui->writeEdit->toPlainText();
    tcpSocket->write(strText.toUtf8().data());
}

void ClicentWidget::on_closeButton_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
