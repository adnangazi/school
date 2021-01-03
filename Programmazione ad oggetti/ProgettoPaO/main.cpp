#include <QApplication>
#include <typeinfo>
#include "crossfit.h"
#include "deepptr.h"
#include "multiesercizio.h"
#include "riposoattivo.h"
#include "riposopassivo.h"
#include "dlist.h"

using namespace std;

int main(int argc, char * argv[]) {
    cout << argc << " " << argv << endl;
    cout << "Inizio programma ... " << endl;

    DList<int> d;
    int * uno = new int(999);
    d.pushBack(uno);
    d.popBack();
    cout << *uno << endl;

    cout << "Fine programma ... " << endl;
    return 0;
}
