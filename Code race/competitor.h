#pragma once
#include "tile.h"
#include "point2d.h"
#include "fileParser.h"

using namespace std;
class tile;
class competitor
{
    float totalMovementCost=0;
protected:
    fileParser* My_Setting_File = new fileParser();
    point2d size = My_Setting_File->call_Size();
    string allMoves[5][13];
    string name;
    tile* currentTile;
    point2d position;
    
public:
    competitor();
    virtual ~competitor();
    
    void moveTo(point2d,competitor&);
    void setPosition(point2d);
    inline point2d getPosition() {return position;}
    
    inline virtual void swim(){}
    inline virtual void eat(){}
    inline virtual void run(){}
    inline virtual void walk(){}
    
    void operator<<(competitor&);
    
    void setCost(float);
    inline virtual float getCost() {return totalMovementCost;}
    void lookAhead(point2d, tile**,competitor&);
    
    void setName(string);
    inline string getName(){return name;}
    
    virtual void setRecord(competitor&){}
    virtual void printMoves(){}
};