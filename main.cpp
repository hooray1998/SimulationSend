#include "widget.h"
#include <QApplication>
#include <time.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.showLoginWidget();

    return a.exec();
}
