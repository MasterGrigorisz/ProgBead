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
#include "Babu.hpp"
class Master
{
public:
    Master(int darab);
    void rajz();
    void handle(genv::event ev);
    void babufelrak(genv::event ev);

protected:
    int darab, mezomeret;
    vector<vector<WidAlap*>> tabla;
    vector<Babu*> feher, fekete;
};

#endif // MASTER_HPP
