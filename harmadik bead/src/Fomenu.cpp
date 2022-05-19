#include "Fomenu.hpp"

Fomenu::Fomenu()
{
    Gomb *gombocska_1 =new Gomb(10,10,100,40,6);
    Gomb *gombocska_2 =new Gomb(10,60,100,40,8);
    Gomb *gombocska_3 =new Gomb(10,110,100,40,10);
    lista.push_back(gombocska_1);
    lista.push_back(gombocska_2);
    lista.push_back(gombocska_3);
    gout.open(120,200);
    for (WidAlap * lepes : lista)
        lepes->rajz();
    gout<<move_to(20,175)<<color(255,255,255)<<text("Feher kezd")<<refresh;
}
int Fomenu::handle(event ev)
{
    bool porogj=1;
    while(gin >> ev and porogj)
    {
        if (ev.type == ev_mouse and ev.button==btn_left)
        {
            for (WidAlap * lepes : lista)
            {
                if (lepes->ischecked(ev.pos_x, ev.pos_y))
                    lepes->check=1;
                if (!lepes->ischecked(ev.pos_x, ev.pos_y))
                    lepes->check=0;
            }
            for (WidAlap * lepes : lista)
            lepes->rajz();
            for (WidAlap * lepes : lista)
                if(lepes->check)
                    porogj=0;
        }
    }
    for (WidAlap * lepes : lista)
            if(lepes->check)
                    return lepes->szam;
}
