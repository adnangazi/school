#ifndef MONOSLIDE_H
#define MONOSLIDE_H
#include "slide.h"
#include <string>
using std::string;

class Monoslide: public Slide {
private:
    u_int max_height;
    u_int max_width;
    string image_path;

public:
    Monoslide(const string & path, u_int height, u_int width);
    ~Monoslide() = default;
    string getPath() const;
    u_int getMaxHeight() const override;
    u_int getMaxWidth() const override;
};

#endif // MONOSLIDE_H
