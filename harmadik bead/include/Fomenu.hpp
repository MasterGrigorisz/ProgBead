#ifndef FOMENU_HPP
#define FOMENU_HPP
#include "WidAlap.hpp"
#include "graphics.hpp"
#include <vector>
#include "Gomb.hpp"
using namespace std;
using namespace genv;
class Fomenu
{
    public:
        Fomenu();
    vector<WidAlap*> lista;
    int handle(event ev);
    int chosen;
};

#endif // FOMENU_HPP
