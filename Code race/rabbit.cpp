#include "rabbit.h"

rabbit::rabbit()
{
    setName("[R]");
}
rabbit::~rabbit(){}
void rabbit::run()
{
    setCost(0.5);
}
void rabbit::swim()
{
    setCost(1);
}
void rabbit::eat()
{
    setCost(2);
}
void rabbit::walk()
{
    setCost(1);
}
void rabbit::setRecord()
{
    int x,y;
    x= getPosition().getx();
    y= getPosition().gety();
    allMoves[x][y]+=getName();
}
void rabbit::printMoves()
{
    int x =size.getx();
    int y =size.gety();

    for (int i=0; i<x; i++)
    {
        cout<<endl;
        for (int j=0; j<y; j++)
        {
            if (allMoves[i][j] != "[R]")
            {
                cout<<"\tX";
            }
            else cout<<"\t"<<allMoves[i][j];
        }
    }
}