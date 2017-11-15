#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QDebug>
#include<QFileInfo>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->selectedBtn->setEnabled(false);
    ui->sendBtn->setEnabled(false);
    //监听套接字
    tcpServer=new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器端口为：8888");

    connect(tcpServer,&QTcpServer::newConnection,
            [=](){
                tcpSocket=tcpServer->nextPendingConnection();
                //ip,port
                QString ip=tcpSocket->peerAddress().toString();
                quint16  port=tcpSocket->peerPort();

                QString text=QString("[%1,%2],成功连接").arg(ip).arg(port);
                ui->textEdit->setText(text);
                //服务器连接成功，选择上传文件
                ui->selectedBtn->setEnabled(true);

    });

    connect(&timer,&QTimer::timeout,
            [=](){

                timer.stop();

                sendData();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_selectedBtn_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,"open","../");
    if(false==filePath.isEmpty())
    {
        fileName.clear();
        fileSize=0;
        //获取文件信息
        QFileInfo info(filePath);
        fileName=info.fileName();
        fileSize=info.size();

        sendSize=0;
        //只读方式打开
        //指定文件的名字
        file.setFileName(filePath);

        bool isOk=file.open(QIODevice::ReadOnly);

        ui->textEdit->append(filePath);
        ui->sendBtn->setEnabled(true);
        ui->selectedBtn->setEnabled(false);

    }
    else
    {
        qDebug()<<"open file fail!";
    }
}

void Widget::on_sendBtn_clicked()
{
    //先发送头部文件  文件名##文件大小
    QString head=QString("%1##%2").arg(fileName).arg(fileSize);
    //发送头部信息
    qint64 len=tcpSocket->write(head.toUtf8());
    if(len>0)
    {
        //头部信息发送成功
        //发送真正的文件信息
        //防止tcp黏包文件
        //需要通过定时器延时20ms
        timer.start(20);
    }
    else
    {
        file.close();
        ui->sendBtn->setEnabled(false);
        ui->selectedBtn->setEnabled(false);
    }

}

void Widget::sendData()
{
    qint64 len=0;
    do
    {
        //每次发送数据的大小
        char buf[4*1024]={0};
        len=0;
        //往文件中读取数据
        len=file.read(buf,sizeof(buf));
        //发送数据，读多少，发多少
        len=tcpSocket->write(buf,len);
        //发送的数据需要积累
        sendSize+=len;

    }while(len>0);
    //是否发送完毕
    if(sendSize==fileSize)
    {
        ui->textEdit->append("发送完毕");
        file.close();

        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }
}
