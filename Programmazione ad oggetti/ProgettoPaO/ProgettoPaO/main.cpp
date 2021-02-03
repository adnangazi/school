#include "crossfit.h"
#include "riposopassivo.h"
#include "riposoattivo.h"
#include "deepptr.h"
#include "dlist.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[]) {
    cout << argc << " " << *argv << endl;
    cout << "Inizio programma" << endl;

    DList<DeepPtr<Esercizio>> dl;
    dl.pushBack(DeepPtr<Esercizio>(new Cardio("Cardio1", "Descrizione Cardio1", 3, Orario(0, 10), 6)));
    dl.pushBack(DeepPtr<Esercizio>(new Cardio("Cardio2", "Descrizione Cardio2", 4, Orario(0, 11), 7)));
    dl.pushFront(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi1", "Descrizione SollevamentoPesi1", 3, 15, 10, 3)));
    dl.pushFront(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi2", "Descrizione SollevamentoPesi1", 3, 20, 12, 4)));
    dl.pushBack(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi3", "Descrizione SollevamentoPesi3", 3, 20, 12, 4)));

    DList<DeepPtr<Esercizio>> dl2(dl);

    //dl2.set(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi3", "Descrizione SollevamentoPesi3", 3, 20, 12, 4)), 4);

    if (dl2 == dl) {} else cout << "1" << endl;
    if (dl2 != dl) cout << "2" << endl;
    if (dl2.deepCheckEquals(dl)) cout << "3" << endl;
    if (dl2.deepCheckNotEquals(dl)) {} else cout << "4" << endl;

    dl2.set(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi31", "Descrizione SollevamentoPesi3", 3, 20, 12, 4)), 4);
    cout << endl << endl;

    if (dl2 == dl) {} else cout << "1" << endl;
    if (dl2 != dl) cout << "2" << endl;
    if (dl2.deepCheckEquals(dl)) {} else cout << "3" << endl;
    if (dl2.deepCheckNotEquals(dl)) cout << "4" << endl;

    cout << "Fine programma" << endl;
}
