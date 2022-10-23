#pragma once
#include "animal.h"
#include <string>
using namespace std;

class hunter : public animal{
private:
    int kills;
    static int nextID;
public:
    hunter(string n, int v);
    int get_kills(){return kills;}
    void set_kills(int s_kills){kills = s_kills;}
    string get_name();
};
