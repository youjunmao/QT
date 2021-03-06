#include "mainwindow.h"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,600);
    QMenuBar    *mBar=menuBar();
    setMenuBar(mBar);
    QMenu       *menu=mBar->addMenu("对话框");
    QAction     *p1=menu->addAction("模态对话框");
    connect(p1,QAction::triggered,[](){
        QDialog dlg;
        dlg.exec();
        qDebug()<<"helloWorld";
    });

    QAction     *p2=menu->addAction("非模态对话框");
    connect(p2,&QAction::triggered,[](){
        QDialog *p=new QDialog;
        p->setAttribute(Qt::WA_DeleteOnClose);
        p->show();
    });

    QAction     *p3=menu->addAction("关于对话框");
    connect(p3,&QAction::triggered,[this](){
        QMessageBox::about(this,"about","关于qt");
    });

    QAction     *p4=menu->addAction("问题对话框");
    connect(p4,&QAction::triggered,[this](){

        int ret=QMessageBox::question(this,"question","Are you Ok?");
        if(ret==QMessageBox::Ok)
        {
            qDebug()<<"Ok";
        }
        else
        {
            qDebug()<<"cancel";
        }
    });

    QAction     *p5=menu->addAction("文件对话框");
    connect(p5,&QAction::triggered,[this](){
        QString path=QFileDialog::getOpenFileName(this,
                                                  "open",
                                                  "../../",
                                                  "souce(*.cpp *h);;"
                                                  "Text(*.txt);;"
                                                  "all(*.*)");
        qDebug()<<path;
    });
}

MainWindow::~MainWindow()
{

}
