#ifndef _MODEL_H
#define _MODEL_H

#include <string>
#include <utility>

#include "Slide.h"
#include "SlideCreator.h"
#include "SlideShow.h"

using std::string;

typedef unsigned int u_int;

class Model {
 private:
    SlideShow* slideshow;

 public:
    Model();
    ~Model();

    /**
     * @brief addNewSlide		Aggiunge al modello una slide
     * @param path					Path in cui si trova l'immagine da
     * aggiungere
     */
    void addNewSlide(string path) const;

    /**
     * @brief mergeSlides					Compone due slide in un'unica slide
     * multipla
     * @param firstIndex					Indice della prima slide
     * @param secondIndex					Indice della seconda
     * slide
     * @throw std::out_of_range		se gli indici non rispettano il numero di
     * slides
     */
    void mergeSlides(u_int firstIndex, u_int secondIndex) const;

    /**
     * @brief removeSlide					Rimuove una slide
     * @param index								Indice della slide da
     * rimuovere
     * @throw std::out_of_range		se l'indice non è tra le slide indicate
     */
    void removeSlide(u_int index) const;

    /**
     * @brief nextSlide			Va avanti di una slide
     */
    void nextSlide() const;

    /**
     * @brief previousSlide			Va indietro di una slide
     */
    void previousSlide() const;

    /**
     * @brief restartSlideShow			Ritorna all'inizio dello
     * SlideShow
     */
    void restartSlideShow() const;

    /**
     * @brief endSlideShow					Va alla fine dello
     * SlideShow
     */
    void endSlideShow() const;

    /**
     * @brief getSlide							Restituisce la slide
     * corrente
     * @return											Slide
     * corrente
		 * @throw out_of_range          se non ci sono slide
     */
    Slide* getSlide() const;

    /**
     * @brief getCurrent						Restituisce l'indice
     * corrente
     * @return u_int								Indice della slide
     * corrente
     */
    u_int getCurrent() const;

    /**
     * @brief getSlideShowSize			Restituisce la dimensione dello
     * SlideShow
     * @return u_int								Dimensione dello
     * SlideShow
     */
    u_int getSlideShowSize() const;
};

#endif  //_MODEL_H
