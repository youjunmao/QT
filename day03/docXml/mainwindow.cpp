#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  "docxml.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DocXml::createXml("../maomao.xml");
}

MainWindow::~MainWindow()
{
    delete ui;
}
