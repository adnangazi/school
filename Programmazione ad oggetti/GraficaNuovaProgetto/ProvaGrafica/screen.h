#ifndef SCREEN_H
#define SCREEN_H

#include "viewcreator.h"

class Screen : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout * mainLayout;

public:
    Screen(QVBoxLayout * const ml);
    void createScreen();
};

#endif // SCREEN_H
