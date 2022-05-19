#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Master.hpp"
#include "Fomenu.hpp"
using namespace genv;
using namespace std;


int main()
{
    event ev;
    Fomenu kezdes;
    Master tabla(kezdes.handle(ev));
    tabla.rajz();
    while(gin >> ev)
    {
        tabla.handle(ev);
        if (ev.keycode == 27)
            break;
    }
    return 0;
}
