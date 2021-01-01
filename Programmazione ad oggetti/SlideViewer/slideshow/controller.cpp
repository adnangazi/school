#include "controller.h"

#include <iostream>

Controller::Controller(QObject* parent)
		: QObject(parent), autoMode(false), timer(new QTimer) {
	connect(timer, SIGNAL(timeout()), this, SLOT(next()));
}

Controller::~Controller() { delete timer; }

void Controller::setModel(Model* m) { model = m; }

void Controller::setView(SlidesViewer* v) { view = v; }

void Controller::setAutoMode(bool mode) {
	if (autoMode != mode) {
		autoMode = mode;
		if (mode) {
			timer->start(2000);
		} else {
			timer->stop();
		}
	}
}

void Controller::next() const {
	model->nextSlide();
	showSlide();
}

void Controller::previous() const {
	model->previousSlide();
	showSlide();
}

void Controller::begin() const {
	model->restartSlideShow();
	showSlide();
}

void Controller::end() const {
	model->endSlideShow();
	showSlide();
}

void Controller::showSlide() const {
	try {
		view->showSlide(model->getSlide(), model->getCurrent() + 1,
										model->getSlideShowSize());
	} catch (std::out_of_range exc) {
		view->showSlide(0, 0, 0);
	}
}

void Controller::add() const {
	try {
		QString path = view->showAddDialog();
		model->addNewSlide(path.toStdString());
	} catch (std::runtime_error exc) {
		view->showWarning(exc.what());
	}
	begin();
}

void Controller::remove() const {
	try {
		u_int index = view->showRemoveDialog();
		model->removeSlide(index - 1);
	} catch (std::runtime_error exc) {
		view->showWarning(exc.what());
	}
	begin();
}

void Controller::merge() const {
	try {
		std::pair<u_int, u_int> indexes = view->showMergeDialog();
		model->mergeSlides(indexes.first - 1, indexes.second - 1);
	} catch (std::runtime_error exc) {
		view->showWarning(exc.what());
	}
	begin();
}

void Controller::autoplay() { setAutoMode(!autoMode); }
