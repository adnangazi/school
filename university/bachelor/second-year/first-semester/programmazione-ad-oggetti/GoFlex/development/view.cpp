#include "view.h"
#include "controller.h"

View::View(QWidget * parent) : QWidget(parent), mainLayout(new QVBoxLayout), menus(new Menus(mainLayout)), screen(new Screen(mainLayout)), dialog(new Dialog()) {
    setLayout(mainLayout);
    menus->createMenus();
    screen->createScreen();
}

View::~View() {
    delete dialog;
    delete screen;
    delete menus;
}

void View::showCreateCardioDialog(Controller * const c) {
    dialog->createShowCreateCardioDialog(this);
    connect(static_cast<QPushButton*>(dialog->getCrea()), SIGNAL(clicked()), c, SLOT(createCardio()));
}

void View::showCreateSollevamentoPesiDialog(Controller * const c) {
    dialog->createShowCreateSollevamentoPesiDialog(this);
    connect(static_cast<QPushButton*>(dialog->getCrea()), SIGNAL(clicked()), c, SLOT(createSollevamentoPesi()));
}

void View::showCreateCrossFitDialog(Controller * const c) {
    dialog->createShowCreateCrossFitDialog(this);
    connect(static_cast<QPushButton*>(dialog->getCrea()), SIGNAL(clicked()), c, SLOT(createCrossFit()));
}

void View::showCreateRiposoPassivoDialog(Controller * const c) {
    dialog->createShowCreateRiposoPassivoDialog(this);
    connect(static_cast<QPushButton*>(dialog->getCrea()), SIGNAL(clicked()), c, SLOT(createRiposoPassivo()));
}

void View::showCreateRiposoAttivoCardioDialog(Controller * const c) {
    dialog->createShowCreateRiposoAttivoCardioDialog(this);
    connect(static_cast<QPushButton*>(dialog->getCrea()), SIGNAL(clicked()), c, SLOT(createRiposoAttivoCardio()));
}

void View::showCreateRiposoAttivoSollevamentoPesiDialog(Controller * const c) {
    dialog->createShowCreateRiposoAttivoSollevamentoPesiDialog(this);
    connect(static_cast<QPushButton*>(dialog->getCrea()), SIGNAL(clicked()), c, SLOT(createRiposoAttivoSollevamentoPesi()));
}

void View::showCreateRiposoAttivoCrossFitDialog(Controller * const c) {
    dialog->createShowCreateRiposoAttivoCrossFitDialog(this);
    connect(static_cast<QPushButton*>(dialog->getCrea()), SIGNAL(clicked()), c, SLOT(createRiposoAttivoCrossFit()));
}

void View::showMessageDialog(const string & message) {
    dialog->createShowMessageDialog(this, message);
}

uint View::showGetNumberDialog(const string & tipoDialog) {
    return dialog->createShowGetNumberDialog(this, tipoDialog);
}

void View::setController(Controller * const c) {
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

Screen * View::getScreen() {
    return screen;
}
