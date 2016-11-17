#pragma once
#include "competitor.h"
#include "tile.h"

class competitor;
class endTile: public tile
{
public:
    endTile();
    ~endTile();
    
    void Who_Am_I();
    void onEnter(competitor&);
    inline type getType() {return End;}
    inline int end(){return 0;}
};