#include "point2d.h"

point2d::point2d()
{
    setx(0);
    sety(0);
}
point2d::point2d(int pixel_1, int pixel_2)
{
    setx(pixel_1);
    sety(pixel_2);
}
point2d::~point2d(){}
void point2d::setx(int pixel_1)
{
    this->x = pixel_1;
}
void point2d::sety(int pixel_2)
{
    this->y = pixel_2;
}