#ifndef MULTISLIDE_H
#define MULTISLIDE_H
#include "slide.h"
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <stdexcept>
using std::string;

class Multislide: public Slide {
private:
    bool dividedHorizontally;
    std::vector <Slide *> slides;
public:
    Multislide(bool h);
    ~Multislide();
    void addSlide(Slide * slide);
    Slide * removeSlide(u_int index);
    bool isDividedHorizontaly() const;
    const std::vector <Slide *> & getSlides() const;
    u_int getMaxHeight() const override;
    u_int getMaxWidth() const override;
};

#endif // MULTISLIDE_H
