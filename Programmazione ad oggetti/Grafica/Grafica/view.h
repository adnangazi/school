#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QFrame>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QInputDialog>
#include <iostream>
#include <string>
#include "viewcreator.h"
#include "menus.h"
#include "screen.h"
#include "dialog.h"

using std::string;

class View : public QWidget {
    Q_OBJECT
private:


    void addMenus(QVBoxLayout * const mainLayout);
    void addScreens(QVBoxLayout * const mainLayout);

public:
    explicit View(QWidget * parent = nullptr);

    void showCreateCardioDialog();
    void showCreateSollevamentoPesiDialog();
    void showCreateCrossFitDialog();
    void showCreateRiposoPassivoDialog();
    void showCreateRiposoAttivoDialog();
    void showMessageDialog(const string & message);
    int showGetNumberDialog(const string & tipoDialog);

signals:
};

#endif // VIEW_H
