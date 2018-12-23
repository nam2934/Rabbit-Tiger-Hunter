#ifndef HUNTER_H
#define HUNTER_H

#include<iostream>
#include"critter.h"

using namespace std;

#include"rabbit.h"
#include"tiger.h"
//class Hunter - inheritance of Critter : get xy_cordinate
class Hunter : public Critter{
    public:
        Hunter();
        void set_grid_hunter(char** grid_total);
        void move_up(char** grid_total);
        void move_down(char** grid_total);
        void move_left(char** grid_total);
        void move_right(char** grid_total);
        void move_up_right(char** grid_total);
        void move_up_left(char** grid_total);
        void move_down_right(char** grid_total);
        void move_down_left(char** grid_total);
        void HP_decrease();
        void score_increase_1();
        void score_increase_2();
        void HP_increase_2();
        void HP_increase_max();
        void potion_decrease();
        int get_score();
        int get_HP();
        int get_potion();
        void set_score(int sc);
        void set_HP(int hp);
        void set_potion(int pt);

    private:
        int score;
        int HP;
        int potion;
};

#endif