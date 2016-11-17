#pragma once
#include "competitor.h"
#include "tile.h"
class competitor;
class mediumTile: public tile
{
public:
    mediumTile();
    ~mediumTile();
    
    void Who_Am_I();
    void onEnter(competitor&);
    inline type getType() {return medium;}
};