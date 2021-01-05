#include "crossfit.h"
#include "riposopassivo.h"
#include "riposoattivo.h"
#include "deepptr.h"
#include "dlist.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << argc << " " << *argv << endl;
    cout << "Inizio programma" << endl;

    DList<DeepPtr<Esercizio>> dl;
    dl.pushBack(DeepPtr<Esercizio>(new Cardio("Cardio1", "Descrizione Cardio1", 3, Orario(0, 10), 6)));
    dl.pushBack(DeepPtr<Esercizio>(new Cardio("Cardio2", "Descrizione Cardio2", 4, Orario(0, 11), 7)));
    dl.pushFront(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi1", "Descrizione SollevamentoPesi1", 3, 15, 10, 3)));
    dl.pushFront(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi2", "Descrizione SollevamentoPesi1", 3, 20, 12, 4)));
    dl.pushBack(DeepPtr<Esercizio>(new SollevamentoPesi("SollevamentoPesi3", "Descrizione SollevamentoPesi3", 3, 20, 12, 4)));

    for (auto it = dl.begin(); it != dl.end(); it++) {
        cout << (*(*it)).getNome() << endl;
    }

    cout << "Fine programma" << endl;
}
