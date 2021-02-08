#include "vista.h"

Vista::Vista(QWidget * parent) : QWidget(parent) {
    QVBoxLayout * mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    menus = new Menus(mainLayout);
    screen = new Screen(mainLayout);

    menus->createMenus();
    screen->createScreen();

    /*for (int i = 1; i < 6; i++) {
        showCreateDialog(i);
    }
    showMessageDialog("prova prova showMessaggeDialog()");
    showGetNumberDialog("Rimozione");
    */
}

Vista::~Vista() {
    delete menus;
    delete screen;
}

QWidget ** Vista::showCreateDialog(const int i) {
    switch (i) {
    case 1:
        return dialog->createShowCreateCardioDialog(this);
    case 2:
        return dialog->createShowCreateSollevamentoPesiDialog(this);
    case 3:
        return dialog->createShowCreateCrossFitDialog(this);
    case 4:
        return dialog->createShowCreateRiposoPassivoDialog(this);
    case 5:
        return dialog->createShowCreateRiposoAttivoDialog(this);
    }
    return nullptr;
}

void Vista::showMessageDialog(const string & message) {
    dialog->createShowMessageDialog(this, message);
}

int Vista::showGetNumberDialog(const string & tipoDialog) {
    return dialog->createShowGetNumberDialog(this, tipoDialog);
}
