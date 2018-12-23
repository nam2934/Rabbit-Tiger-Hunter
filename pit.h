#ifndef PIT_H
#define PIT_H

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
//class Pit - if hunter, rabbit, tiger fall into the pit -> die
class Pit{

    public:
        Pit();
        int get_x();
        int get_y();
        void create(char** grid1);
        void set_grid_pit(char** grid_total);

    private:
        int x;
        int y;
};

#endif