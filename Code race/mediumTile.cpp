#include "mediumTile.h"

mediumTile::mediumTile()
{
    setName("MT");
}
mediumTile::~mediumTile(){}
void mediumTile::Who_Am_I()
{
    cout<<name;
}
void mediumTile::onEnter(competitor & comp)
{
    comp.walk();
}