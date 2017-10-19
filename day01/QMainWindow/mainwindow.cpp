#include "mainwindow.h"
#include<QMenuBar>
#include<QMenu>
#include<QDebug>
#include<QToolBar>
#include<QStatusBar>
#include<QLabel>
#include<QTextEdit>
#include<QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,600);
    //菜单栏
    QMenuBar    *mBar=menuBar();
    //添加菜单
    QMenu       *pFile=mBar->addMenu("文件");
    //添加菜单项，添加动作
    QAction     *pNew=pFile->addAction("新建");
    connect(pNew,&QAction::triggered,[](){
           qDebug()<<"新建被按下";
    }
    );
    pFile->addSeparator();//分割线
    QAction*        pOpen=pFile->addAction("打开");
    //工具栏
    QToolBar*       toolBar=addToolBar("toolBar");
    toolBar->addAction(pNew);
    //状态栏
    QStatusBar *sBar=statusBar();
    QLabel     *label=new QLabel();
    label->setText("label");
    sBar->addWidget(label);
    sBar->addPermanentWidget(new QLabel("label2",this));
    //核心控件
    QTextEdit   *textEdit=new QTextEdit(this);
    setCentralWidget(textEdit);
    //浮动窗口
    QDockWidget *dock=new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    QTextEdit   *textEdit1=new QTextEdit(this);
    dock->setWidget(textEdit1);
}

MainWindow::~MainWindow()
{

}
