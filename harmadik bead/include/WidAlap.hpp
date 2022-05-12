#ifndef WIDALAP_H
#define WIDALAP_H
#include "graphics.hpp"
#include <sstream>
#include <iostream>
using namespace std;
const int gombszel=25;
class WidAlap
{
protected:
    int posX, posY, sizeX, sizeY;

public:
    bool check /*, checkUP, checkDW*/;
    WidAlap(int x, int y, int sx, int sy);
    bool ischecked(int egerX, int egerY);
    //virtual bool issmallcheckedUP(int egerX, int egerY)=0;
    //virtual bool issmallcheckedDW(int egerX, int egerY)=0;
    virtual void rajz()=0;
    virtual void handle(genv::event ev) = 0;
    virtual std::string mitirjonki()=0;
};

#endif // WIDALAP_H
