#include "easyTile.h"

easyTile::easyTile()
{
    setName("ET");
}
easyTile::~easyTile(){}
void easyTile::Who_Am_I()
{
    cout<<name;
}
void easyTile::onEnter(competitor & comp)
{
    comp.run();
}