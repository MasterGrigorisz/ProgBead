#include "Babu.hpp"
#include "WidAlap.hpp"
#include <sstream>
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;
Babu::Babu(int x, int y, bool csap, int mezom): WidAlap(x,y,0,0)
{
    csapat=csap;
    tudlepni=1;
    //posX �s posY haszn�lva a b�bu t�bl�n l�v� hely�re
    mezomeret=mezom;
}
void Babu::rajz()
{
    int szin=0;
    if (csapat)
        szin=255;
    gout<<move_to(posX*mezomeret+mezomeret/3-mezomeret, posY*mezomeret+mezomeret/3-mezomeret)<<color(szin,szin,szin)<<box(mezomeret/3,mezomeret/3);

}
void Babu::handle(genv::event ev)
{

}
string Babu::mitirjonki()
{

}
bool Babu::tud_e_lepni()
{
    return tudlepni;
}
