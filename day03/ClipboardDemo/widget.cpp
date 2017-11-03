#include "widget.h"
#include "ui_widget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QClipboard>
#include<QApplication>
#include<QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *northLayout = new QHBoxLayout;
    QHBoxLayout *southLayout = new QHBoxLayout;

    editor = new QTextEdit;
    QLabel *label = new QLabel;
    label->setText("Text Input: ");
    label->setBuddy(editor);
    QPushButton *copyButton = new QPushButton;
    copyButton->setText("Set Clipboard");
    QPushButton *pasteButton = new QPushButton;
    pasteButton->setText("Get Clipboard");

    northLayout->addWidget(label);
    northLayout->addWidget(editor);
    southLayout->addWidget(copyButton);
    southLayout->addWidget(pasteButton);
    mainLayout->addLayout(northLayout);
    mainLayout->addLayout(southLayout);

    connect(copyButton, SIGNAL(clicked()), this, SLOT(setClipboardContent()));
    connect(pasteButton, SIGNAL(clicked()), this, SLOT(getClipboardContent()));
}
void Widget::setClipboardContent()
{
    QClipboard *board = QApplication::clipboard();
    board->setText(editor->toPlainText());
}

void Widget::getClipboardContent()
{
    QClipboard *board = QApplication::clipboard();
    QString str = board->text();
    QMessageBox::information(NULL, "From clipboard", str);
}
Widget::~Widget()
{
    delete ui;
}
