#include "esp2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Esp2 w;
    w.show(); // wywlanie akcji
    return a.exec();
}
