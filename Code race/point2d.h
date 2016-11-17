#pragma once
class point2d
{
    int x;
    int y;
public:
    point2d(int x, int y);
    point2d();
    ~point2d();
    
    inline int getx() {return x;}
    inline int gety() {return y;}
    void setx(int pixel_1);
    void sety(int pixel_2);
};