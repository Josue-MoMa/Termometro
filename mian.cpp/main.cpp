#include "termometrov.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TermometroV w;
    w.show();
    return a.exec();
}
