#include <complex>
#include <string.h>
#include <stdlib.h>
#include "component.h"

class Set : public Component {
    unsigned char* buffer = nullptr;
    float min_x;
    float max_x;
    float min_y;
    float max_y;
    float d_x;
    float d_y;

    public:
    Set(int min_x, int max_x, int min_y, int max_y, double d_x, double d_y);
    void render();
    int get_min_x() const;
    int get_max_x() const;
    int get_min_y() const;
    int get_max_y() const;
    double get_dx() const;
    double get_dy() const;
    const unsigned char *get_buffer() const;
};