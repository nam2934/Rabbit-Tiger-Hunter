#include"tiger.h"

Tiger::Tiger() : Critter() {
    tiger_alive = 0;
}

int Tiger::get_check_fall(){
    return check_fall;
}

int Tiger::get_count_tiger_alive(){
    return tiger_alive;
}
//tiger move almost same rabbit
void Tiger::move(char** grid_total, Grass* grass, int number_of_grass, int& g_die, Rabbit* rabbit, int r_num, int& r_die, int* arr_g){
    int number4 = rand()%4 + 1;
    int count=0;
    
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

    if(grid_new[y+1][x+2] == 'R' || grid_new[y+2][x+1] == 'R' || grid_new[y][x+1] == 'R' || grid_new[y+1][x] == 'R'){
        if(grid_new[y+1][x+2] == 'R') count++; //right
        if(grid_new[y+2][x+1] == 'R') count++; //down
        if(grid_new[y][x+1] == 'R') count++; //up
        if(grid_new[y+1][x] == 'R') count++; //left
        while(count != 0){
            int number = rand()%4 + 1;
            if(number == 1){
                if(grid_new[y+1][x+2] == 'R'){
                    grid_total[y][x+1] = 'T';
                    grid_total[y][x] = '-';
                    x++;
                    lifetime = 3;
                    r_die++;
                    tiger_alive++;
                    break;
                }
                else continue;
            }

            if(number == 2){
                if(grid_new[y+2][x+1] == 'R'){
                    grid_total[y+1][x] = 'T';
                    grid_total[y][x] = '-';
                    y++;
                    lifetime = 3;
                    r_die++;
                    tiger_alive++;
                    break;
                }
                else continue;
            }

            if(number == 3){
                if(grid_new[y][x+1] == 'R'){
                    grid_total[y-1][x] = 'T';
                    grid_total[y][x] = '-';
                    y--;
                    lifetime = 3;
                    r_die++;
                    tiger_alive++;
                    break;
                }
                else continue;
            }
            
            if(number == 4){
                if(grid_new[y+1][x] == 'R'){
                    grid_total[y][x-1] = 'T';
                    grid_total[y][x] = '-';
                    x--;
                    lifetime = 3;
                    r_die++;
                    tiger_alive++;
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
                tiger_alive++;
            }
            else if(grid_total[y-1][x] == '-'){
                grid_total[y-1][x] = 'T';
                grid_total[y][x] = '-';
                y--;
                if(lifetime > 0) lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y-1][x] == 'H'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y-1][x] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
            }
            else if(grid_total[y-1][x] == 'T'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y-1][x] == '*'){
                grid_total[y-1][x] = 'T';
                grid_total[y][x] = '-';
                y--;
                lifetime--;
                int i;
                for(i = 0; i<number_of_grass; i++){
                    if(grass[i].get_y() == y && grass[i].get_x() == x){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                tiger_alive++;
            }
        }

        else if(number4 == 2){//down
            if(y==9){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y+1][x] == '-'){
                grid_total[y+1][x] = 'T';
                grid_total[y][x] = '-';
                y++;
                if(lifetime > 0) lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y+1][x] == 'H'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y+1][x] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
            }
            else if(grid_total[y+1][x] == 'T'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y+1][x] == '*'){
                grid_total[y+1][x] = 'T';
                grid_total[y][x] = '-';
                y++;
                lifetime--;
                int i;
                for(i = 0; i<number_of_grass; i++){
                    if(grass[i].get_y() == y && grass[i].get_x() == x){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                tiger_alive++;
            }
        }

        else if(number4 == 3){//left
            if(x==0){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x-1] == '-'){
                grid_total[y][x-1] = 'T';
                grid_total[y][x] = '-';
                x--;
                if(lifetime > 0) lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x-1] == 'H'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x-1] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
                tiger_alive++;
            }
            else if(grid_total[y][x-1] == 'T'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x-1] == '*'){
                grid_total[y][x-1] = 'T';
                grid_total[y][x] = '-';
                x--;
                lifetime--;
                int i;
                for(i = 0; i<number_of_grass; i++){
                    if(grass[i].get_y() == y && grass[i].get_x() == x){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                tiger_alive++;
            }
        }

        else if(number4 == 4){//right
            if(x==9){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x+1] == '-'){
                grid_total[y][x+1] = 'T';
                grid_total[y][x] = '-';
                x++;
                if(lifetime > 0) lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x+1] == 'H'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x+1] == 'O'){
                check_fall++;
                grid_total[y][x] = '-';
                tiger_alive++;
            }
            else if(grid_total[y][x+1] == 'T'){
                lifetime--;
                tiger_alive++;
            }
            else if(grid_total[y][x+1] == '*'){
                grid_total[y][x+1] = 'T';
                grid_total[y][x] = '-';
                x++;
                lifetime--;
                int i;
                for(i = 0; i<number_of_grass; i++){
                    if(grass[i].get_y() == y && grass[i].get_x() == x){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                tiger_alive++;
            }
        }
    }

    delete[] grid_new;
}

//tiger breed almost same as rabbit
void Tiger::breed(char** grid_total, Grass* grass, int number_of_grass, int& g_die, Rabbit* rabbit, int r_num, int& r_die, int& count_add2, Tiger* addtiger, int* arr_g){
    int number4 = rand()%4 + 1;
    int count=0;
    
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
                    grid_total[y][x+1] = 'T';
                    int i;
                    for(i = 0; i<number_of_grass; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x + 1){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x + 1);
					addtiger[count_add2 - 1].set_y(y);
                    break;
                }
                else if(grid_new[y+1][x+2] == '-'){
                    grid_total[y][x+1] = 'T';
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x + 1);
					addtiger[count_add2 - 1].set_y(y);
                    break;
                }
                else continue;
            }

            if(number == 2){
                if(grid_new[y+2][x+1] == '*'){
                    grid_total[y+1][x] = 'T';
                    int i;
                    for(i = 0; i<number_of_grass; i++){
                        if(grass[i].get_y() == y + 1 && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x);
					addtiger[count_add2 - 1].set_y(y + 1);
                    break;
                }
                else if(grid_new[y+2][x+1] == '-'){
                    grid_total[y+1][x] = 'T';
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x);
					addtiger[count_add2 - 1].set_y(y + 1);
                    break;
                }                
                else continue;
            }

            if(number == 3){
                if(grid_new[y][x+1] == '*'){
                    grid_total[y-1][x] = 'T';
                    int i;
                    for(i = 0; i<number_of_grass; i++){
                        if(grass[i].get_y() == y-1 && grass[i].get_x() == x){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x);
					addtiger[count_add2 - 1].set_y(y - 1);
                    break;
                }
                else if(grid_new[y][x+1] == '-'){
                    grid_total[y-1][x] = 'T';
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x);
					addtiger[count_add2 - 1].set_y(y - 1);
                    break;
                }
                else continue;
            }
            
            if(number == 4){
                if(grid_new[y+1][x] == '*'){
                    grid_total[y][x-1] = 'T';
                    int i;
                    for(i = 0; i<number_of_grass; i++){
                        if(grass[i].get_y() == y && grass[i].get_x() == x-1){
                            break;
                        } 
                    }
                    arr_g[g_die] = i;
                    g_die++;
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x - 1);
					addtiger[count_add2 - 1].set_y(y);
                    break;
                }
                else if(grid_new[y+1][x] == '-'){
                    grid_total[y][x-1] = 'T';
					count_add2 += 1;
					addtiger[count_add2 - 1].set_x(x - 1);
					addtiger[count_add2 - 1].set_y(y);
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


void Tiger::set_grid_tiger(char** grid_total){
    grid_total[y][x] = 'T'; 
}