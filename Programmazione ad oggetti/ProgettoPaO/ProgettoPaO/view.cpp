#include "view.h"
#include "controller.h"

View::View(QWidget * parent) : QWidget(parent) {
    QVBoxLayout * mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    menus = new Menus(mainLayout);
    screen = new Screen(mainLayout);

    menus->createMenus();
    screen->createScreen();
}

View::~View() {
    delete menus;
    delete screen;
}

QWidget ** View::showCreateCardioDialog(Controller * c) {
    QWidget ** temp = dialog->createShowCreateCardioDialog(this);
    connect(static_cast<QPushButton*>(temp[7]), SIGNAL(clicked()), c, SLOT(createCardio()));
    return temp;
}

QWidget ** View::showCreateSollevamentoPesiDialog(Controller * c) {
    QWidget ** temp = dialog->createShowCreateSollevamentoPesiDialog(this);
    connect(static_cast<QPushButton*>(temp[6]), SIGNAL(clicked()), c, SLOT(createSollevamentoPesi()));
    return temp;
}

QWidget ** View::showCreateCrossFitDialog(Controller * c) {
    QWidget ** temp = dialog->createShowCreateCrossFitDialog(this);
    connect(static_cast<QPushButton*>(temp[8]), SIGNAL(clicked()), c, SLOT(createCrossFit()));
    return temp;
}

QWidget ** View::showCreateRiposoPassivoDialog(Controller * c) {
    QWidget ** temp = dialog->createShowCreateRiposoPassivoDialog(this);
    connect(static_cast<QPushButton*>(temp[6]), SIGNAL(clicked()), c, SLOT(createRiposoPassivo()));
    return temp;
}

QWidget ** View::showCreateRiposoAttivoCardioDialog(Controller * c) {
    QWidget ** temp = dialog->createShowCreateRiposoAttivoCardioDialog(this);
    connect(static_cast<QPushButton*>(temp[8]), SIGNAL(clicked()), c, SLOT(createRiposoAttivoCardio()));
    return temp;
}

QWidget ** View::showCreateRiposoAttivoSollevamentoPesiDialog(Controller * c) {
    QWidget ** temp = dialog->createShowCreateRiposoAttivoSollevamentoPesiDialog(this);
    connect(static_cast<QPushButton*>(temp[7]), SIGNAL(clicked()), c, SLOT(createRiposoAttivoSollevamentoPesi()));
    return temp;
}

QWidget ** View::showCreateRiposoAttivoCrossFitDialog(Controller * c) {
    QWidget ** temp = dialog->createShowCreateRiposoAttivoCrossFitDialog(this);
    connect(static_cast<QPushButton*>(temp[9]), SIGNAL(clicked()), c, SLOT(createRiposoAttivoCrossFit()));
    return temp;
}

void View::showMessageDialog(const string & message) {
    dialog->createShowMessageDialog(this, message);
}

int View::showGetNumberDialog(const string & tipoDialog) {
    return dialog->createShowGetNumberDialog(this, tipoDialog);
}

void View::setController(Controller * c) {
    controller = c;

    connect(menus->getAggiungiEsercizio()->actions()[0], SIGNAL(triggered()), controller, SLOT(addCardio()));
    connect(menus->getAggiungiEsercizio()->actions()[1], SIGNAL(triggered()), controller, SLOT(addSollevamentoPesi()));
    connect(menus->getAggiungiEsercizio()->actions()[2], SIGNAL(triggered()), controller, SLOT(addCrossFit()));
    connect(menus->getAggiungiEsercizio()->actions()[3], SIGNAL(triggered()), controller, SLOT(addRiposoPassivo()));

    connect(menus->getAggiungiRiposoAttivo()->actions()[0], SIGNAL(triggered()), controller, SLOT(addRiposoAttivoCardio()));
    connect(menus->getAggiungiRiposoAttivo()->actions()[1], SIGNAL(triggered()), controller, SLOT(addRiposoAttivoSollevamentoPesi()));
    connect(menus->getAggiungiRiposoAttivo()->actions()[2], SIGNAL(triggered()), controller, SLOT(addRiposoAttivoCrossFit()));

    connect(menus->getCambiaEsercizio()->actions()[0], SIGNAL(triggered()), controller, SLOT(setCardio()));
    connect(menus->getCambiaEsercizio()->actions()[1], SIGNAL(triggered()), controller, SLOT(setSollevamentoPesi()));
    connect(menus->getCambiaEsercizio()->actions()[2], SIGNAL(triggered()), controller, SLOT(setCrossFit()));
    connect(menus->getCambiaEsercizio()->actions()[3], SIGNAL(triggered()), controller, SLOT(setRiposoPassivo()));

    connect(menus->getCambiaRiposoAttivo()->actions()[0], SIGNAL(triggered()), controller, SLOT(setRiposoAttivoCardio()));
    connect(menus->getCambiaRiposoAttivo()->actions()[1], SIGNAL(triggered()), controller, SLOT(setRiposoAttivoSollevamentoPesi()));
    connect(menus->getCambiaRiposoAttivo()->actions()[2], SIGNAL(triggered()), controller, SLOT(setRiposoAttivoCrossFit()));

    connect(menus->getControllerAllenamento()->actions()[2], SIGNAL(triggered()), controller, SLOT(remove()));

    connect(menus->getAiuto()->actions()[0], SIGNAL(triggered()), controller, SLOT(whatIsMET()));
    connect(menus->getAiuto()->actions()[1], SIGNAL(triggered()), controller, SLOT(whatIsCrossFit()));
    connect(menus->getAiuto()->actions()[2], SIGNAL(triggered()), controller, SLOT(whatIsRiposoAttivo()));

    connect(screen->getStart(), SIGNAL(clicked()), controller, SLOT(goToStart()));
    connect(screen->getPrevious(), SIGNAL(clicked()), controller, SLOT(previous()));
    connect(screen->getNext(), SIGNAL(clicked()), controller, SLOT(next()));
    connect(screen->getEnd(), SIGNAL(clicked()), controller, SLOT(goToEnd()));
}

Dialog * View::getDialog() {
    return dialog;
}

Menus * View::getMenus() {
    return menus;
}

Screen * View::getScreen() {
    return screen;
}
