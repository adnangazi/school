#include "view.h"
#include "controller.h"
#include "model.h"
#include <QApplication>

int main(int argc, char * argv[]) {
    QApplication a(argc, argv);
    View w;
    Controller c;
    Model m;



    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);
    w.show();
    return a.exec();
}
