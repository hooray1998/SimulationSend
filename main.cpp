#include "widget.h"
#include <QApplication>
#include <time.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    puts("sdf");
    Widget w;
    //w.showLoginWidget(false, b);
    w.showLoginWidget();

    return a.exec();
}
