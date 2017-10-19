#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("新按钮");

    ui->lineEdit->setTextMargins(15,0,0,0);

    //ui->lineEdit->setEchoMode(QLineEdit::Password);

    QStringList list;
    list<<"hello"<<"nishi"<<"kkk";

    QCompleter* completer=new QCompleter(list,this);

    ui->lineEdit->setCompleter(completer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
