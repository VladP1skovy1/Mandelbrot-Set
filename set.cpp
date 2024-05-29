#include "set.h"

Set::RenderHandler Set::render_handler_set = nullptr;

void Set::update() 
{
    this->set = (SETS)(shared_data.set);
    this->params.min_x = set_data.min_x;
    this->params.min_y = set_data.min_y;
    this->params.d_x = set_data.d_x;
    this->params.d_y = set_data.d_y;    


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
        switch (this->set)
        {
        case Mandelbrot:
            my_threads[i] = std::thread(&Set::init_mandelbrot_for_region, this, start, start+batch_size);
            break;
        
        default:
            break;
        }
    }
    init_mandelbrot_for_region(nb_threads * batch_size, nb_threads * batch_size + batch_remainder);

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


void Set::init_mandelbrot_for_region(int start, int end) {
    double min_x = this->params.min_x;
    double min_y = this->params.min_y;
    double d_x = this->params.d_x;
    double d_y = this->params.d_y;

    for (int l = start; l < end; l++)
    {
        double x = min_x + (l % width) * d_x;
        double y = min_y + l / width * d_y;
        double z_x = 0.0;
        double z_y = 0.0;
        int k = 0;
        while (k < 255)
        {
            double z_x_new = z_x * z_x - z_y * z_y + x;
            double z_y_new = 2 * z_x * z_y + y;
            if (z_x_new * z_x_new + z_y_new * z_y_new > 4)
            {
                break;
            }
            z_x = z_x_new;
            z_y = z_y_new;
            k++;
        }
        this->buffer[(l % width) * width + l / width] = k;
    }
}

void Set::render()
{
    if(this->render_handler_set != nullptr)
    {
        this->render_handler_set(this);
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
