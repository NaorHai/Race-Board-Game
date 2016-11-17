//Naor Haimov 311254528
#include "iostream"
#include "fileParser.h"
#include "tile.h"
#include "raceTrack.h"
using namespace std;

int main()
{
    raceTrack start = *new raceTrack;
    start.setMap();
    start.currentMap();
    start.startRace();
    return 0;
}