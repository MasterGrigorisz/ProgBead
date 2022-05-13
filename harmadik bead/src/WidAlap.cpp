#include "WidAlap.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>
using namespace std;
using namespace genv;
WidAlap::WidAlap(int x, int y, int sx, int sy) : posX(x), posY(y), sizeX(sx), sizeY(sy)
{
    check=0;
}
bool WidAlap::ischecked(int egerX, int egerY)
{
    return  egerX > posX            and
            egerX < posX + sizeX    and
            egerY > posY            and
            egerY < posY + sizeY;
}

