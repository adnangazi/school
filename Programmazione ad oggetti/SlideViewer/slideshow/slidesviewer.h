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
#include <QInputDialog>
#include <QFileDialog>

#include <utility>

#include<MultiSlide.h>
#include<MonoSlide.h>
#include<Slide.h>
#include"slidescreen.h"

class Controller;

class SlidesViewer : public QWidget {
	Q_OBJECT
 private:

	Controller* controller;

	SlideScreen* screen;

	QMenu* file;
	QMenu* riproduzione;
	QMenu* slide;

	QPushButton* startButton;
	QPushButton* prevButton;
	QPushButton* nextButton;
	QPushButton* endButton;

	QPushButton* autoButton;

	void addMenus(QVBoxLayout* mainLayout);
	void addScreen(QVBoxLayout* mainLayout);

	void addControls(QVBoxLayout* mainLayout);

public:
	explicit SlidesViewer(QWidget *parent = nullptr);

	void setController(Controller* c);

	void showWarning(const QString& message);

	QString showAddDialog();
	int showRemoveDialog();
	std::pair<int,int> showMergeDialog();

	void showSlide(Slide* slide,u_int current, u_int limit);
};

#endif  // SLIDESVIEWER_H
