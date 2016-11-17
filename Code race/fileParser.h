#pragma once
#include "stdio.h"
#include "iostream"
#include "point2d.h"
using namespace std;

class fileParser
{
    point2d size = point2d();
    char character;
    int counter=4;
    
public:
    fileParser();
    ~fileParser();
    
    point2d call_Size();
    char call_Orbit();
};