#include "MonoSlide.h"

MonoSlide::MonoSlide(const string& path, int max_w, int max_h) :
    max_height(max_h),
    max_width(max_w),
    image_path(path){}

string MonoSlide::getPath() const { return image_path; }

u_int MonoSlide::getMaxHeight() const { return max_height; }

u_int MonoSlide::getMaxWidth() const { return max_width; }
