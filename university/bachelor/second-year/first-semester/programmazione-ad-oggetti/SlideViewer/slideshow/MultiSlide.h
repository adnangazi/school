#ifndef _MULTISLIDE_H
#define _MULTISLIDE_H

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

#include "Slide.h"

using std::string;

class MultiSlide : public Slide {
 private:
    bool dividedHorizontally;
    std::vector<Slide*> slides;

 public:
    MultiSlide(bool h);
    ~MultiSlide();

    /**
     * @brief aggiunge una slide alla multislide
     * @param slide : puntatore alla slide da aggiungere
     */
    void addSlide(Slide* slide);

    /**
     * @brief rimuove la index-esima slide dalla slide corrente
     * @param index : indice della slide da rimuovere
     * @return riferimento alla slide rimossa
     * @throws std::out_of_range : se index > numero di slides
     */
    Slide* removeSlide(u_int index);

    /**
     * @brief specifica se la slide corrente è divisa verticale o orizzontale
     * @return true sse è divisa orizzontalmente, false altrimenti
     */
    bool isDividedHorizontally() const;

    /**
     * @brief getter per le slide che compongono la corrente
     * @return vector delle slide contenute
     */
    const std::vector<Slide*>& getSlides() const;

    /**
     * @brief getMaxHeight		Restituisce l'altezza massima della
     *												slide
     * @return u_int					Altezza massima della
     *												slide
     */
    u_int getMaxHeight() const override;

    /**
     * @brief getMaxWidth			Restituisce la larghezza massima della
     *												slide
     * @return u_int					Larghezza massima della
     *												slide
     */
    u_int getMaxWidth() const override;
};

#endif  //_MULTISLIDE_H
