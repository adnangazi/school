#ifndef SLIDESVIEWER_H
#define SLIDESVIEWER_H

#include <QAction>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QDialog>
#include <utility>
#include <QFileDialog>
#include <QInputDialog>
#include <iostream>
#include "slide.h"
#include "monoslide.h"
#include "multislide.h"

class SlideViewer : public QWidget {
    Q_OBJECT
 private:
    QFrame * image;
    void clearLayout(QLayout * ) const;
    void showSlideRecursive(Slide * slide, QBoxLayout * layout, double scale);

    void addMenus(QVBoxLayout* mainLayout);
    void addScreen(QVBoxLayout* mainLayout);
    void addControls(QVBoxLayout* mainLayout);

public:
    explicit SlideViewer(QWidget *parent = nullptr);
    void showWarning(const QString & comment);
    QString showAddDialog();
    int showRemoveDialog();
    std::pair<int, int> showMergeDialog();
    void showSlide(Slide * slide);

 signals:
};

#endif  // SLIDESVIEWER_H
