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
    void csekkelo(genv::event ev);
    void babufelrak();
    void babuleptetes(int x, int y);
protected:
    int darab, mezomeret;
    int babutemp;
    bool voltlepes;
    vector<vector<WidAlap*>> tabla;
    vector<Babu*> feher, fekete;
};

#endif // MASTER_HPP
