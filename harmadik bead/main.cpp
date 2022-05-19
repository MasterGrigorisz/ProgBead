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
    Master tabla(6);
    event ev;
    tabla.rajz();
    while(gin >> ev)
    {
        tabla.handle(ev);
        if (ev.keycode == 27)
            break;
    }
    return 0;
}
