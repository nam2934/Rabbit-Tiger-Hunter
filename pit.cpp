#include"pit.h"

Pit::Pit(){
    x = 0;
    y = 0;
}

int Pit::get_x(){
    return x;
}

int Pit::get_y(){
    return y;
}
//pit create
void Pit::create(char** grid1){
    srand((unsigned)time(NULL));
    int cor_x;
    int cor_y;
    while(true){
        cor_x = rand()%10;
        cor_y = rand()%10;
        if(grid1[cor_y][cor_x] != 'H' && grid1[cor_y][cor_x] != 'R' && grid1[cor_y][cor_x] != 'T' && grid1[cor_y][cor_x] != '*' && grid1[cor_y][cor_x] != 'O'){
            break;
        }
        else{
            continue;
        }
    }
    x = cor_x;
    y = cor_y;
}

void Pit::set_grid_pit(char** grid_total){
    grid_total[y][x] = 'O';
}