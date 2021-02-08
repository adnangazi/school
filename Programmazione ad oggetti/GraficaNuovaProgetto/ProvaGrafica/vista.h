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

    void showCreateDialog(const int i); // return DList<QWidget*>
    void showMessageDialog(const string & message);
    int showGetNumberDialog(const string & tipoDialog);
};

#endif // VISTA_H
