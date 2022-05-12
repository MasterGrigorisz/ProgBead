#include "Master.hpp"
#include "graphics.hpp"
#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "WidAlap.hpp"
#include "Mezo.hpp"
using namespace genv;
using namespace std;
Master::Master(int dar)
{
    darab=dar;
    //vector<vector<WidAlap*>> tabla;
    int  mezomeret=600/darab;
    for (int i=0; i<darab; i++)
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
    for (vector<WidAlap *> lepes : tabla)
        for (WidAlap * lepes2 : lepes)
            lepes2->rajz();
    gout<<refresh;
}
