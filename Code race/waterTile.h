#pragma once
#include "competitor.h"
#include "tile.h"

class competitor;
class waterTile: public tile
{
public:
    waterTile();
    ~waterTile();
    
    void Who_Am_I();
    void onEnter(competitor&);
    inline type getType() {return water;}
};