#include<QApplication>
#include<QWidget>
#include<QPushButton>

int main(int argc,char**argv)
{
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle("货换货");

    QPushButton btn;
    btn.setText("ni hao");
    btn.setParent(&w);
    btn.move(200,250);

    QPushButton btn2(&w);
    btn2.setText("hhhh");

    w.show();

    app.exec();
    return 0;
}
