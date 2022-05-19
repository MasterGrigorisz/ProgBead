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
    void kiloves();
protected:
    int szin[2];
};

#endif // MEZO_HPP
