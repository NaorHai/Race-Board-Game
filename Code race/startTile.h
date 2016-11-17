#pragma once
#include "competitor.h"
#include "tile.h"

class competitor;
class startTile: public tile
{
public:
    startTile();
    ~startTile();
    
    void Who_Am_I();
    inline type getType() {return start;}
};