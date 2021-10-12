#ifndef MONOSLIDE_H
#define MONOSLIDE_H

#include <string>
#include "Slide.h"
using std::string;

class MonoSlide : public Slide {
 private:
    u_int max_height;
    u_int max_width;
    string image_path;

 public:
    MonoSlide(const string& path, int max_w, int max_h);
    ~MonoSlide() = default;

    /**
     * @brief getter per il path della slide
     * @return il path della slide
     */
    string getPath() const;

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

#endif // MONOSLIDE_H
