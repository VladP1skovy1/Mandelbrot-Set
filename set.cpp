#include "set.h"

Set::RenderHandler Set::render_handler_set = nullptr;

void Set::update() 
{
    this->set = (SETS)shared_data.set;
    this->params = set_data;   
    this->color = this->params.color;


    unsigned nb_threads_hint = std::thread::hardware_concurrency();
    //unsigned nb_threads = nb_threads_hint == 0 ? 8 : (nb_threads_hint);
    unsigned nb_threads = 10;
    unsigned nb_elements = width * height;
    unsigned batch_size = nb_elements / nb_threads;
    unsigned batch_remainder = nb_elements % nb_threads;

    std::vector< std::thread > my_threads(nb_threads);

    for(unsigned i = 0; i < nb_threads; ++i)
    {
        int start = i * batch_size;
        switch (this->set) {
            case Mandelbrot:
                my_threads[i] = std::thread(&Set::init_mandelbrot_for_region, this, start, start+batch_size);
            break;
            case Julia:
                my_threads[i] = std::thread(&Set::init_julia_for_region, this, start, start+batch_size);
            break;

        
        default:
            break;
        }
    }

    switch (this->set) {
    case Mandelbrot:
        init_mandelbrot_for_region(nb_threads * batch_size, nb_threads * batch_size + batch_remainder);
        break;
    case Julia:
        init_julia_for_region(nb_threads * batch_size, nb_threads * batch_size + batch_remainder);
        break;
    
    default:
        break;
    }
    

    std::for_each(my_threads.begin(), my_threads.end(), std::mem_fn(&std::thread::join));

}

Set::~Set()
{
    if(this->buffer != nullptr) {
        free(this->buffer);
    }
}

Set::Set(int x, int y, int width, int height) : Component(x, y, width, height)
{
    if(this->buffer == nullptr) {
        this->buffer = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    }
}

void Set::init_mandelbrot()
{
}

void Set::init_julia_for_region(int start, int end)
{
    int iterations = get_max_value();
    double min_x = this->params.min_x;
    double min_y = this->params.min_y;
    double d_x = this->params.d_x;
    double d_y = this->params.d_y;
    double c_x = this->params.constant_x;
    double c_y = this->params.constant_y;

    for (int l = start; l < end; l++)
    {
        int i = l % width;
        int j = l / width;
        double z_x = min_x + i * d_x;
        double z_y = min_y + j * d_y;
        int k = 0;
        while (k < iterations) {
            double z_x_new = z_x * z_x - z_y * z_y + c_x;
            double z_y_new = 2 * z_x * z_y + c_y;
            if (z_x_new * z_x_new + z_y_new * z_y_new > 4) {
                break;
            }
            z_x = z_x_new;
            z_y = z_y_new;
            k++;
        }
        this->buffer[j * width + i] = k;
    }
}


void Set::init_mandelbrot_for_region(int start, int end) {
    int iterations = this->get_max_value();
    double min_x = this->params.min_x;
    double min_y = this->params.min_y;
    double d_x = this->params.d_x;
    double d_y = this->params.d_y;

    for (int l = start; l < end; l++) {
        int i = l % width;
        int j = l / width;
        double x = min_x + i * d_x;
        double y = min_y + j * d_y;
        double z_x = 0.0;
        double z_y = 0.0;
        int k = 0;
        while (k < iterations) {
            double z_x_new = z_x * z_x - z_y * z_y + x;
            double z_y_new = 2 * z_x * z_y + y;
            if (z_x_new * z_x_new + z_y_new * z_y_new > 4) {
                break;
            }
            z_x = z_x_new;
            z_y = z_y_new;
            k++;
        }
        this->buffer[j * width + i] = k;
    }
}

void Set::render()
{
    if(this->render_handler_set != nullptr)
    {
        this->render_handler_set(this);
    }
}

int Set::get_max_value() const
{
    switch (this->set)
    {
    case Mandelbrot:
    case Julia:
        return 255 * this->params.resolution;
        break;
    default:
        break;
    }
}

const unsigned char* Set::get_buffer() const
{
    return buffer;
}

void Set::set_render_handler(RenderHandler render_handler)
{
    Set::render_handler_set = render_handler;
}
