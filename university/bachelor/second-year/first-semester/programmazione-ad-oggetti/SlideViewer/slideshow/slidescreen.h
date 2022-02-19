#ifndef SLIDESCREEN_H
#define SLIDESCREEN_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>

#include "Slide.h"
#include "MultiSlide.h"
#include "MonoSlide.h"

class SlideScreen : public QWidget {
	Q_OBJECT
 private:
	QFrame* image;
	QProgressBar* progressBar;

	void clearLayout(QLayout*) const;
	void showSlideRecursive(Slide* slide, QBoxLayout* layout, double scale);

 public:
	explicit SlideScreen(QWidget* parent = nullptr);

	/**
	 * @brief showSlide			Mostra la slide corrente
	 * @param slide					Puntatore alla Slide da
	 * mostrare
	 */
	void showSlide(Slide* slide);

	/**
	 * @brief updateProgressBar		Aggiorna lo stato della barra di
	 * progresso
	 * @param current							Indice della slide
	 * corrente
	 * @param limit								Numero di slide
	 * massimo
	 */
	void updateProgressBar(u_int current, u_int limit) const;
};

#endif  // SLIDESCREEN_H
