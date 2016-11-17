#pragma once
#include "competitor.h"
#include "tile.h"

class tile;
class competitor;
class frog: public competitor
{
public:
    frog();
    ~frog();
    
    bool moveTo(tile***,competitor&);
    void swim();
    void eat();
    void run();
    void walk();
    void operator<<(const competitor&);
    void setRecord();
    void printMoves();
};