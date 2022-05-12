#ifndef BABU_HPP
#define BABU_HPP
#include "WidAlap.hpp"
#include <sstream>
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;

class Babu : public WidAlap
{
public:
    Babu(int x, int y, bool csap, int mezomeret);
    string mitirjonki();
    void rajz();
    void handle(genv::event ev);
    bool tud_e_lepni();
protected:
    bool csapat;
    bool tudlepni;
    int mezomeret;

};
//bool issmallcheckedUP(int egerX, int egerY); //szemet
//bool issmallcheckedDW(int egerX, int egerY); //szemet
#endif // BABU_HPP






