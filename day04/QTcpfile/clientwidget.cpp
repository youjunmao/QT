#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QDebug>
#include<QMessageBox>
#include<QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    isStart=true;
    tcpSocket=new QTcpSocket(this);
    setWindowTitle("客户端");
    move(width()/2,height());
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=](){
        //取出接受的内容
        QByteArray buf=tcpSocket->readAll();
        if(isStart)
        {
            //接受头部信息,文件名##文件大小
            isStart=false;
            //解析头部信息//初始化
            fileName=QString(buf).section("##",0,0);
            fileSize=QString(buf).section("##",1,1).toInt();
            recvSize=0;
            //打开文件
            file.setFileName(fileName);
            bool isOk=file.open(QIODevice::WriteOnly);
            if(false==isOk)
            {
                tcpSocket->disconnectFromHost();
                tcpSocket->close();
                return;
            }

            QString str=QString("接受的文件，[%1,%2kb]").arg(fileName).arg(fileSize);
            QMessageBox::information(this,"文件信息",str);

            //设置进度条
            ui->progressBar->setMinimum(0);
            ui->progressBar->setMaximum(fileSize/1024);
            ui->progressBar->setValue(0);
        }
        else
        {
            //文件信息
            qint64 len=file.write(buf);
            if(len>0)
            {
                recvSize+=len;
            }
            //更新进度条
            ui->progressBar->setValue(fileSize/1024);
            if(recvSize==fileSize)
            {
                file.close();
                QMessageBox::information(this,"完成","文件接受完成");

                tcpSocket->disconnectFromHost();
                tcpSocket->close();
            }
        }
    });

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_pushButton_clicked()
{
    quint16 port=ui->portText->text().toInt();
    QString ip=ui->ipText->text();

    tcpSocket->connectToHost(QHostAddress(ip),port);
}
