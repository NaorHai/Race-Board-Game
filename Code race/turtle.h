#pragma once
#include "competitor.h"
#include "tile.h"

class competitor;
class turtle: public competitor
{
public:
    turtle();
    ~turtle();
    
    bool moveTo(tile***,competitor&);
    void swim();
    void eat();
    void run();
    void walk();
    void operator<<(const competitor&);
    void setRecord();
    void printMoves();
};