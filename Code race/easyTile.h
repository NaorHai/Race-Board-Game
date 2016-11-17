#pragma once
#include "competitor.h"
#include "tile.h"
class competitor;
class easyTile: public tile
{    
public:
    easyTile();
    ~easyTile();
    
    void Who_Am_I();
    void onEnter(competitor&);
    inline type getType() {return easy;}
};