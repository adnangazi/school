#include "vista.h"

Vista::Vista(QWidget * parent) : QWidget(parent) {
    QVBoxLayout * mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    resize(QSize(750, 500));
    setMaximumSize(QSize(1500, 1000));

    menus = new Menus(mainLayout);
    screen = new Screen(mainLayout);

    menus->createMenus();
    screen->createScreen();

    //showCreateDialog(1);

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

void Vista::showCreateDialog(const int i) {
    switch (i) {
    case 1:
        dialog->createShowCreateCardioDialog(this);
        break;
    case 2:
        dialog->createShowCreateSollevamentoPesiDialog(this);
        break;
    case 3:
        dialog->createShowCreateCrossFitDialog(this);
        break;
    case 4:
        dialog->createShowCreateRiposoPassivoDialog(this);
        break;
    case 5:
        dialog->createShowCreateRiposoAttivoDialog(this);
        break;
    }
}

void Vista::showMessageDialog(const string & message) {
    dialog->createShowMessageDialog(this, message);
}

int Vista::showGetNumberDialog(const string & tipoDialog) {
    return dialog->createShowGetNumberDialog(this, tipoDialog);
}
