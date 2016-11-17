#include "fileParser.h"
#include "fstream"
using namespace std;

fileParser::fileParser() {}
fileParser::~fileParser() {}
point2d fileParser::call_Size()
{
    int num;
    ifstream settings_file;
    settings_file.open("settings.txt");
    
    if (!settings_file.good())
    {
        cout << "The file could not be oppened successfully" << endl;
        return size;
    }
    else
    {
        settings_file >> num;
        size.setx(num);
        settings_file>>character;
        settings_file >> num;
        size.sety(num);
        return size;
    }
}
char fileParser::call_Orbit()
{
    ifstream settings_file;
    settings_file.open("settings.txt");
    
    if (!settings_file.good())
    {
        cout << "The file could not be oppened successfully" << endl;
        exit(EXIT_FAILURE);
    }
    else
        for(int i=0 ; i<counter ; i++)
        {
        again: settings_file >> character;
            if(character==',') goto again;
        }
    counter++;
    return character;
}