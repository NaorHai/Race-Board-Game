#include "cropTile.h"

cropTile::cropTile()
{
    setName("CT");
}
cropTile::~cropTile(){}
void cropTile::Who_Am_I()
{
    cout<<name;
}
void cropTile::onEnter(competitor & comp)
{
    comp.eat();
}