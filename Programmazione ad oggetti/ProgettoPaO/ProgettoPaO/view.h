#ifndef VIEW_H
#define VIEW_H

#include "dialog.h"
#include "menus.h"
#include "screen.h"

class Controller;

class View : public QWidget {
    Q_OBJECT
private:
    Dialog * dialog;
    Menus * menus;
    Screen * screen;

    Controller * controller;

public:
    explicit View(QWidget * parent = nullptr);
    ~View();

    QWidget ** showCreateCardioDialog(Controller * c);
    QWidget ** showCreateSollevamentoPesiDialog(Controller * c);
    QWidget ** showCreateCrossFitDialog(Controller * c);
    QWidget ** showCreateRiposoPassivoDialog(Controller * c);
    QWidget ** showCreateRiposoAttivoCardioDialog(Controller * c);
    QWidget ** showCreateRiposoAttivoSollevamentoPesiDialog(Controller * c);
    QWidget ** showCreateRiposoAttivoCrossFitDialog(Controller * c);

    void showMessageDialog(const string & message);
    int showGetNumberDialog(const string & tipoDialog);
    void setController(Controller * c);

    Dialog * getDialog();
    Menus * getMenus();
    Screen * getScreen();
};

#endif // VIEW_H
