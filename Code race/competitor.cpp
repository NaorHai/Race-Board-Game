#include "competitor.h"

competitor::competitor()
{
    setName("NONE");
}
competitor::~competitor() {}
void competitor::operator<<(competitor& comp)
{
    string new_name = comp.getName();
    cout<<new_name<<endl;
    cout<<"The total cost is: "<<comp.totalMovementCost<<endl;
}
void competitor::setName(string new_name)
{
    this->name=new_name;
}
void competitor::setCost(float add)
{
    totalMovementCost+=add;
}
void competitor::moveTo(point2d next_t,competitor& cmp)
{
    cmp.setPosition(next_t);
}
void competitor::setPosition(point2d pos)
{
    position.setx(pos.getx());
    position.sety(pos.gety());
}
void competitor::lookAhead(point2d desteny, tile** track,competitor& cmp)
{
    cout<<cmp.getName()<<" current location -> Line:"<<cmp.getPosition().getx()+1<<" Tile:"<<cmp.getPosition().gety()+1<<endl;
    bool up=false,down=false,left=false,right=false;
    
    if (cmp.getPosition().getx()<desteny.getx()) down=true;
    if (cmp.getPosition().getx()>desteny.getx()) up=true;
    if (cmp.getPosition().gety()<desteny.gety()) right=true;
    if (cmp.getPosition().gety()>desteny.gety()) left=true;
    
    int x= cmp.getPosition().getx();
    int y= cmp.getPosition().gety();
    point2d RealPosition (x,y);
    point2d temp (x,y);
    float cost_ud=5, cost_lr=5,RealCost=cmp.getCost();
    
    point2d location_ud (0,0);
    point2d location_lr (0,0);
    
    if (up == true)
    {
        location_ud.setx(cmp.getPosition().getx()-1);
        location_ud.sety(cmp.getPosition().gety());
        cmp.moveTo(location_ud,cmp);
        track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
        cost_ud=cmp.totalMovementCost-RealCost;
        cmp.totalMovementCost=RealCost;
    }
    if (down == true)
    {
        location_ud.setx(cmp.getPosition().getx()+1);
        location_ud.sety(cmp.getPosition().gety());
        cmp.moveTo(location_ud,cmp);
        track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
        cost_ud=cmp.totalMovementCost-RealCost;
        cmp.totalMovementCost=RealCost;
    }
    cmp.setPosition(RealPosition);
    if (right == true)
    {
        location_lr.sety(cmp.getPosition().gety()+1);
        location_lr.setx(cmp.getPosition().getx());
        cmp.moveTo(location_lr,cmp);
        track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
        cost_lr=cmp.totalMovementCost-RealCost;
        cmp.totalMovementCost=RealCost;
    }
    if (left == true)
    {
        location_lr.sety(cmp.getPosition().gety()-1);
        location_lr.setx(cmp.getPosition().getx());
        cmp.moveTo(location_lr,cmp);
        track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
        cost_lr=cmp.totalMovementCost-RealCost;
        cmp.totalMovementCost=RealCost;
    }
    if (up==true || down==true || right==true || left==true)
    {
        cmp.setPosition(RealPosition);
        if((cost_ud>=cost_lr))
        {
            if (right==true)
            {
                location_lr.setx(cmp.getPosition().getx());
                location_lr.sety(cmp.getPosition().gety()+1);
                moveTo(location_lr,cmp);
                track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
            }
            else if (left==true)
            {
                location_lr.setx(cmp.getPosition().getx());
                location_lr.sety(cmp.getPosition().gety()-1);
                moveTo(location_lr,cmp);
                track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
            }
        }
        else if (up==true)
        {
            location_ud.setx(cmp.getPosition().getx()-1);
            location_ud.sety(cmp.getPosition().gety());
            moveTo(location_ud,cmp);
            track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
        }
        else if (down==true)
        {
            location_ud.setx(cmp.getPosition().getx()+1);
            location_ud.sety(cmp.getPosition().gety());
            moveTo(location_ud,cmp);
            track[cmp.getPosition().getx()][cmp.getPosition().gety()].onEnter(cmp);
        }
    }
    cout<<cmp.getName()<<" next location -> Line:"<<cmp.getPosition().getx()+1<<" Tile: "<<cmp.getPosition().gety()+1<<endl<<endl;
}