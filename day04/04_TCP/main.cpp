#include "widgetserver.h"
#include <QApplication>
#include"clicentwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetServer w;
    w.show();

    ClicentWidget w2;
    w2.show();

    return a.exec();
}
