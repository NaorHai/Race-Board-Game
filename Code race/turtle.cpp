#include "turtle.h"

turtle::turtle()
{
    setName("[T]");
}
turtle::~turtle(){}
void turtle::run()
{
    setCost(0.75);
}
void turtle::swim()
{
    setCost(1);
}
void turtle::eat()
{
    setCost(1);
}
void turtle::walk()
{
    setCost(1);
}
void turtle::setRecord()
{
    int x,y;
    x= getPosition().getx();
    y= getPosition().gety();
    allMoves[x][y]+=getName();
}
void turtle::printMoves()
{
    int x =size.getx();
    int y =size.gety();
    
    for (int i=0; i<x; i++)
    {
        cout<<endl;
        for (int j=0; j<y; j++)
        {
            if (allMoves[i][j] != "[T]")
            {
                cout<<"\tX";
            }
            else cout<<"\t"<<allMoves[i][j];
        }
    }
}