#include "Babu.hpp"
#include "WidAlap.hpp"
#include <sstream>
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;
Babu::Babu(int x, int y, bool csap, int mezom): WidAlap(x,y,mezom,mezom)
{
    csapat=csap;
    tudlepni=1;
    //posX �s posY haszn�lva a b�bu t�bl�n l�v� hely�re -- update: h�lyes�g volt
    mezomeret=mezom;
}
void Babu::rajz()
{
    int szin=0;
    if (csapat)
        szin=255;
    if (check)
        szin=szin/3+100;
    gout<<move_to(posX+mezomeret/3, posY+mezomeret/3)<<color(szin,szin,szin)<<box(mezomeret/3,mezomeret/3);

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
void Babu::lepes(int x, int y)
{
    //cout<<endl<<"atlep"<<endl;
    posX=x-x%mezomeret;
    posY=y-y%mezomeret;
}
