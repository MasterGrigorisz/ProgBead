#ifndef MASTER_HPP
#define MASTER_HPP
#include "graphics.hpp"
#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "WidAlap.hpp"
#include "Mezo.hpp"
class Master
{
public:
    Master(int darab);
    void rajz();
protected:
    int darab;
    vector<vector<WidAlap*>> tabla;
};

#endif // MASTER_HPP
