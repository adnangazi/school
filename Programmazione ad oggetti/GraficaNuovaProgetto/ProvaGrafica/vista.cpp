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

void Vista::setController(Controller * c) {
    controller = c;

    connect(menus->getAggiungiEsercizio()->actions()[0], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getAggiungiEsercizio()->actions()[1], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getAggiungiEsercizio()->actions()[2], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getAggiungiEsercizio()->actions()[3], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));

    connect(menus->getAggiungiRiposoAttivo()->actions()[0], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getAggiungiRiposoAttivo()->actions()[1], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getAggiungiRiposoAttivo()->actions()[2], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));

    connect(menus->getCambiaEsercizio()->actions()[0], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getCambiaEsercizio()->actions()[1], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getCambiaEsercizio()->actions()[2], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getCambiaEsercizio()->actions()[3], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));

    connect(menus->getCambiaRiposoAttivo()->actions()[0], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getCambiaRiposoAttivo()->actions()[1], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getCambiaRiposoAttivo()->actions()[2], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));

    connect(menus->getControllerAllenamento()->actions()[0], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));
    connect(menus->getControllerAllenamento()->actions()[1], SIGNAL(triggered()), controller, SLOT(controllerAllenamento(0)));

    connect(menus->getAiuto()->actions()[0], SIGNAL(triggered()), controller, SLOT(aiuto(0)));
    connect(menus->getAiuto()->actions()[1], SIGNAL(triggered()), controller, SLOT(aiuto(1)));
    connect(menus->getAiuto()->actions()[2], SIGNAL(triggered()), controller, SLOT(aiuto(2)));

    connect(screen->getStart(), SIGNAL(clicked()), controller, SLOT(begin()));
    connect(screen->getPrevious(), SIGNAL(clicked()), controller, SLOT(previous()));
    connect(screen->getNext(), SIGNAL(clicked()), controller, SLOT(next()));
    connect(screen->getEnd(), SIGNAL(clicked()), controller, SLOT(end()));
}



















