#ifndef VISTA_H
#define VISTA_H

#include "dialog.h"
#include "menus.h"
#include "screen.h"

class Vista : public QWidget {
    Q_OBJECT
private:
    Dialog * dialog;
    Menus * menus;
    Screen * screen;

public:
    explicit Vista(QWidget * parent = nullptr);
    ~Vista();

    QWidget ** showCreateDialog(const int i);
    void showMessageDialog(const string & message);
    int showGetNumberDialog(const string & tipoDialog);
};

#endif // VISTA_H
