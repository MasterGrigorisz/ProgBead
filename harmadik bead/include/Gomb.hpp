#ifndef GOMB_HPP
#define GOMB_HPP
#include "graphics.hpp"
#include "WidAlap.hpp"
#include <sstream>
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;

class Gomb : public WidAlap
{
private:
    //int szam;
    int kattintosszin;
public:
    Gomb(int x, int y, int sx, int sy, int sza);
    void rajz();
    void handle(genv::event ev);

};

#endif // GOMB_HPP
