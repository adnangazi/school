#include <QApplication>
#include "vista.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Vista w;
    w.show();
    return a.exec();
}
