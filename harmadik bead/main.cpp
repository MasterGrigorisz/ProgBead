#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Master.hpp"

using namespace genv;
using namespace std;

void eventloop()
{

}
int main()
{
    Master tabla_hat(10);
    tabla_hat.rajz();
    event ev;
    while(gin >> ev)
    {
        tabla_hat.rajz();
        if (ev.keycode == 27)
            break;
    }
    return 0;
}
