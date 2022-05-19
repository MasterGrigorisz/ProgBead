#include "Gomb.hpp"
#include "WidAlap.hpp"
#include "graphics.hpp"
#include <iostream>
#include <sstream>
using namespace genv;
using namespace std;
Gomb::Gomb(int x, int y, int sx, int sy, int sza): WidAlap(x,y,sx,sy)
{
szam=sza;
kattintosszin=85;
}
void Gomb::rajz()
{
    stringstream sss;
    sss<<szam<<" X "<<szam;
    int el=2;
    gout<<move_to(posX,posY)<<color(85,85,85)<<box(sizeX,sizeY)
        <<move_to(posX+el,posY+el)<<color(200,200,200)<<box(sizeX-el*2,sizeY-el*2)
        <<move_to(posX+el*2,posY+el*2)<<color(kattintosszin,kattintosszin,kattintosszin)<<box(sizeX-el*4,sizeY-el*4+1)
        <<move_to(posX+10, posY+23)<<color(255,255,255) << text(sss.str());
    kattintosszin=85;
}
void Gomb::handle(genv::event ev)
{
    if(check)
    {
        kattintosszin*=2;
    }


    check=!check;
}
