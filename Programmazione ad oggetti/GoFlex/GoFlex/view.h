#ifndef VIEW_H
#define VIEW_H

#include "dialog.h"
#include "menus.h"
#include "screen.h"

class Controller;

class View : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout * mainLayout;
    Menus * menus;
    Screen * screen;
    Dialog * dialog;
    Controller * controller;

public:
    //costruttori e distruttori
    explicit View(QWidget * parent = nullptr);
    ~View();

    //metodi della classe
    void showCreateCardioDialog(Controller * const c);
    void showCreateSollevamentoPesiDialog(Controller * const c);
    void showCreateCrossFitDialog(Controller * const c);
    void showCreateRiposoPassivoDialog(Controller * const c);
    void showCreateRiposoAttivoCardioDialog(Controller * const c);
    void showCreateRiposoAttivoSollevamentoPesiDialog(Controller * const c);
    void showCreateRiposoAttivoCrossFitDialog(Controller * const c);

    void showMessageDialog(const string & message);
    uint showGetNumberDialog(const string & tipoDialog);
    void setController(Controller * const c);

    Dialog * getDialog();
    Screen * getScreen();
};

#endif // VIEW_H
