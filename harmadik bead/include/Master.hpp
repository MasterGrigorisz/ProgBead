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
    void vane_a_mezonbabu();
    void babulevetel();
    void babuatrako();


    int darab, mezomeret;
    int babuszintemp;
    bool voltlepes;
    int lepeskijeloloX, lepeskijeloloY;
    void sorabanvan_jelolo();
    vector<vector<WidAlap*>> tabla;
    vector<Babu*> feher, fekete;
};

#endif // MASTER_HPP
