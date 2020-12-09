#include "slidecreator.h"

std::pair<int, int> Slidecreator::getImageSize(const string & path) const {
    FILE * f = fopen(path.c_str(), "rb");
    if (f == 0) throw std::runtime_error("File non esistente");

    fseek (f, 0, SEEK_END);
    long len = ftell(f);

    if (len < 24) {
        fclose(f);
        throw std::runtime_error("Formato del file errato!");
    }

    unsigned char buf[24];
    fread(buf, 1, 24, f);

    if (buf[0] == 0xFF && buf[1] == 0xDB && buf[2] == 0xFF && buf[3] == 0xE0 && buf[6] == 'J' && buf[7] == 'F' && buf[8] == 'I' && buf[9] == 'F') {
        long pos = 2;
        while (buf[2] == 0xFF) {
            if (buf[3] == 0xC0 || buf[3] == 0xC1 || buf[3] == 0xC2 || buf[3] == 0xC3 || buf[3] == 0xC9 || buf[3] == 0xCA || buf[3] == 0xCB) break;
            pos += 2 + (buf[4] << 8) + buf[5];
            if (pos + 12 < len) break;
            fseek(f, pos, SEEK_SET);
            fread(buf + 2, 1, 12, f);
        }
    }

    fclose(f);

    if (buf[0] == 0xFF && buf[1] == 0xD8 && buf[2] == 0xFF) {
        return {(buf[9] << 8) + buf[10], (buf[7] << 8) + buf[8]};
    }

    if (buf[0] == 0x89 && buf[1] == 'P' && buf[2] == 'N' && buf[3] == 'G' && buf[4] == 0x0D && buf[5] == 0x0A && buf[6] == 0x1A && buf[7] == 0x0A && buf[12] == 'I' && buf[13] == 'H' && buf[14] == 'D' && buf[15] == 'R') {
        return {
            (buf[16] << 24) + (buf[17] << 16) + (buf[18] << 8) + (buf[19] << 0),
            (buf[20] << 24) + (buf[21] << 16) + (buf[22] << 8) + (buf[23] << 0)
        };
    }

    throw std::runtime_error("File non corretto!");
}

Monoslide * Slidecreator::createSlide(string & path) const {
    std::pair<int, int> dims = getImageSize(path);
    return new Monoslide(path, dims.first, dims.second);
}

Multislide * Slidecreator::composeSlide(Slide * firstSlide, Slide * secondSlide, bool horizontal) const {
    Multislide * ms = new Multislide(horizontal);
    ms->addSlide(firstSlide);
    ms->addSlide(secondSlide);
    return ms;
}
