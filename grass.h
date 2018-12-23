#ifndef GRASS_H
#define GRASS_H

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
//class Grass - preserve grass number
class Grass{

    public:
        Grass();
        int get_x();
        int get_y();
        void create(char** grid1);
        void set_grid_grass(char** grid_total);
        int get_check_grass_die();
        void set_check_grass_die(int i);

    private:
        int x;
        int y;
        int check_grass_die;
};

#endif