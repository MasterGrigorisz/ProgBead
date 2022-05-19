#include "Mezo.hpp"
#include "WidAlap.hpp"
#include <sstream>
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;
Mezo::Mezo(int x, int y, int sx, int sy, int Tx, int Ty): WidAlap(x,y,sx,sy)
{

    tablaposX=Tx;
    tablaposY=Ty;
    //cout<<tablaposX<<" mezo konst "<<tablaposY<<endl;
    if (Tx %2 ==0 and Ty % 2 ==0 or Tx %2 ==1 and Ty % 2 ==1)
    {
        szin[0]=255;
        szin[1]=207;
        szin[2]=159;
    }
    else
    {
        szin[0]=210;
        szin[1]=140;
        szin[2]=70;
    }
    //kilott=0;
    kijelolt=0;
    kivanrajta=0; ///0=senki, 1=fehér, 2=fekete, 3=X
}
/*bool Mezo::kilott_e()
{
    return kilott;
}*/
/*void Mezo::kiloves()
{
    kilott=1;
}*/
void Mezo::rajz()
{
    if (check)
        gout<<move_to(posX,posY)<<color(0,200,0)<<box(sizeX,sizeY);
    else
        gout<<move_to(posX,posY)<<color(szin[0],szin[1],szin[2])<<box(sizeX,sizeY);
    if(kijelolt)
        gout<<move_to(posX,posY)<<color(szin[1]-100,50,50)<<box(sizeX,sizeY);
    if (kivanrajta==3)
        gout<<move_to(posX,posY)<<color(0,0,0)<<line_to(posX+sizeX,posY+sizeY)<<move_to(posX+sizeX,posY)<<line_to(posX,posY+sizeY);

    //bábuk
    int szincsapat=0;
    if (kivanrajta==1 or kivanrajta==2)
    {
        if (kivanrajta==1)
            szincsapat=255;
        if (kivanrajta==2)
            szincsapat=0;
        if (check)
            szincsapat=szincsapat/3+100;
        gout<<move_to(posX+sizeX/3, posY+sizeY/3)<<color(szincsapat,szincsapat,szincsapat)<<box(sizeX/3,sizeY/3);
    }
}
void Mezo::handle(genv::event ev)
{

}
/*int Mezo::kivanrajta_leker()
{
    return kivanrajta;
}
void Mezo::kivanrajta_modosit(int kivan)
{
    kivanrajta=kivan;
}*/
