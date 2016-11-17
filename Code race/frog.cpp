#include "frog.h"

frog::frog()
{
    setName("[F]");
}
frog::~frog(){}
void frog::run()
{
    setCost(2);
}
void frog::swim()
{
    setCost(0.5);
}
void frog::eat()
{
    setCost(1);
}
void frog::walk()
{
    setCost(1);
}
void frog::setRecord()
{
    int x,y;
    x= getPosition().getx();
    y= getPosition().gety();
    allMoves[x][y]+=getName();
}
void frog::printMoves()
{
    int x =size.getx();
    int y =size.gety();
    
    for (int i=0; i<x; i++)
    {
        cout<<endl;
        for (int j=0; j<y; j++)
        {
            if (allMoves[i][j] != "[F]")
            {
                cout<<"\tX";
            }
            else cout<<"\t"<<allMoves[i][j];
        }
    }
}