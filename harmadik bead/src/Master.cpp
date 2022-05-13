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

    for (vector<WidAlap *> lepes : tabla) ///random nullazas mert ny�g�s
        for (WidAlap * lepes2 : lepes)
            lepes2->check=0;
}
void Master::rajz()
{
    for (vector<WidAlap *> lepes : tabla) ///mezo
        for (WidAlap * lepes2 : lepes)
            lepes2->rajz();
    for (Babu * lepo : feher) //feher babu
        lepo->rajz();
    for (Babu * lepo : fekete) //fekete babu
        lepo->rajz();

    gout<<refresh;
}
void Master::handle(genv::event ev)
{
    {
        if (ev.type == ev_mouse and ev.button==btn_left)
        {
            csekkelo(ev);
        }
    }
    rajz();
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