
#ifndef _SLIDESHOW_H
#define _SLIDESHOW_H

#include <Slide.h>
#include <stdexcept>
#include <vector>

class SlideShow {
 private:
    u_int currentSlide;
    std::vector<Slide*> slides;

 public:
    SlideShow();
    ~SlideShow();

    /**
     * @brief inserisce slide alla posizione finale
     * @param slide : slide da inserire
     */
    void addSlide(Slide* slide);

    /**
     * @brief inserisce slide alla posizione index, oppure alla fine se index >
     *				numero di slide correntemente inserite
     * @param slide : slide da inserire
     * @param index : indice a cui inserire la slide
     */
    void insertSlide(Slide* slide, u_int index);

    /**
     * @brief rimuove la index-esima slide dalla slideshow
     * @param index : indice della slide da rimuovere
     * @return puntatore alla slide rimossa
     * @throw out_of_range se index > numero di slide correntemente nella
     * slideshow
     */
    Slide* removeSlide(u_int index);

    /**
     * @brief getter per l'indice della slide corrente
     * @return l'indice della slide corrente
     */
    u_int getCurrentSlide() const;

    /**
     * @brief getter per uan slide specifica
     * @param index : indice della slide desiderata
     * @return la slide desiderata
     * @throw out_of_range se index > numero di slide correntemente nella
     * slideshow
     */
    Slide* getSlide(u_int index) const;

    /**
     * @brief getSize			getter per la dimensione dello SlideShow
     * @return u_int			la dimensione dello SlideShow
     */
    u_int getSize() const;

    /**
     * @brief torna indietro di una slide
     */
    void previous();

    /**
     * @brief va avanti di una slide
     */
    void next();

    /**
     * @brief riporta la slideshow alla slide iniziale
     */
    void goToStart();

    /**
     * @brief porta la slideshow all'ultima slide
     */
    void goToEnd();
};

#endif  //_SLIDESHOW_H
