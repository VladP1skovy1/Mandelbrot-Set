#include "set.h"

Set::Set(int min_x, int max_x, int min_y, int max_y, double d_x, double d_y)
{
    this->min_x = min_x;
    this->max_x = max_x;
    this->min_y = min_y;
    this->max_y = max_y;
    this->d_x = d_x;
    this->d_y = d_y;
    this->height = (max_y - min_y) / d_y + 1;
    this->width = (max_x - min_x) / d_x + 1;
    this->buffer = new unsigned char[height * width];
    memset(this->buffer, 0, height * width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double x = min_x + j * d_x;
            double y = min_y + i * d_y;
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
            this->buffer[i * width + j] = k;
        }
    }
}

void Set::render()
{
    if(this->render_handler != nullptr)
    {
        this->render_handler(this);
    }
}

int Set::get_min_x() const
{
    return min_x;
}

int Set::get_max_x() const
{
    return max_x;
}

int Set::get_min_y() const
{
    return min_y;
}

int Set::get_max_y() const
{
    return max_y;
}

double Set::get_dx() const
{
    return d_x;
}

double Set::get_dy() const
{
    return d_y;
}

const unsigned char* Set::get_buffer() const
{
    return buffer;
}
