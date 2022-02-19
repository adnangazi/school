#include "slidesviewer.h"

#include "controller.h"

void SlidesViewer::addMenus(QVBoxLayout* mainLayout) {
	QMenuBar* menuBar = new QMenuBar(this);

	file = new QMenu("File", menuBar);
	riproduzione = new QMenu("Riproduzione", menuBar);
	slide = new QMenu("Slide", menuBar);

	menuBar->addMenu(file);
	menuBar->addMenu(riproduzione);
	menuBar->addMenu(slide);

	// Menù "File"
	file->addAction(new QAction("Chiudi", file));

	// Menù "Riproduzione"
	riproduzione->addAction(new QAction("Inizio", riproduzione));
	riproduzione->addAction(new QAction("Precedente", riproduzione));
	riproduzione->addAction(new QAction("Successiva", riproduzione));
	riproduzione->addAction(new QAction("Fine", riproduzione));
	riproduzione->addAction(new QAction("Autoriproduzione On/Off", riproduzione));

	// Menù "Slide"
	slide->addAction(new QAction("Aggiungi slide", slide));
	slide->addAction(new QAction("Rimuovi slide", slide));
	slide->addAction(new QAction("Unisci slide", slide));

	connect(file->actions()[0], SIGNAL(triggered()), this, SLOT(close()));

	mainLayout->addWidget(menuBar);
}

void SlidesViewer::addScreen(QVBoxLayout* mainLayout) {
	screen = new SlideScreen(this);
	mainLayout->addWidget(screen);
}

void SlidesViewer::addControls(QVBoxLayout* mainLayout) {
	QHBoxLayout* controlsLayout = new QHBoxLayout;

	QHBoxLayout* playLayout = new QHBoxLayout;

	startButton = new QPushButton("Inizio");
	prevButton = new QPushButton("Precedente");
	nextButton = new QPushButton("Successiva");
	endButton = new QPushButton("Fine");

	playLayout->addWidget(startButton);
	playLayout->addWidget(prevButton);
	playLayout->addWidget(nextButton);
	playLayout->addWidget(endButton);
	playLayout->setSpacing(5);
	playLayout->setContentsMargins(20, 0, 20, 0);

	controlsLayout->addLayout(playLayout);

	autoButton = new QPushButton("AUTO");
	controlsLayout->addWidget(autoButton);

	controlsLayout->setSpacing(150);
	controlsLayout->setContentsMargins(150, 20, 150, 20);

	mainLayout->addLayout(controlsLayout);
}

SlidesViewer::SlidesViewer(QWidget* parent) : QWidget(parent) {
	QVBoxLayout* mainLayout = new QVBoxLayout;

	addMenus(mainLayout);

	addScreen(mainLayout);

	addControls(mainLayout);

	mainLayout->setSpacing(0);
	setLayout(mainLayout);
	resize(QSize(1024, 720));
}

void SlidesViewer::setController(Controller *c){
	controller = c;

	connect(riproduzione->actions()[0], SIGNAL(triggered()), controller,
					SLOT(begin()));
	connect(riproduzione->actions()[1], SIGNAL(triggered()), controller,
					SLOT(previous()));
	connect(riproduzione->actions()[2], SIGNAL(triggered()), controller,
					SLOT(next()));
	connect(riproduzione->actions()[3], SIGNAL(triggered()), controller,
					SLOT(end()));
	connect(riproduzione->actions()[4], SIGNAL(triggered()), controller,
					SLOT(autoplay()));

	connect(slide->actions()[0], SIGNAL(triggered()), controller, SLOT(add()));
	connect(slide->actions()[1], SIGNAL(triggered()), controller, SLOT(remove()));
	connect(slide->actions()[2], SIGNAL(triggered()), controller, SLOT(merge()));

	connect(startButton, SIGNAL(clicked()), controller, SLOT(begin()));
	connect(prevButton, SIGNAL(clicked()), controller, SLOT(previous()));
	connect(nextButton, SIGNAL(clicked()), controller, SLOT(next()));
	connect(endButton, SIGNAL(clicked()), controller, SLOT(end()));
	connect(autoButton, SIGNAL(clicked()), controller, SLOT(autoplay()));
}

void SlidesViewer::showWarning(const QString& message) {
	QDialog* dialog = new QDialog(this);

	dialog->setLayout(new QHBoxLayout);
	dialog->layout()->addWidget(new QLabel(message, dialog));
	dialog->layout()->setAlignment(Qt::AlignCenter);
	dialog->setMinimumWidth(120);
	dialog->setMaximumWidth(500);

	dialog->show();
}

QString SlidesViewer::showAddDialog() {
	QString fileName = QFileDialog::getOpenFileName(
			this, tr("Apri il file"), "/home", tr("Immagini (*.png *.jpg)"));

	if (fileName == "")
		throw std::runtime_error("Nessun file scelto: aggiunta annullata");

	return fileName;
}

int SlidesViewer::showRemoveDialog() {
	bool ok = false;
	int remove =
			QInputDialog::getInt(this, tr("Rimuovi slides"),
													 "Indice della slide: ", 1, 1, 2147483647, 1, &ok);
	if (!ok)
		throw std::runtime_error("Nessuna slide scelta: rimozione annullata");

	return remove;
}

std::pair<int, int> SlidesViewer::showMergeDialog() {
	bool ok1 = false, ok2 = false;
	int first = QInputDialog::getInt(this, tr("Componi slides"),
																	 "Indice della prima slide:", 1, 1,
																	 2147483647, 1, &ok1);
	int second = QInputDialog::getInt(this, tr("Componi slides"),
																		"Indice della seconda slide: ", 1, 1,
																		2147483647, 1, &ok2);
	if (!ok1 || !ok2)
		throw std::runtime_error(
				"Non sono stati scelti due indici: unione annullata");

	return {first, second};
}

void SlidesViewer::showSlide(Slide* slide, u_int current, u_int limit) {
	screen->showSlide(slide);
	screen->updateProgressBar(current,limit);
}
