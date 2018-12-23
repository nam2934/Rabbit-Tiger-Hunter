#ifndef RABBIT_H
#define RABBIT_H

#include<iostream>
#include"critter.h"
#include"grass.h"
#include<ctime>
#include<cstdlib>
using namespace std;
//class rabbit inheritance by Critter
class Rabbit : public Critter{
    public:
        Rabbit();
        //move
        void move(char** grid_total, Grass* grass, int number_of_grass, int& g_die, int* arr_g);
        //breed
        void breed(char** grid_total, Grass* grass, int number_of_grass, int& g_die, int& count_add, Rabbit* addrabbit, int* arr_g);
        //set rabbit
        void set_grid_rabbit(char** grid_total);
        //count rabbit life
        void count_rabbit_alive();
        int get_count_rabbit_alive();
        int get_check_fall();
        void set_check_rabbit_die(int i);
        int get_check_rabbit_die();
    private:
        int check_fall;
        int check_rabbit_die;
        int rabbit_alive;
};

#endif