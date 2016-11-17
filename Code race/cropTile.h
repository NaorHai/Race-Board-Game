#pragma once
#include "competitor.h"
#include "tile.h"
class competitor;
class cropTile: public tile
{    
public:
    cropTile();
    ~cropTile();
    
    void Who_Am_I();
    void onEnter(competitor&);
    inline type getType() {return crop;}
};