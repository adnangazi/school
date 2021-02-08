#ifndef MENUS_H
#define MENUS_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>

class Menus : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout * mainLayout;

public:
    Menus(QVBoxLayout * const ml);
    void createMenus();
};

#endif // MENUS_H
