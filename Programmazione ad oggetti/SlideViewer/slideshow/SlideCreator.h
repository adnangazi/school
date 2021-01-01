#ifndef _SLIDECREATOR_H
#define _SLIDECREATOR_H

#include <string>
#include <utility>

#include <MonoSlide.h>
#include <MultiSlide.h>

using std::string;

class SlideCreator {
 private:
    std::pair<int, int> getImageSize(const string& path) const;

 public:
    /**
     * @brief factory per la creazione di MonoSlide
     * @param path : path della slide
     * @return la slide che rappresenta i parametri
     * @throw std::runtime_error
     */
    MonoSlide* createSlide(string path) const;

    /**
     * @brief factory per la composizione di slide composte
     * @param firstSlide : prima slide da aggiungere
     * @param secondSlide : seconda slide da aggiungere
     * @return la MultiSlide contentente le slide di input
     */
    MultiSlide* composeSlides(Slide* firstSlide, Slide* secondSlide,
                                                        bool horizontal = true) const;
};

#endif  //_SLIDECREATOR_H
