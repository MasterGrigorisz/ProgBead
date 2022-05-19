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
    babuszintemp=-1;
    voltlepes=0;
    lepeskijeloloX=-1;
    lepeskijeloloY=-1;
    for (int i=0; i<darab; i++) ///MEZO
    {
        vector<WidAlap*> pakolos;
        for (int j=0; j<darab; j++)
        {
            Mezo* rakjad =new Mezo(mezomeret*j,mezomeret*i,mezomeret,mezomeret,j,i);
            //cout<<j<<" master const "<<i<<endl;
            pakolos.push_back(rakjad);
        }
        tabla.push_back(pakolos);
    }
    gout.open(mezomeret*darab,mezomeret*darab);
    babufelrak();

    for (vector<WidAlap *> lepes : tabla) ///random nullazas mert nyûgös
        for (WidAlap * lepes2 : lepes)
            ;//lepes2->check=0;
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

        csekkelo(ev);
        vane_a_mezonbabu();
        sorabanvan_jelolo();
        rajz();

        babuatrako();
        babulevetel();
        if (voltlepes)
        {
            for (vector<WidAlap *> lepes : tabla)
                for (WidAlap * lepes2 : lepes)
                    lepes2->kijelolt=0;
            rajz();
        }
        voltlepes=0;


    }
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
            /*if (babuszintemp!=-1 and lepes2->check)
            {
                lepes2->kivanrajta_modosit(babuszintemp);
                babuszintemp=-1;
                voltlepes=1;
            }*/
        }
}
void Master::vane_a_mezonbabu()
{
    for (vector<WidAlap *> lepes1 : tabla)
        for (WidAlap * lepes2 : lepes1)
            if (lepes2->check and (lepes2->kivanrajta==1 or lepes2->kivanrajta==2))
            {
                lepeskijeloloX=lepes2->tablaposX;
                lepeskijeloloY=lepes2->tablaposY;
            }
}

void Master::sorabanvan_jelolo()
{
    //reset
    /*for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
                lepes2->kijelolt=0;*/
    //--
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

        kar2=0;
        for (WidAlap * lepes2 : lepes1)
        {
            if (lepeskijeloloY>=lepeskijeloloY-kar1-1 and lepeskijeloloX==kar2 and utkozveXYY) //FEL          ///
            {
                if (lepes2->kivanrajta==0)
                    lepes2->kijelolt=1;
                else
                    utkozveXYY=0;
            }
            if (lepeskijeloloY<kar1 and lepeskijeloloX==kar2 and utkozveXyy) //LE
            {
                if (lepes2->kivanrajta==0)
                    lepes2->kijelolt=1;
                else
                    utkozveXyy=0;
            }
            if (lepeskijeloloY==kar1 and lepeskijeloloX>kar2 and utkozveXXY) //BALRA            ////
            {
                if (lepes2->kivanrajta==0)
                    lepes2->kijelolt=1;
                else
                    utkozveXXY=0;
            }
            if (lepeskijeloloY==kar1 and lepeskijeloloX<kar2 and utkozvexxY) //JOBBRA
            {
                if (lepes2->kivanrajta==0)
                    lepes2->kijelolt=1;
                else
                    utkozvexxY=0;
            }
            kar2++;
        }
        kar1++;
    }
    int lept=0;
}

void Master::babuatrako()
{
    for (vector<WidAlap *> lepes1 : tabla)
        for (WidAlap * lepes2 : lepes1)
            if (babuszintemp!=-1 and lepes2->check and lepes2->kijelolt)
            {
                lepes2->kivanrajta_modosit(babuszintemp);
                babuszintemp=-1;
                voltlepes=1;
            }
}
void Master::babulevetel()
{
    for (vector<WidAlap *> lepes1 : tabla) //ha van bábu a mezőn, lépjünk vele
        for (WidAlap * lepes2 : lepes1)
        {
            if (lepes2->check and (lepes2->kivanrajta==1 or lepes2->kivanrajta==2) and !voltlepes)
            {
                babuszintemp=lepes2->kivanrajta;
                lepes2->kivanrajta_modosit(0);

            }//lepes2->kijelolt=0;
        }
}
void Master::babufelrak()
{
    if (darab==6)
    {
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
            {
                if(lepes2->tablaposX==0 and lepes2->tablaposY==2)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==3 and lepes2->tablaposY==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==5 and lepes2->tablaposY==3)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablaposX==2 and lepes2->tablaposY==5)
                    lepes2->kivanrajta_modosit(2);
            }
    }
    if (darab==8)
    {
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
            {
                if(lepes2->tablaposX==0 and lepes2->tablaposY==2)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==3 and lepes2->tablaposY==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==7 and lepes2->tablaposY==1)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==0 and lepes2->tablaposY==6)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablaposX==4 and lepes2->tablaposY==7)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablaposX==7 and lepes2->tablaposY==5)
                    lepes2->kivanrajta_modosit(2);
            }
    }
    if (darab==10)
    {
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
            {
                if(lepes2->tablaposX==0 and lepes2->tablaposY==3)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==3 and lepes2->tablaposY==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==6 and lepes2->tablaposY==0)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==9 and lepes2->tablaposY==3)
                    lepes2->kivanrajta_modosit(1);
                if(lepes2->tablaposX==0 and lepes2->tablaposY==6)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablaposX==3 and lepes2->tablaposY==9)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablaposX==6 and lepes2->tablaposY==9)
                    lepes2->kivanrajta_modosit(2);
                if(lepes2->tablaposX==9 and lepes2->tablaposY==6)
                    lepes2->kivanrajta_modosit(2);
            }
    }
}
