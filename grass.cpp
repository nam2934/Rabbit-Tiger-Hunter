#include"grass.h"
//constructor
Grass::Grass(){
    x = 0;
    y = 0;
    check_grass_die = 0;
}

int Grass::get_x(){
    return x;
}

int Grass::get_y(){
    return y;
}
//check grass die
int Grass::get_check_grass_die(){
    return check_grass_die;
}

void Grass::set_check_grass_die(int i){
    check_grass_die = i;
}
//create grass
void Grass::create(char** grid1){
    srand((unsigned)time(NULL));
    int cor_x;
    int cor_y;
    while(true){
        cor_x = rand()%10;
        cor_y = rand()%10;
        if(grid1[cor_y][cor_x] != 'H' && grid1[cor_y][cor_x] != 'R' && grid1[cor_y][cor_x] != 'T' && grid1[cor_y][cor_x] != '*'){
            break;
        }
        else{
            continue;
        }
    }
    x = cor_x;
    y = cor_y;
}
//set grid
void Grass::set_grid_grass(char** grid_total){
    grid_total[y][x] = '*';
}