#include "slideviewer.h"
#include <QApplication>

int main(int argc, char * argv[]) {
    QApplication a(argc, argv);

    SlideViewer b;
    b.show();

    return a.exec();
}
