#include <QApplication>
#include <typeinfo>
#include "crossfit.h"
#include "deepptr.h"
#include "mainwindow.h"
#include "multiesercizio.h"
#include "riposoattivo.h"
#include "riposopassivo.h"

using namespace std;

int main(int argc, char * argv[]) {
    cout << argc << " " << argv << endl;
    cout << "Inizio programma ... " << endl;

    Cardio * c = new Cardio("corsa", "descrizione corsa", 3, Orario(0, 10), 6);

    RiposoAttivo * a = new RiposoAttivo("istruzione", c);
    RiposoAttivo * b = new RiposoAttivo("istruzione", c);

    if (*a == *b) cout << "Bella" << endl;

    cout << "Fine programma ... " << endl;
    return 0;
}
