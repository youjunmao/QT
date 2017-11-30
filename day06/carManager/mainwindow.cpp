#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCar_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->car);
    ui->titleLabel->setText("车辆管理");
}

void MainWindow::on_actionCalc_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->calc);
    ui->titleLabel->setText("销售统计");
}
