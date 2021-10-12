#include "slidescreen.h"

void SlideScreen::clearLayout(QLayout* layout) const {
	QLayoutItem* item;
	while ((item = layout->takeAt(0))) {
		if (item->layout()) {
			clearLayout(item->layout());
		}
		if (item->widget()) {
			delete item->widget();
		}
		delete item;
	}
}

void SlideScreen::showSlideRecursive(Slide* slide, QBoxLayout* layout,
																		 double scale) {
	MonoSlide* s = dynamic_cast<MonoSlide*>(slide);
	if (s) {
		QLabel* img = new QLabel(this);
		QPixmap pic = QPixmap(QString::fromStdString(s->getPath()));
		img->setPixmap(
				pic.scaled(s->getMaxWidth() * scale, s->getMaxHeight() * scale));
		img->setMaximumSize(
				QSize(s->getMaxWidth() * scale, s->getMaxHeight() * scale));

		img->setContentsMargins(0, 0, 0, 0);

		layout->addWidget(img);
	} else {
		MultiSlide* ms = dynamic_cast<MultiSlide*>(slide);

		QBoxLayout* newLayout;

		if (ms->isDividedHorizontally())
			newLayout = new QHBoxLayout;
		else
			newLayout = new QVBoxLayout;

		layout->addLayout(newLayout);
		newLayout->setSpacing(0);
		newLayout->setContentsMargins(0, 0, 0, 0);

		std::vector<Slide*> slides = ms->getSlides();
		for (Slide* sl : slides)
			showSlideRecursive(sl, newLayout, (scale / slides.size()) * 1.7);
	}
}

SlideScreen::SlideScreen(QWidget* parent) : QWidget(parent) {
	QVBoxLayout* screenLayout = new QVBoxLayout;
	image = new QFrame;

	QHBoxLayout* imageLayout = new QHBoxLayout;
	imageLayout->addWidget(new QLabel(this));

	progressBar = new QProgressBar;
	progressBar->setRange(0, 0);
	progressBar->setValue(0);
	progressBar->setFormat("%v / %m");

	image->setStyleSheet("background-color: rgb(50,50,50)");
	image->setLayout(imageLayout);
	image->layout()->setMargin(0);
	image->layout()->setSpacing(0);
	image->layout()->setAlignment(Qt::AlignCenter);
	image->setMinimumSize(1024, 720);
	image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	screenLayout->addWidget(image);
	screenLayout->addWidget(progressBar);
	screenLayout->setSpacing(0);

	setLayout(screenLayout);

}

void SlideScreen::showSlide(Slide* slide) {
	MultiSlide* s = dynamic_cast<MultiSlide*>(slide);

	clearLayout(image->layout());

	if (s && !s->isDividedHorizontally())
		image->setLayout(new QVBoxLayout);
	else
		image->setLayout(new QHBoxLayout);

	if (slide)
		showSlideRecursive(slide, static_cast<QBoxLayout*>(image->layout()), 1);
	else
		image->layout()->addWidget(new QLabel(this));
}

void SlideScreen::updateProgressBar(u_int current, u_int limit) const {
	progressBar->setRange(0, limit);
	progressBar->setValue(current);
	progressBar->show();
}
