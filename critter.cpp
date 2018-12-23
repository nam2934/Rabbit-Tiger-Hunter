#include"critter.h"

Critter::Critter(){
    x = 0;
    y = 0;
    lifetime = 3;
}

int Critter::get_x(){
    return x;
}

int Critter::get_y(){
    return y;
}

void Critter::set_x(int cor_x){
    x = cor_x;
}

void Critter::set_y(int cor_y){
    y = cor_y;
}
void Critter::create(char** grid1){
    srand((unsigned)time(NULL));
    int cor_x;
    int cor_y;
    //make random cordinate
    while(true){
        cor_x = rand()%10;
        cor_y = rand()%10;
        if(grid1[cor_y][cor_x] != 'H' && grid1[cor_y][cor_x] != 'R' && grid1[cor_y][cor_x] != 'T'){
            break;
        }
        else{
            continue;
        }
    }
    x = cor_x;
    y = cor_y;
}

int Critter::get_lifetime(){
    return lifetime;
}

void Critter::move(){

}

void Critter::breed(){

}