#include "slidesviewer.h"
#include "controller.h"
#include "Model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
		SlidesViewer w;
		Controller c;
		Model m;

		c.setModel(&m);
		c.setView(&w);
		w.setController(&c);
    w.show();

		return a.exec();
}
