#include "model.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[]) {
    cout << argc << " " << *argv << endl;
    cout << "Inizio programma" << endl;

    Model model;
    model.addCardio("Cardio", "Descrizione cardio", 3, Orario(1, 1, 1), 5);

    cout << "Fine programma" << endl;
}
