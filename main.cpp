#include "translate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Translate w;
    w.show();
    w.Init();
    return a.exec();
}
