#include <complex>
#include <string.h>
#include <stdlib.h>
#include "shared_data.h"
#include "component.h"

#define DEFAULT_MIN_X -2
#define DEFAULT_MAX_X 2
#define DEFAULT_MIN_Y -2
#define DEFAULT_MAX_Y 2

class Set : public Component {
    unsigned char* buffer = nullptr;
    float min_x;
    float max_x;
    float min_y;
    float max_y;
    float d_x;
    float d_y;
    SETS set;

    public:
    Set(SETS set);
    Set(int min_x, int max_x, int min_y, int max_y, double d_x, double d_y);
    void init_mandelbrot();
    void render();
    int get_min_x() const;
    int get_max_x() const;
    int get_min_y() const;
    int get_max_y() const;
    double get_dx() const;
    double get_dy() const;
    const unsigned char *get_buffer() const;

    static void  set_render_handler(RenderHandler render_handler);
    void set_min_x(float value) {
        min_x = value;
    }

    void set_max_x(float value) {
        max_x = value;
    }

    void set_min_y(float value) {
        min_y = value;
    }

    void set_max_y(float value) {
        max_y = value;
    }

    void set_dx(float value) {
        d_x = value;
    }

    void set_dy(float value) {
        d_y = value;
    }

    void update() {

        this->height = (max_y - min_y) / d_y + 1;
        this->width = (max_x - min_x) / d_x + 1;
        switch (this->set)
        {
        case Mandelbrot:
            init_mandelbrot();
            break;
        
        default:
            break;
        }
    }
protected:
    static RenderHandler render_handler_set;
};