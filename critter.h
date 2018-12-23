#ifndef CRITTER_H
#define CRITTER_H

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

//class critter - getter and setter of critter's cordinate
class Critter{
    public:
        Critter();
        int get_x();
        int get_y();
        void set_x(int cor_x);
        void set_y(int cor_y);
        void create(char** grid1);
        int get_lifetime();
        virtual void move();
        virtual void breed(); 

    protected:
        int x;
        int y;
        int lifetime;
};

#endif