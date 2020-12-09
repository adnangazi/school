#ifndef SLIDECREATOR_H
#define SLIDECREATOR_H
#include "monoslide.h"
#include "multislide.h"
#include <string>
#include <utility>
using std::string;

class Slidecreator {
private:
    std::pair<int, int> getImageSize(const string & path) const;

public:
    Monoslide * createSlide(string & path) const;
    Multislide * composeSlide(Slide * firstSlide, Slide * secondSlide, bool horizontal = true) const;
};

#endif // SLIDECREATOR_H
