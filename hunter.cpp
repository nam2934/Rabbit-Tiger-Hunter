#include"hunter.h"
//various hunter's function : move, HP, score, potion
Hunter::Hunter() : Critter(){
    score = 0;
    HP = 5;
    potion = 0;
}

void Hunter::set_grid_hunter(char** grid_total){
    grid_total[y][x] = 'H';
}

void Hunter::move_up(char** grid_total){
    grid_total[y-1][x] = 'H';
    grid_total[y][x] = '-';
    y -= 1;
}

void Hunter::move_down(char** grid_total){
    grid_total[y+1][x] = 'H';
    grid_total[y][x] = '-';
    y += 1;
}

void Hunter::move_left(char** grid_total){
    grid_total[y][x-1] = 'H';
    grid_total[y][x] = '-';
    x -= 1;
}

void Hunter::move_right(char** grid_total){
    grid_total[y][x+1] = 'H';
    grid_total[y][x] = '-';
    x += 1;
}

void Hunter::move_down_left(char** grid_total){
    grid_total[y+1][x-1] = 'H';
    grid_total[y][x] = '-';
    x -= 1;
    y += 1;
}

void Hunter::move_down_right(char** grid_total){
    grid_total[y+1][x+1] = 'H';
    grid_total[y][x] = '-';
    x += 1;
    y += 1;
}

void Hunter::move_up_left(char** grid_total){
    grid_total[y-1][x-1] = 'H';
    grid_total[y][x] = '-';
    x -= 1;
    y -= 1;
}

void Hunter::move_up_right(char** grid_total){
    grid_total[y-1][x+1] = 'H';
    grid_total[y][x] = '-';
    x += 1;
    y -= 1;
}

void Hunter::HP_decrease(){
    HP--;
}

void Hunter::score_increase_1(){
    score++;
}

void Hunter::score_increase_2(){
    score += 2;
}

void Hunter::HP_increase_2(){
    HP += 2;
}

void Hunter::HP_increase_max(){
    HP = 5;
}

void Hunter::potion_decrease(){
    potion--;
}

int Hunter::get_HP(){
    return HP;
}

int Hunter::get_score(){
    return score;
}

int Hunter::get_potion(){
    return potion;
}

void Hunter::set_HP(int hp){
    HP = hp;
}

void Hunter::set_score(int sc){
    score = sc;
}

void Hunter::set_potion(int pt){
    potion = pt;
}