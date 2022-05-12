#ifndef MEZO_HPP
#define MEZO_HPP
#include "WidAlap.hpp"
#include <sstream>
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;
class Mezo : public WidAlap
{
public:
    Mezo(int x, int y, int sx, int sy, int Tx, int Ty);
    void rajz();
    void handle(genv::event ev);
    bool kilott_e();
    //bool issmallcheckedUP(int egerX, int egerY); //szemet
    //bool issmallcheckedDW(int egerX, int egerY); //szemet
    string mitirjonki();
    void kiloves();
protected:
    int szin[2];
    int tablapos[1];
    bool kilott;
    int kivanrajta;
    bool kijelolt;

};

#endif // MEZO_HPP
