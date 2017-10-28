#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  "docxml.h"
#include<QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DocXml::createXml("../maomao.xml");
    QStringList list;
    list<<"二汽神龙"<<"茂茂佳儿"<<"毕加索"<<"供电局"<<"供电刚刚局";
    DocXml::appendXml("../maomao.xml",list);
    DocXml::readXml("../maomao.xml");
}


MainWindow::~MainWindow()
{
    delete ui;
}
