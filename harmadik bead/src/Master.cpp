#include "Master.hpp"
#include "graphics.hpp"
#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "WidAlap.hpp"
#include "Mezo.hpp"
#include "Babu.hpp"
using namespace genv;
using namespace std;
Master::Master(int dar)
{
    darab=dar;
    mezomeret=69;
    babutemp=-1;
    voltlepes=0;
    lepeskijelolo[0]=-1;
    lepeskijelolo[1]=-1;
    for (int i=0; i<darab; i++) ///MEZO
    {
        vector<WidAlap*> pakolos;
        for (int j=0; j<darab; j++)
        {
            Mezo* rakjad =new Mezo(mezomeret*j,mezomeret*i,mezomeret,mezomeret,j,i);
            pakolos.push_back(rakjad);
        }
        tabla.push_back(pakolos);
    }
    gout.open(mezomeret*darab,mezomeret*darab);
    babufelrak();

    for (vector<WidAlap *> lepes : tabla) ///random nullazas mert nyûgös
        for (WidAlap * lepes2 : lepes)
            lepes2->check=0;
}
void Master::rajz()
{
    for (vector<WidAlap *> lepes : tabla) ///mezo
        for (WidAlap * lepes2 : lepes)
            lepes2->rajz();
    gout<<refresh;
}
void Master::handle(genv::event ev)
{



    if (ev.type == ev_mouse and ev.button==btn_left)
    {
        ///lépés---
        for (vector<WidAlap *> lepes1 : tabla) //ha van bábu a mezőn, lépjünk vele
            for (WidAlap * lepes2 : lepes1)
                if (lepes2->check and (lepes2->kivanrajta==1 or lepes2->kivanrajta==2) and !voltlepes)
                {
                    babutemp=lepes2->kivanrajta;
                    lepes2->kivanrajta_modosit(0);
                }
        //jelöljük ki hova léphet
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
                if (lepes2->check and (lepes2->kivanrajta==1 or lepes2->kivanrajta==2))
                {
                    lepeskijelolo[0]=lepes2->tablapos[0];
                    lepeskijelolo[1]=lepes2->tablapos[1];
                }
        sorabanvan_jelolo();

        ///---
        voltlepes=0;
        csekkelo(ev);
    }

    rajz();
}
void Master::sorabanvan_jelolo()
{
    //reset
    /*for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
                lepes2->kijelolt=0;
    //--*/
    cout<<lepeskijelolo[0]<<" : "<<lepeskijelolo[1]<<endl;
    bool    utkozveXYY=1, //jobbra
            utkozveXXYY=1, //jobbra le
            utkozveXXY=1, //lefele
            utkozveXXyy=1, //balra le
            utkozveXyy=1, //balra
            utkozvexxyy=1, //balra fel
            utkozvexxY=1, //felfele
            utkozvexxYY=1 //jobbra fel
            ; //Kódolás: nagybetü: pozitív irányba indul,    kisbetü: negatív irányba indul,    1db betü: stabil
    int kar1=0, kar2;
    for (vector<WidAlap *> lepes1 : tabla)
    {
        kar1++;
        kar2=0;
        for (WidAlap * lepes2 : lepes1)
        {
            if (lepeskijelolo[0]<kar1 and lepeskijelolo[1]==kar2 and utkozveXYY) //jobbra
            {
                if (lepes2->kivanrajta==0)
                    lepes2->kijelolt=1;
                else
                    utkozveXYY=0;
            }
            if (lepeskijelolo[0]<kar1 and lepeskijelolo[1]==kar2 and utkozveXYY) //jobbra le
            {
                if (lepes2->kivanrajta==0)
                    lepes2->kijelolt=1;
                else
                    utkozveXYY=0;
            }



        }
    }

    int lept=0;
    /*for (int i=lepeskijelolo[0]; i<=darab;i++)
            tabla[lepeskijelolo[0],lepeskijelolo[1]+lept]->kijelolt=1;*/


    /*if (lepes2->tablapos[0]==lepeskijelolo[0] or lepes2->tablapos[1]==lepeskijelolo[1])
        lepes2->kijelolt=1;*/
}
void Master::csekkelo(genv::event ev)
{
    for (vector<WidAlap *> lepes1 : tabla)
        for (WidAlap * lepes2 : lepes1)
        {
            if (lepes2->ischecked(ev.pos_x, ev.pos_y))
                lepes2->check=1;
            if (!lepes2->ischecked(ev.pos_x, ev.pos_y))
                lepes2->check=0;
            if (babutemp!=-1 and lepes2->check)
            {
                lepes2->kivanrajta_modosit(babutemp);
                babutemp=-1;
                voltlepes=1;
            }
        }

}
void Master::babufelrak()
{
    if (darab==6)
    {
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
            {
                if(lepes2->tablapos[0]==0 and lepes2->tablapos[1]==2)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==3 and lepes2->tablapos[1]==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==5 and lepes2->tablapos[1]==3)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablapos[0]==2 and lepes2->tablapos[1]==5)
                    lepes2->kivanrajta_modosit(2);
            }
    }
    if (darab==8)
    {
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
            {
                if(lepes2->tablapos[0]==0 and lepes2->tablapos[1]==2)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==3 and lepes2->tablapos[1]==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==7 and lepes2->tablapos[1]==1)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==0 and lepes2->tablapos[1]==6)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablapos[0]==4 and lepes2->tablapos[1]==7)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablapos[0]==7 and lepes2->tablapos[1]==5)
                    lepes2->kivanrajta_modosit(2);
            }
    }
    if (darab==10)
    {
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
            {
                if(lepes2->tablapos[0]==0 and lepes2->tablapos[1]==3)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==3 and lepes2->tablapos[1]==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==6 and lepes2->tablapos[1]==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==9 and lepes2->tablapos[1]==3)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablapos[0]==0 and lepes2->tablapos[1]==6)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablapos[0]==3 and lepes2->tablapos[1]==9)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablapos[0]==6 and lepes2->tablapos[1]==9)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablapos[0]==9 and lepes2->tablapos[1]==6)
                    lepes2->kivanrajta_modosit(2);
            }
    }
}
