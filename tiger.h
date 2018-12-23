#ifndef TIGER_H
#define TIGER_H

#include<iostream>
#include"critter.h"
#include"grass.h"
#include"rabbit.h"
#include<ctime>
#include<cstdlib>
using namespace std;
//class tiger inheritance by Critter
//almost same as rabbit
class Tiger : public Critter{
    public:
        Tiger();
        void move(char** grid_total, Grass* grass, int number_of_grass, int& g_die, Rabbit* rabbit, int r_num, int& r_die, int* arr_g);
        void breed(char** grid_total, Grass* grass, int number_of_grass, int& g_die, Rabbit* rabbit, int r_num, int& r_die, int& count_add2, Tiger* addtiger, int* arr_g);
        void set_grid_tiger(char** grid_total);
        int get_count_tiger_alive();
        int get_check_fall();
    private:
        int check_fall;
        int tiger_alive;
};

#endif