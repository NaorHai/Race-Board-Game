#include "waterTile.h"

waterTile::waterTile()
{
    setName("WT");
}
waterTile::~waterTile(){}
void waterTile::Who_Am_I()
{
    cout<<name;
}
void waterTile::onEnter(competitor & comp)
{
    comp.swim();
}