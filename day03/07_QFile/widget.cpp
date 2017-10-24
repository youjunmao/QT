#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QFileDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_readButton_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    if(path.isEmpty()==false)
    {
        //文件对象
        QFile file(path);
        //打开文件
        bool isOpen=file.open(QIODevice::ReadOnly);
        if(isOpen==true)
        {
#if 0
            //读文件，默认只识别utf8
            QByteArray _data=file.readAll();
            ui->textEdit->setText(QString(_data));
            ui->textEdit->setText(_data);

#endif
            QByteArray _data;
            while(file.atEnd()==false)
            {
                _data+=file.readLine();
            }
            ui->textEdit->setFontWeight(22);
            ui->textEdit->setText(_data);

        }
        file.close();
    }
}

void Widget::on_writeButton_2_clicked()
{
    QString path=QFileDialog::getSaveFileName(this,"save","../","Txt(*.txt)");
    if(path.isEmpty()==false)
    {
        QFile file;
        file.setFileName(path);
        bool isOpen=file.open(QIODevice::WriteOnly);
        if(isOpen)
        {
            //获取编辑区内容
            QString _data=ui->textEdit->toPlainText();
            //写文件
            //file.write(_data.toUtf8());
            //file.write(_data.toStdString().data());
            file.write(_data.toLocal8Bit());
        }
        file.close();
    }
}
