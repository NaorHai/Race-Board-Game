#pragma once
#include <iostream>
#include "point2d.h"
#include "string"
#include "competitor.h"

using namespace std;
enum type {start,water,medium,easy,crop,End};
class competitor;
class tile
{
protected:
    point2d position;
    string name;
    type x;
    float dEasy,dMedium,dCrop,dWater;
    
public:
    tile();
    tile(point2d new_point);
    virtual ~tile();
    
    inline virtual void Who_Am_I(){cout<<name;}
    virtual void onEnter(competitor&) {}
    void setName(string);
    inline string getName(){return name;}
    
    void setPosition(point2d);
    inline point2d getPosition(){return position;}
    inline type getType(){return x;}
};