#include "FZZLautoscript.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FZZLautoscript w;
    w.show();
    return a.exec();
}
