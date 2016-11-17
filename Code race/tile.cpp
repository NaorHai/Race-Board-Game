#include "tile.h"

tile::tile() {}

tile::tile(point2d pointXY)
{
    setPosition(pointXY);
}
tile::~tile(){}
void tile::setName(string new_name)
{
    name=new_name;
}

void tile::setPosition(point2d p)
{
    position.setx(p.getx());
    position.sety(p.gety());
}