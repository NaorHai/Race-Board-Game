#include "endTile.h"

endTile::endTile()
{
    setName("FIN");
}
endTile::~endTile(){}
void endTile::Who_Am_I()
{
    cout<<name;
}
void endTile::onEnter(competitor & comp)
{
    end();
}