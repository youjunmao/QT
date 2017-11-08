#include "widgetserver.h"
#include "ui_widgetserver.h"

WidgetServer::WidgetServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetServer)
{
    ui->setupUi(this);
    this->move(width()/2,height());
    tcpSocket=NULL;
    this->setWindowTitle("服务器，8888");
    //监听套接字，指定父对象，自动回收
    tcpServer=new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,8888);

    connect(tcpServer,&QTcpServer::newConnection,this,&WidgetServer::backNewConnection);
}

void  WidgetServer::backNewConnection()
{
    //取出建立好连接的套接字
    tcpSocket=tcpServer->nextPendingConnection();
    //获取对方的ip和端口
    QString ip=tcpSocket->peerAddress().toString();
    qint16  port=tcpSocket->peerPort();

    QString temp=QString("[%1,%2],连接成功").arg(ip).arg(port);
    ui->textRead->setText(temp);

    //
    connect(tcpSocket,&QTcpSocket::readyRead,this,&WidgetServer::backReadyRead);
}

void    WidgetServer::backReadyRead()
{
    QByteArray array=tcpSocket->readAll();
    ui->textRead->append(array);
}

WidgetServer::~WidgetServer()
{
    delete ui;
}

void WidgetServer::on_send_clicked()
{
    QString str=ui->textWrite->toPlainText();
    //给客户端发送数据
    if(tcpServer)
        tcpSocket->write(str.toUtf8().data());
}

void WidgetServer::on_btnClose_clicked()
{
    //主动断开与客户端连接
    if(tcpSocket)
    {
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        tcpSocket=NULL;
    }

}
