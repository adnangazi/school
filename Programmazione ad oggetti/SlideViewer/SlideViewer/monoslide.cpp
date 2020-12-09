#include "monoslide.h"

Monoslide::Monoslide(const string & path, u_int height, u_int width) {
    max_height = height;
    max_width = width;
    image_path = path;
}

string Monoslide::getPath() const {
    return image_path;
}

u_int Monoslide::getMaxHeight() const {
    return max_height;
}

u_int Monoslide::getMaxWidth() const {
    return max_width;
}
