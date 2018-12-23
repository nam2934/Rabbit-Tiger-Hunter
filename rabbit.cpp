#include"rabbit.h"
//various rabbiy function
Rabbit::Rabbit() : Critter() {
    check_fall = 0;
    check_rabbit_die = 0;
    rabbit_alive = 0;
}

int Rabbit::get_check_fall(){
    return check_fall;
}

int Rabbit::get_check_rabbit_die(){
    return check_rabbit_die;
}

void Rabbit::set_check_rabbit_die(int i){
    check_rabbit_die = 1;
}

void Rabbit::count_rabbit_alive(){
    rabbit_alive++;
}

int Rabbit::get_count_rabbit_alive(){
    return rabbit_alive;
}
//move rabbit
void Rabbit::move(char** grid_total, Grass* grass,int number_of_grasses,int& g_die, int* arr_g){
    //random number 1,2,3,4
    int number4 = rand()%4 + 1;
    int count=0;
    
    //make new grid set 12x12 - because of index -1
    char** grid_new = new char*[12];
    for (int i = 0; i < 12; i++) {
		grid_new[i] = new char[12];
	}
    for(int i = 0; i< 12; i++){
        for(int j = 0; j< 12; j++){
            grid_new[i][j] = 'x';
        }
    }

    for(int i=1; i<11; i++){
        for(int j= 1; j<11; j++){
            grid_new[i][j] = grid_total[i-1][j-1];
        }
    }

    //if grass in adject cell
    if(grid_new[y+1][x+2] == '*' || grid_new[y+2][x+1] == '*' || grid_new[y][x+1] == '*' || grid_new[y+1][x] == '*'){
        if(grid_new[y+1][x+2] == '*') count++; //right
        if(grid_new[y+2][x+1] == '*') count++; //down
        if(grid_new[y][x+1] == '*') count++; //up
        if(grid_new[y+1][x] == '*') count++; //left
        //if grass not in custom direction -> try again
        while(count != 0){
            int number = rand()%4 + 1;
            //right
            if(number == 1){
                if(grid_new[y+1][x+2] == '*'){
                    grid_total[y][x+1] = 'R';
                    grid_total[y][x] = '-';
                    x++;
                    lifetime = 3;
                    rabbit_alive++;
                    int i;
                    for(i = 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
                    break;
                }
                else continue;
            }
            //down
            if(number == 2){
                if(grid_new[y+2][x+1] == '*'){
                    grid_total[y+1][x] = 'R';
                    grid_total[y][x] = '-';
                    y++;
                    lifetime = 3;
                    rabbit_alive++;
                    int i;
                    for(i= 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
                    break;
                }
                else continue;
            }
            //up
            if(number == 3){
                if(grid_new[y][x+1] == '*'){
                    grid_total[y-1][x] = 'R';
                    grid_total[y][x] = '-';
                    y--;
                    lifetime = 3;
                    rabbit_alive++;
                    int i;
                    for(i = 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
                    break;
                }
                else continue;
            }
            //left
            if(number == 4){
                if(grid_new[y+1][x] == '*'){
                    grid_total[y][x-1] = 'R';
                    grid_total[y][x] = '-';
                    x--;
                    lifetime = 3;
                    rabbit_alive++;
                    int i;
                    for(i = 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
                    break;
                }
                else continue;
            }
        }
    }
    else{
        if(number4 == 1){//up
            if(y == 0){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y-1][x] == '-'){
                grid_total[y-1][x] = 'R';
                grid_total[y][x] = '-';
                y--;
                if(lifetime > 0) lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y-1][x] == 'H'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y-1][x] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
            }
            else if(grid_total[y-1][x] == 'T'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y-1][x] == 'R'){
                lifetime--;
                rabbit_alive++;
            }
        }

        else if(number4 == 2){//down
            if(y==9){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y+1][x] == '-'){
                grid_total[y+1][x] = 'R';
                grid_total[y][x] = '-';
                y++;
                if(lifetime > 0) lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y+1][x] == 'H'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y+1][x] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
            }
            else if(grid_total[y+1][x] == 'T'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y+1][x] == 'R'){
                lifetime--;
                rabbit_alive++;
            }
        }

        else if(number4 == 3){//left
            if(x==0){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x-1] == '-'){
                grid_total[y][x-1] = 'R';
                grid_total[y][x] = '-';
                x--;
                if(lifetime > 0) lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x-1] == 'H'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x-1] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
            }
            else if(grid_total[y][x-1] == 'T'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x-1] == 'R'){
                lifetime--;
                rabbit_alive++;
            }
        }

        else if(number4 == 4){//right
            if(x==9){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x+1] == '-'){
                grid_total[y][x+1] = 'R';
                grid_total[y][x] = '-';
                x++;
                if(lifetime > 0) lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x+1] == 'H'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x+1] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
            }
            else if(grid_total[y][x+1] == 'T'){
                lifetime--;
                rabbit_alive++;
            }
            else if(grid_total[y][x+1] == 'R'){
                lifetime--;
                rabbit_alive++;
            }
        }
    }
    delete[] grid_new;
}
//breed rabbit
void Rabbit::breed(char** grid_total, Grass* grass,int number_of_grasses,int& g_die, int& count_add, Rabbit* addrabbit, int* arr_g){
    int number4 = rand()%4 + 1;
    int count=0;
    
    //new grid 12x12
    char** grid_new = new char*[12];
    for (int i = 0; i < 12; i++) {
		grid_new[i] = new char[12];
	}
    for(int i = 0; i< 12; i++){
        for(int j = 0; j< 12; j++){
            grid_new[i][j] = 'x';
        }
    }

    for(int i=1; i<11; i++){
        for(int j= 1; j<11; j++){
            grid_new[i][j] = grid_total[i-1][j-1];
        }
    }
    if(grid_new[y+1][x+2] == '-' || grid_new[y+2][x+1] == '-' || grid_new[y][x+1] == '-' || grid_new[y+1][x] == '-' || grid_new[y+1][x+2] == '*' || grid_new[y+2][x+1] == '*' || grid_new[y][x+1] == '*' || grid_new[y+1][x] == '*'){
        if(grid_new[y+1][x+2] == '-') count++; //right
        if(grid_new[y+1][x+2] == '*') count++; //right
        if(grid_new[y+2][x+1] == '-') count++; //down
        if(grid_new[y+2][x+1] == '*') count++; //down
        if(grid_new[y][x+1] == '-') count++; //up
        if(grid_new[y][x+1] == '*') count++; //up
        if(grid_new[y+1][x] == '-') count++; //left
        if(grid_new[y+1][x] == '*') count++; //left
        while(count != 0){
            int number = rand()%4 + 1;
            if(number == 1){
                if(grid_new[y+1][x+2] == '*'){
                    grid_total[y][x+1] = 'R';
                    int i;
                    for(i = 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x + 1){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add += 1;
					addrabbit[count_add - 1].set_x(x + 1);
					addrabbit[count_add - 1].set_y(y);
                    break;
                }
                else if(grid_new[y+1][x+2] == '-'){
                    grid_total[y][x+1] = 'R';
					count_add += 1;
					addrabbit[count_add - 1].set_x(x + 1);
					addrabbit[count_add - 1].set_y(y);
                    break;
                }
                else continue;
            }

            if(number == 2){
                if(grid_new[y+2][x+1] == '*'){
                    grid_total[y+1][x] = 'R';
                    int i;
                    for(i = 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y + 1 && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add += 1;
					addrabbit[count_add - 1].set_x(x);
					addrabbit[count_add - 1].set_y(y + 1);
                    break;
                }
                else if(grid_new[y+2][x+1] == '-'){
                    grid_total[y+1][x] = 'R';
					count_add += 1;
					addrabbit[count_add - 1].set_x(x);
					addrabbit[count_add - 1].set_y(y + 1);
                    break;
                }                
                else continue;
            }

            if(number == 3){
                if(grid_new[y][x+1] == '*'){
                    grid_total[y-1][x] = 'R';
                    int i;
                    for(i = 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y-1 && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add += 1;
					addrabbit[count_add - 1].set_x(x);
					addrabbit[count_add - 1].set_y(y - 1);
                    break;
                }
                else if(grid_new[y][x+1] == '-'){
                    grid_total[y-1][x] = 'R';
					count_add += 1;
					addrabbit[count_add - 1].set_x(x);
					addrabbit[count_add - 1].set_y(y - 1);
                    break;
                }
                else continue;
            }
            
            if(number == 4){
                if(grid_new[y+1][x] == '*'){
                    grid_total[y][x-1] = 'R';
                    int i;
                    for(i = 0; i<number_of_grasses; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x-1){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add += 1;
					addrabbit[count_add - 1].set_x(x - 1);
					addrabbit[count_add - 1].set_y(y);
                    break;
                }
                else if(grid_new[y+1][x] == '-'){
                    grid_total[y][x-1] = 'R';
					count_add += 1;
					addrabbit[count_add - 1].set_x(x - 1);
					addrabbit[count_add - 1].set_y(y);
                    break;
                }
                else continue;
            }
        }
    }
    else{
    }
 
    delete[] grid_new;
}



void Rabbit::set_grid_rabbit(char** grid_total){
    grid_total[y][x] = 'R'; 
}