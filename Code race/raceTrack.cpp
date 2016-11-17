#include "raceTrack.h"

raceTrack::raceTrack()
{
    for(int a=0;a<size.getx();a++)
    {
        track[a]=new tile*[size.gety()];
    }
}
raceTrack::~raceTrack()
{
    for (int b=0;b<size.getx();b++)
        for (int c=0;c<size.gety();c++)
        {
            delete  track[b][c];
        }
}
void raceTrack::currentMap()
{
    for (int i=0; i<size.getx(); i++)
    {
        cout<<endl<<"|\t";
        for (int j=0; j<size.gety(); j++)
        {
            track[i][j]->Who_Am_I();
            cout<<"\t|\t";
        }
    }
    cout<<endl<<endl;
}
void raceTrack::setMap()
{
    cout<<"Let's the play begin - may the force be with you"<<endl;
    char character;
    for(int i=0;i<size.getx();i++)
    {
        cout<<endl<<"| ";
        for(int j=0;j<size.gety();j++)
        {
            character=My_Setting_File->call_Orbit();
            switch (character)
            {
                case '=':
                {
                    cout<<"= | ";
                    track [i][j]= new easyTile();
                    break;
                }
                case '#':
                {
                    cout<<"# | ";
                    track [i][j]= new mediumTile();
                    break;
                }
                case '~':
                {
                    cout<<"~ | ";
                    track [i][j]= new waterTile();
                    break;
                }
                case 'v':
                {
                    cout<<"v | ";
                    track [i][j]= new cropTile();
                    break;
                }
                case 'S':
                {
                    cout<<"S | ";
                    track [i][j]= new startTile();
                    point2d t(i,j);
                    
                    rabbit_comp.setPosition(t);
                    rabbit_comp.setRecord();
                    frog_comp.setPosition(t);
                    frog_comp.setRecord();
                    turtle_comp.setPosition(t);
                    turtle_comp.setRecord();
                    break;
                }
                case 'E':
                {
                    cout<<"E | ";
                    track [i][j]= new endTile();
                    dest.setx(i);
                    dest.sety(j);
                    break;
                }
            }
        }
    }
    delete My_Setting_File;
    cout<<endl<<endl;
}
void raceTrack::startRace()
{
    int i=0; float min=0; string Win;
    cout<<"Ready.. Set.. (BOOM..) GOOO!!!!!"<<endl;
    rabbit_comp.printMoves();
    cout<<endl;
    turtle_comp.printMoves();
    cout<<endl;
    frog_comp.printMoves();
    while (1)
    {
        cout<<endl<<endl<<"Please press 1 to perform the next step or press any key to Exit"<<endl;
        cin>>i;
        if (i==1) goto next_step;
        else exit(0);
   
    next_step:
        if (rabbit_comp.getPosition().getx()!=dest.getx() || rabbit_comp.getPosition().gety()!=dest.gety())
        {
            rabbit_comp.lookAhead(dest,*track,rabbit_comp);
            rabbit_comp.setRecord();
        }
        if (frog_comp.getPosition().getx()!=dest.getx() || frog_comp.getPosition().gety()!=dest.gety())
        {
            frog_comp.lookAhead(dest,*track,frog_comp);
            frog_comp.setRecord();
        }
        if (turtle_comp.getPosition().getx()!=dest.getx() || turtle_comp.getPosition().gety()!=dest.gety())
        {
            turtle_comp.lookAhead(dest,*track,turtle_comp);
            turtle_comp.setRecord();
        }
        rabbit_comp.printMoves();
        cout<<endl;
        turtle_comp.printMoves();
        cout<<endl;
        frog_comp.printMoves();
        if ((track[rabbit_comp.getPosition().getx()][rabbit_comp.getPosition().gety()]->getName()=="FIN") && (track[frog_comp.getPosition().getx()][frog_comp.getPosition().gety()]->getName()=="FIN") && (track[turtle_comp.getPosition().getx()][turtle_comp.getPosition().gety()]->getName()=="FIN")) break;
    }
    cout<<endl<<endl<<"Rabbit"<<endl;
    cout<<"the total movment cost is - "<<rabbit_comp.getCost()<<endl;
    
    cout<<endl<<"Turtle"<<endl;
    cout<<"the total movment cost is - "<<turtle_comp.getCost()<<endl;
    
    cout<<endl<<"Frog"<<endl;
    cout<<"the total movment cost is - "<<frog_comp.getCost()<<endl;
    
    min=rabbit_comp.getCost();
    Win=rabbit_comp.getName();
    
    if(min>frog_comp.getCost())
    {
        min=frog_comp.getCost();
        Win=frog_comp.getName();
    }
    if (turtle_comp.getCost()<min)
    {
        min=turtle_comp.getCost();
        Win=turtle_comp.getName();
    }
    if(rabbit_comp.getCost()==turtle_comp.getCost()==frog_comp.getCost())
        cout<<"All the competitors could be the lcocal navigation prince"<<endl;
    else
        cout<<endl<<Win<<" could be the lcocal navigation prince"<<endl<<endl;
}