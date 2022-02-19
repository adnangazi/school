#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>

#include "slidesviewer.h"
#include "Model.h"


class Controller : public QObject
{
	Q_OBJECT
private:
	bool autoMode;
	QTimer* timer;

	SlidesViewer* view;
	Model* model;
	void showSlide() const;

public:
	explicit Controller(QObject *parent = nullptr);
	~Controller();

	void setModel(Model* m);
	void setView(SlidesViewer* v);
	void setAutoMode(bool mode);

public slots:
	void next() const;
	void previous() const;
	void begin() const;
	void end() const;

	void add() const;
	void remove() const;
	void merge() const;

	void autoplay();
};

#endif // CONTROLLER_H
