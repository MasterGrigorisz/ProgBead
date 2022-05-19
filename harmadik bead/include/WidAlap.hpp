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
    int kivanrajta;
    int tablaposX, tablaposY;
    bool check;
    bool kijelolt;
    WidAlap(int x, int y, int sx, int sy);
    bool ischecked(int egerX, int egerY);
    virtual void rajz()=0;
    virtual void handle(genv::event ev) = 0;
    void kivanrajta_modosit(int kivan);
    //virtual int kivanrajta_leker();
};

#endif // WIDALAP_H
