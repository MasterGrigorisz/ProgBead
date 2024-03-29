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
    ki_kovetkezik=1;
    voltloves=0;
    NemtudLepni_e=0;
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
}
void Master::rajz()
{
    for (vector<WidAlap *> lepes : tabla) ///mezo
        for (WidAlap * lepes2 : lepes)
            lepes2->rajz();
    gout<<refresh;
}
void Master::handle_seged(event ev, int kijon)
{
    if (ev.type == ev_mouse and ev.button==btn_left)
    {
        csekkelo(ev);
        for (vector<WidAlap *> lepes : tabla)
            for (WidAlap * lepes2 : lepes)
                if (lepes2->check and lepes2->kivanrajta==kijon)
                {

                    vane_a_mezonbabu();
                    sorabanvan_jelolo();
                    rajz();

                    for (vector<WidAlap *> lepes : tabla)
                        for (WidAlap * lepes2 : lepes)
                            if (lepes2->kijelolt)
                                NemtudLepni_e++;
                    if (NemtudLepni_e==0)
                    {
                        NemtudLepni_e=0-kijon;
                        break;
                    }
                    babuatrako();
                    babulevetel();
                    if (voltlepes)
                    {
                        for (vector<WidAlap *> lepes : tabla)
                            for (WidAlap * lepes2 : lepes)
                                lepes2->kijelolt=0;
                        rajz();
                        voltloves=0;
                    }
                    voltlepes=0;
                    vane_a_mezonbabu();
                    sorabanvan_jelolo();
                    rajz();
                    if(!voltloves)
                    {
                        lojunk(ev);
                    }
                }
    }
}
void Master::handle(genv::event ev)
{
    if (NemtudLepni_e==-1)
    {
        jatekvege(2);
        NemtudLepni_e=-3;
        ki_kovetkezik=0;
    }
    if (NemtudLepni_e==-2)
    {
        jatekvege(1);
        NemtudLepni_e=-3;
        ki_kovetkezik=0;
    }
    if (ki_kovetkezik==1) //fehér jön
    {
        NemtudLepni_e=0;
        handle_seged(ev,1);
        handle_seged(ev,0);
    }
    if (ki_kovetkezik==2) //fekete jön
    {
        NemtudLepni_e=0;
        handle_seged(ev,2);
        handle_seged(ev,0);
    }
}
void Master::jatekvege(int gyoztes)
{
    stringstream sss;
    int szin=0;
    if (gyoztes==1)
    {
        szin=255;
        sss<<"Nyertes:"<<endl<<" Feher";
    }
    else
        sss<<"Nyertes:"<<endl<<" Fekete";
    gout<<move_to(mezomeret*darab/5*2,mezomeret*darab/5*2)<<color(szin,szin,szin)<<box(mezomeret*darab/5,mezomeret*darab/5)
        <<move_to(mezomeret*darab/5*2+mezomeret/6,mezomeret*darab/5*2+mezomeret/2)<<color(255-szin,255-szin,255-szin)<<text(sss.str())
        <<refresh;
}
void Master::lojunk(event ev)
{
    if (ev.type == ev_mouse and ev.button==btn_left)
        for (vector<WidAlap *> lepes1 : tabla)
            for (WidAlap * lepes2 : lepes1)
                if (lepes2->ischecked(ev.pos_x, ev.pos_y) and lepes2->kijelolt)
                {
                    lepes2->kivanrajta_modosit(3);              ///loves
                    for (vector<WidAlap *> lepes3 : tabla)
                        for (WidAlap * lepes4 : lepes3)
                            lepes4->kijelolt=0;
                    voltloves=1;
                    ki_kovetkezik=ki_kovetkezik%2+1;
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
    if (lepeskijeloloY>=0 and lepeskijeloloX>=0)
    {
        bool    utkozveXYY=1, //jobbra
                utkozveXXYY=1, //jobbra le
                utkozveXXY=1, //lefele
                utkozveXXyy=1, //balra le
                utkozveXyy=1, //balra
                utkozvexxyy=1, //balra fel
                utkozvexxY=1, //felfele
                utkozvexxYY=1 //jobbra fel
                            ; //Kódolás: nagybetü: pozitív irányba indul,    kisbetü: negatív irányba indul,    1db betü: stabil

        int seged1=1, seged2=1, seged3=1, seged4=1;
        for(int i=0; i<darab; i++)
            for(int j=0; j<darab; j++)
            {
                if (lepeskijeloloY<i and lepeskijeloloX==j and utkozveXXY) //LE
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozveXXY=0;
                }
                if (lepeskijeloloY==i and lepeskijeloloX<j and utkozveXYY) //JOBBRA
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozveXYY=0;
                }
                if (lepeskijeloloY+seged1==i and lepeskijeloloX+seged1==j  and utkozveXXYY) //JOBBRA LE
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozveXXYY=0;
                    seged1++;
                }

                if (lepeskijeloloY+seged2==i and lepeskijeloloX-seged2==j  and utkozveXXyy) //balra LE
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozveXXyy=0;
                    seged2++;
                }
            }
        for(int i=darab-1; 0<=i; i--)
            for(int j=darab-1; 0<=j; j--)
            {
                if (lepeskijeloloY>i and lepeskijeloloX==j and utkozvexxY) //FEL         //
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozvexxY=0;
                }
                if (lepeskijeloloY==i and lepeskijeloloX>j and utkozveXyy) //BALRA           //
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozveXyy=0;
                }
                if (lepeskijeloloY-seged3==i and lepeskijeloloX+seged3==j  and utkozvexxYY) //JOBBRA fel        //
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozvexxYY=0;
                    seged3++;
                }
                if (lepeskijeloloY-seged4==i and lepeskijeloloX-seged4==j  and utkozvexxyy) //barla fel      //
                {
                    if (tabla[i][j]->kivanrajta==0)
                        tabla[i][j]->kijelolt=1;
                    else
                        utkozvexxyy=0;
                    seged4++;
                }
            }
        lepeskijeloloX=-1;
        lepeskijeloloY=-1;
    }
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
            if (lepes2->check and (lepes2->kivanrajta==1 or lepes2->kivanrajta==2) and !voltlepes)
            {
                babuszintemp=lepes2->kivanrajta;
                lepes2->kivanrajta_modosit(0);

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
