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
    void handle(genv::event ev);
protected:
    void csekkelo(genv::event ev);
    void babufelrak();
    void babuleptetes(int x, int y);
    void vane_a_mezonbabu();
    void babulevetel();
    void babuatrako();
    void lojunk(event ev);
    void handle_seged(event ev, int kijon);
    void sorabanvan_jelolo();
    void jatekvege(int gyoztes);

    int darab, mezomeret,ki_kovetkezik, babuszintemp, lepeskijeloloX, lepeskijeloloY, NemtudLepni_e;
    bool voltlepes, voltloves ;
    vector<vector<WidAlap*>> tabla;
};

#endif // MASTER_HPP
