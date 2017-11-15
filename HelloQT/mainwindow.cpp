#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton btn();
    btn.show();

    connect(btn,&QPushButton::clicked,btn,&QPushButton::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}
