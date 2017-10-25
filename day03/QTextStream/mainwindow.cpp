#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextStream>
#include<QFile>
#include<QDebug>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    writeData();
}
void MainWindow::writeData()
{
    QFile file("../demo.txt");
    bool isOpen=file.open(QIODevice::WriteOnly);
    if(isOpen)
    {
        //创建数据流，和file文件关联
        //往数据流中写数据，相当于往文件中写数据
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream<<QString("主要是帅气")<<250;

        file.close();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../");
    if(false==path.isEmpty())
    {
        QFile file(path);
        bool isOpen=file.open(QIODevice::ReadOnly);
        if(isOpen)
        {

            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            ui->textEdit->setText(stream.readAll());

            file.close();
        }
    }
}
