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
    //vector<vector<WidAlap*>> tabla;
    mezomeret=600/darab;
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
    gout.open(mezomeret*darab+2,mezomeret*darab+2);
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
    while(gin >> ev)
    {
        if (ev.type == ev_mouse and ev.button==btn_left)
            for (vector<WidAlap *> lepes : tabla)
                for (WidAlap * lepes2 : lepes)
                {
                    if (lepes2->ischecked(ev.pos_x, ev.pos_y))
                        lepes2->check=1;
                    if (!lepes2->ischecked(ev.pos_x, ev.pos_y))
                        lepes2->check=0;
                }
    }
}
void Master::babufelrak(genv::event ev)
{
    int babudarab=1;
    if (darab==6)
        babudarab=2;
    if (darab==8)
        babudarab=3;
    if (darab==10)
        babudarab=4;

    Babu* ujw1 =new Babu (0,3,1,mezomeret);
    Babu* ujw2 =new Babu (3,0,1,mezomeret);
    Babu* ujw3 =new Babu (6,0,1,mezomeret);
    Babu* ujw4 =new Babu (9,3,1,mezomeret);

    Babu* ujb1 =new Babu (0,6,0,mezomeret);
    Babu* ujb2 =new Babu (3,9,0,mezomeret);
    Babu* ujb3 =new Babu (6,9,0,mezomeret);
    Babu* ujb4 =new Babu (9,6,0,mezomeret);
    int iksz, ipszilon, pozix=0, poziy=0;
    while(gin >> ev)
    {
        if (ev.type == ev_mouse and ev.button==btn_left)
        {

            iksz= ev.pos_x;
            ipszilon= ev.pos_y;
            while(iksz>-1)
            {
                iksz-=mezomeret;
                pozix++;
            }
            while(ipszilon>-1)
            {
                ipszilon-=mezomeret;
                poziy++;
            }
            int szorzo=0;
            for (int i=0; i<babudarab; i++)
            {
                szorzo=1-i%2;
                Babu* ujw =new Babu (pozix*i*2,poziy*szorzo,1,mezomeret);
                Babu* ujb =new Babu (pozix*i,darab-1-poziy*szorzo,0,mezomeret);
                feher.push_back(ujw);
                fekete.push_back(ujb);
            }
            break;
        }
    }
}
