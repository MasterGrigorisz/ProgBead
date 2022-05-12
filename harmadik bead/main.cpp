#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Master.hpp"

using namespace genv;
using namespace std;

int main()
{
    Master tabla(10);
    tabla.rajz();
    event ev;
    tabla.babufelrak(ev);
    tabla.rajz();
    while(gin >> ev)
    {
        tabla.rajz();
        tabla.handle(ev);
        if (ev.keycode == 27)
            break;
    }
    return 0;
}
