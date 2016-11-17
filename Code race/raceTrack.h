#pragma once
#include "iostream"
#include "fileParser.h"
#include "point2d.h"
#include "frog.h"
#include "rabbit.h"
#include "turtle.h"
#include "cropTile.h"
#include "waterTile.h"
#include "easyTile.h"
#include "mediumTile.h"
#include "startTile.h"
#include "endTile.h"

class raceTrack
{
    fileParser* My_Setting_File = new fileParser();
    point2d size = My_Setting_File->call_Size();
    tile*** track = new tile**[size.getx()];
    point2d dest;
    frog frog_comp;
    rabbit rabbit_comp;
    turtle turtle_comp;
    
public:
    raceTrack();
    ~raceTrack();
    
    void startRace();
    void declareWinner();
    void currentMap();
    void setMap();
};