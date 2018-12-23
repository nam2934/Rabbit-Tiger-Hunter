#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>

#include"hunter.h"
#include"grass.h"
#include"hunter.h"
#include"pit.h"
#include"rabbit.h"
#include"tiger.h"
#include"critter.h"

using namespace std;

int main(){
    //random
    srand((unsigned)time(NULL));

    //declare variable
    int number_of_rabbits, number_of_tigers, number_of_grasses, number_of_pits, number_of_potions;
    bool flag1;
    char** grid_total;
    string move_hunter;
    string ask_potion;
    Hunter hunter;
    int time_step=0;
    int max_value_HP = 5;
    int g_die = 0;
    int r_die = 0;

    int r_num;
    int t_num;
    int g_num;
    int r_cap = 0;
    int t_cap = 0;

    int die_r1 = 0;
    int die_r2 = 0;
    int die_t1 = 0;
    int die_t2 = 0;
    int count_add = 0;
    int count_add2 = 0;

    //make grid
	grid_total = new char*[10];

    //dinamic allocation
	for (int i = 0; i < 10; i++) {
		grid_total[i] = new char[10];
	}

    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            grid_total[i][j] = '-';
        }
    }
    while(true){
        //get rabbit number
        do{
            flag1 = true;
            cout << "Enter initial number of rabbits : ";
            cin >> number_of_rabbits;
            if(!cin){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                flag1 = false;
            }
        }
        while(number_of_rabbits < 0 || flag1 == false);
        
        //get tigers number
        do{
            flag1 = true;
            cout << "Enter initial number of tigers : ";
            cin >> number_of_tigers;
            if(!cin){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                flag1 = false;
            }
        }
        while(number_of_tigers < 0 || flag1 == false);

        //get grass number
        do{
            flag1 = true;
            cout << "Enter initial number of grasses : ";
            cin >> number_of_grasses;
            if(!cin){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                flag1 = false;
            }
        }
        while(number_of_grasses < 0 || flag1 == false);
        
        //get pit number
        do{
            flag1 = true;
            cout << "Enter initial number of pits : ";
            cin >> number_of_pits;
            if(!cin){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                flag1 = false;
            }
        }
        while(number_of_pits < 0 || flag1 == false);

        //get potion number
        do{
            flag1 = true;
            cout << "Enter initial number of potions : ";
            cin >> number_of_potions;
            if(!cin){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                flag1 = false;
            }
        }

        while(number_of_potions >= 100 || flag1 == false);

        if(number_of_grasses + number_of_pits + number_of_rabbits + number_of_tigers < 100) break;
        else cout << endl << "ERROR : number of all objects exceed the 100(10*10)" << endl << endl;
    }

    //set hunter
    hunter.set_potion(number_of_potions);
    hunter.create(grid_total);
    hunter.set_grid_hunter(grid_total);

    //make rabbit
    Rabbit* rabbit = new Rabbit[number_of_rabbits];
    for(int i=0; i<number_of_rabbits; i++){
        rabbit[i].create(grid_total);
        rabbit[i].set_grid_rabbit(grid_total);
    }
    //make tiger
    Tiger* tiger = new Tiger[number_of_tigers];
    for(int i=0; i<number_of_tigers; i++){
        tiger[i].create(grid_total);
        tiger[i].set_grid_tiger(grid_total);
    }
    //make grass
    Grass* grass = new Grass[number_of_grasses];
    for(int i=0; i<number_of_grasses; i++){
        grass[i].create(grid_total);
        grass[i].set_grid_grass(grid_total);
    }
    //make pit
    Pit* pit = new Pit[number_of_pits];
    for(int i=0; i<number_of_pits; i++){
        pit[i].create(grid_total);
        pit[i].set_grid_pit(grid_total);
    }
    
    int arr_g[number_of_grasses];
    r_num = number_of_rabbits;
    t_num = number_of_tigers;
    //game start while humter die
    while(hunter.get_HP() != 0){
        cout << "Time step: " << time_step << endl;
        cout << "Score:"<< hunter.get_score() << ", HP:" << hunter.get_HP() << ", Potion:" << hunter.get_potion() << endl;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cout << grid_total[i][j] << " ";
            }
            cout << endl;
        }
    
        cout << "number of rabbits:                " << r_num << "<born:" << count_add<< ", starve:"<< die_r1 << ", captured:" << r_cap << ", fall:"<< die_r2 << ">"<<endl;
        cout << "number of tigers:                 " << t_num << "<born:" << count_add2<< ", starve:"<< die_t1 << ", captured:" << t_cap << ", fall:"<< die_t2 << ">"<<endl;
        cout << "number of grasses:                " << number_of_grasses << endl;
        cout << "number of pits:                   " << number_of_pits << endl; 
        cout << endl;

        r_cap = 0;
        t_cap = 0;

        //HUNTER - get hunter move direction
        while (true) {
            cout << "Input the moving direction( Up: 'w', Down: 's', Left: 'a', Right: 'd'): ";
            cin >> move_hunter;
            if ((move_hunter != "w") && (move_hunter != "s") && (move_hunter != "a") && (move_hunter != "d") && (move_hunter != "wa") && (move_hunter != "wd") && (move_hunter != "sa") && (move_hunter != "sd")) {
                continue;
            }
            else {
                break;
            }
        }
        //use potion
        while (true) {
            cout << "Are you going to use potion(Yes: 'y', No: 'n'): ";
            cin >> ask_potion;
            if ((ask_potion != "y") && (ask_potion != "n")) {
                continue;
            }
            else {
                break;
            }
        }
        //up
        if(move_hunter == "w"){
            if(hunter.get_y() == 0){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y() - 1][hunter.get_x()] == '-'){
                hunter.move_up(grid_total);
                hunter.HP_decrease();
            }
            //if rabbit
            else if(grid_total[hunter.get_y()-1][hunter.get_x()] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y()-1 && rabbit[i].get_x() == hunter.get_x()){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;

                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
                hunter.move_up(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if tiger
            else if(grid_total[hunter.get_y()-1][hunter.get_x()] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y()-1 && tiger[i].get_x() == hunter.get_x()){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                delete[] temp;
                hunter.move_up(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()-1][hunter.get_x()] == '*'){
                int i;
                for(i=0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y()-1 && grass[i].get_x() == hunter.get_x()){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_up(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()-1][hunter.get_x()] == 'O'){
                hunter.set_HP(0);
            }
        }
        //down
        if(move_hunter == "s"){
            if(hunter.get_y() == 9){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y() + 1][hunter.get_x()] == '-'){
                hunter.move_down(grid_total);
                hunter.HP_decrease();
            }
            //if rabbit
            else if(grid_total[hunter.get_y()+1][hunter.get_x()] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y()+1 && rabbit[i].get_x() == hunter.get_x()){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                hunter.move_down(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if tiger
            else if(grid_total[hunter.get_y()+1][hunter.get_x()] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y()+1 && tiger[i].get_x() == hunter.get_x()){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                hunter.move_down(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()+1][hunter.get_x()] == '*'){
                int i;
                for(i = 0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y()+1 && grass[i].get_x() == hunter.get_x()){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_down(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()+1][hunter.get_x()] == 'O'){
                hunter.set_HP(0);
            }
        }
        //left
        if(move_hunter == "a"){
            if(hunter.get_x() == 0){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()][hunter.get_x()-1] == '-'){
                hunter.move_left(grid_total);
                hunter.HP_decrease();
            }
            //if rabbit
            else if(grid_total[hunter.get_y()][hunter.get_x()-1] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y() && rabbit[i].get_x() == hunter.get_x()-1){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
                hunter.move_left(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }   
            //if tiger
            else if(grid_total[hunter.get_y()][hunter.get_x()-1] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y() && tiger[i].get_x() == hunter.get_x()-1){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                delete[] temp;
                hunter.move_left(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()][hunter.get_x()-1] == '*'){
                int i;
                for(i = 0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y() && grass[i].get_x() == hunter.get_x() - 1){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_left(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()][hunter.get_x()-1] == 'O'){
                hunter.set_HP(0);
            }
        }
        //right
        if(move_hunter == "d"){
            if(hunter.get_x() == 9){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()][hunter.get_x()+1] == '-'){
                hunter.move_right(grid_total);
                hunter.HP_decrease(); 
            }
            //if rabbit
            else if(grid_total[hunter.get_y()][hunter.get_x()+1] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y() && rabbit[i].get_x() == hunter.get_x()+1){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
                hunter.move_right(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if tiger
            else if(grid_total[hunter.get_y()][hunter.get_x()+1] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y() && tiger[i].get_x() == hunter.get_x()+1){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                delete[] temp;
                hunter.move_right(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()][hunter.get_x()+1] == '*'){
                int i;
                for(i = 0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y() && grass[i].get_x() == hunter.get_x()+1){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_right(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()][hunter.get_x()+1] == 'O'){
                hunter.set_HP(0);
            }
        }
        //up rignt
        if(move_hunter == "wd"){
            if(hunter.get_x() == 9 || hunter.get_y() == 0){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()-1][hunter.get_x()+1] == '-'){
                hunter.move_up_right(grid_total);
                hunter.HP_decrease(); 
            }
            //if rabbit
            else if(grid_total[hunter.get_y()-1][hunter.get_x()+1] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y()-1 && rabbit[i].get_x() == hunter.get_x()+1){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
                hunter.move_up_right(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if tiger
            else if(grid_total[hunter.get_y()-1][hunter.get_x()+1] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y()-1 && tiger[i].get_x() == hunter.get_x()+1){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                delete[] temp;
                hunter.move_up_right(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()-1][hunter.get_x()+1] == '*'){
                int i;
                for(i = 0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y()-1 && grass[i].get_x() == hunter.get_x()+1){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_up_right(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()-1][hunter.get_x()+1] == 'O'){
                hunter.set_HP(0);
            }
        }
        //up left
        if(move_hunter == "wa"){
            if(hunter.get_x() == 0 || hunter.get_y() == 0){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()-1][hunter.get_x()-1] == '-'){
                hunter.move_up_left(grid_total);
                hunter.HP_decrease(); 
            }
            //if rabit
            else if(grid_total[hunter.get_y()-1][hunter.get_x()-1] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y()-1 && rabbit[i].get_x() == hunter.get_x()-1){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
                hunter.move_up_left(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if tiger
            else if(grid_total[hunter.get_y()-1][hunter.get_x()-1] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y()-1 && tiger[i].get_x() == hunter.get_x()-1){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                delete[] temp;
                hunter.move_up_left(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()-1][hunter.get_x()-1] == '*'){
                int i;
                for(i = 0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y()-1 && grass[i].get_x() == hunter.get_x() - 1){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_up_left(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()-1][hunter.get_x()-1] == 'O'){
                hunter.set_HP(0);
            }
        }
        //down right
        if(move_hunter == "sd"){
            if(hunter.get_x() == 9 || hunter.get_y() == 9){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()+1][hunter.get_x()+1] == '-'){
                hunter.move_down_right(grid_total);
                hunter.HP_decrease(); 
            }
            //if rabbit
            else if(grid_total[hunter.get_y()+1][hunter.get_x()+1] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y()+1 && rabbit[i].get_x() == hunter.get_x()+1){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
                hunter.move_down_right(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if tiger
            else if(grid_total[hunter.get_y()+1][hunter.get_x()+1] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y()+1 && tiger[i].get_x() == hunter.get_x()+1){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                delete[] temp;
                hunter.move_down_right(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()+1][hunter.get_x()+1] == '*'){
                int i;
                for(i = 0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y()+1 && grass[i].get_x() == hunter.get_x()+1){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_down_right(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()+1][hunter.get_x()+1] == 'O'){
                hunter.set_HP(0);
            }
        }
        //down left
        if(move_hunter == "sa"){
            if(hunter.get_x() == 0 || hunter.get_y() == 9){
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()+1][hunter.get_x()-1] == '-'){
                hunter.move_down_left(grid_total);
                hunter.HP_decrease(); 
            }
            //if rabbit
            else if(grid_total[hunter.get_y()+1][hunter.get_x()-1] == 'R'){
                int i;
                for(i=0; i<r_num; i++){
                    if(rabbit[i].get_y() == hunter.get_y()+1 && rabbit[i].get_x() == hunter.get_x()-1){
                        break;
                    }
                }
                
                for(int j=i; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
                hunter.move_down_left(grid_total);
                hunter.score_increase_1();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_2();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if tiger
            else if(grid_total[hunter.get_y()+1][hunter.get_x()-1] == 'T'){
                int i;
                for(i=0; i<t_num; i++){
                    if(tiger[i].get_y() == hunter.get_y()+1 && tiger[i].get_x() == hunter.get_x()-1){
                        break;
                    }
                }
                
                for(int j=i; j<t_num; j++){
                    tiger[j] = tiger[j+1];
                }
                t_num -= 1; 
                t_cap++;
                Tiger* temp = tiger;
                tiger = new Tiger[t_num];
                for(int i=0; i<t_num; i++){
                    tiger[i] = temp[i];
                }
                delete[] temp;
                hunter.move_down_left(grid_total);
                hunter.score_increase_2();
                if(hunter.get_HP() + 2 <= max_value_HP){
                    hunter.HP_increase_max();
                }
                else if(hunter.get_HP() == max_value_HP - 1){
                    hunter.HP_increase_max();
                }
            }
            //if grass
            else if(grid_total[hunter.get_y()+1][hunter.get_x()-1] == '*'){
                int i;
                for(i=0; i<number_of_grasses; i++){
                    if(grass[i].get_y() == hunter.get_y()+1 && grass[i].get_x() == hunter.get_x()-1){
                        break;
                    } 
                }
                arr_g[g_die] = i;
                g_die++;
                hunter.move_down_left(grid_total);
                hunter.HP_decrease();
            }
            else if(grid_total[hunter.get_y()+1][hunter.get_x()-1] == 'O'){
                hunter.set_HP(0);
            }
        }
        if(ask_potion == "y" && hunter.get_potion() > 0){ 
            hunter.HP_increase_max();
            hunter.potion_decrease();
        }

        //tiger born and starve
        count_add2= 0;
        Tiger* addtiger;
        addtiger = new Tiger[1];
        for(int i = 0; i< t_num; i++){
            //move tiger
            int index = 0;
            tiger[i].move(grid_total, grass, number_of_grasses, g_die, rabbit, r_num, r_die, arr_g);
            if(tiger[i].get_check_fall() == 1){
                grid_total[tiger[i].get_y()][tiger[i].get_x()] = '-';
            }
            else if(tiger[i].get_lifetime() == 0){
                grid_total[tiger[i].get_y()][tiger[i].get_x()] = '-';
            }
            //breed tiger
            else if(tiger[i].get_count_tiger_alive()%4 == 0 && tiger[i].get_count_tiger_alive() != 0){
                Tiger* temp = addtiger;
                addtiger = new Tiger[count_add2+1];
                for (int j = 0; j < count_add2; j++) {
                    addtiger[j] = temp[j];
                }
                tiger[i].breed(grid_total, grass, number_of_grasses, g_die, rabbit, r_num, r_die, count_add2, addtiger, arr_g);
                delete[] temp;
            }
            //eat rabbit
            if(r_die == 1){
                int index;
                for(index=0; index<r_num; index++){
                    if(rabbit[index].get_y() == tiger[i].get_y() && rabbit[index].get_x() == tiger[i].get_x()){
                        break;
                    }
                }
                for(int j=index; j<r_num; j++){
                    rabbit[j] = rabbit[j+1];
                }
                r_num -= 1; 
                r_cap++;
                Rabbit* temp = rabbit;
                rabbit = new Rabbit[r_num];
                for(int i=0; i<r_num; i++){
                    rabbit[i] = temp[i];
                }
                delete[] temp;
            }
            r_die = 0;
        }

        //rabbit born starve
        count_add = 0;
        Rabbit* addrabbit;
        addrabbit = new Rabbit[1];
        for(int i = 0; i< r_num; i++){
            //move rabbit
            int index = 0;
            rabbit[i].move(grid_total, grass, number_of_grasses, g_die, arr_g);
            if(rabbit[i].get_check_fall() == 1){
                grid_total[rabbit[i].get_y()][rabbit[i].get_x()] = '-';
            }
            else if(rabbit[i].get_lifetime() == 0){
                grid_total[rabbit[i].get_y()][rabbit[i].get_x()] = '-';
            }
            //born rabbiy
            else if(rabbit[i].get_count_rabbit_alive()%3 == 0 && rabbit[i].get_count_rabbit_alive() != 0){
                Rabbit* temp = addrabbit;
                addrabbit = new Rabbit[count_add+1];
                for (int j = 0; j < count_add; j++) {
                    addrabbit[j] = temp[j];
                }
                rabbit[i].breed(grid_total, grass, number_of_grasses, g_die, count_add, addrabbit, arr_g);
                delete[] temp;
            }
        }

        int index3 = 0;
        die_t2 = 0;
        int arr_fall_t1[100] = {0,};
        int index4 = 0;

        //tiger fall
        for(index3 = 0; index3< t_num; index3++){
            if(tiger[index3].get_check_fall() == 1){
                arr_fall_t1[index3] = 1;
                die_t2++;
            }
        }
        if(die_t2 != 0){
            Tiger* temp = tiger;
            tiger = new Tiger[t_num - die_t2];
            for(int i=0; i<t_num; i++){
                if(arr_fall_t1[i] == 0){
                    tiger[index4] = temp[i];
                    index4++;
                }
            }
            delete[] temp;
        }

        t_num = t_num - die_t2;

        int index = 0;
        die_t1 = 0;
        int arr_die_t1[100] = {0, };
        int index2 = 0;

        //tiger starve
        for(index = 0; index< t_num; index++){
            if(tiger[index].get_lifetime() == 0){
                arr_die_t1[index] = 1;
                die_t1++;
            }
        }

        if(die_t1 != 0){
            Tiger* temp = tiger;
            tiger = new Tiger[t_num-die_t1];
            for(int i=0; i<t_num; i++){
                if(arr_die_t1[i] == 0){
                    tiger[index2] = temp[i];
                    index2++;
                }
            }
            delete[] temp;
        }
        t_num = t_num - die_t1;

        //tiger born
		if (count_add2 != 0) {
			Tiger* temp = tiger;
			tiger = new Tiger[t_num + count_add2];
			for (int i = 0; i < t_num + count_add2; i++) {
				if (i < (t_num)) {
					tiger[i] = temp[i];
				}
				else {
					tiger[i] = addtiger[i - t_num];
				}
			}
            delete[] temp;
		}

        index3 = 0;
        die_r2 = 0;
        int arr_fall_r[100] = {0,};
        index4 = 0;

        t_num = t_num + count_add2;

        //rabbit fall
        for(index3 = 0; index3< r_num; index3++){
            if(rabbit[index3].get_check_fall() == 1){
                arr_fall_r[index3] = 1;
                die_r2++;
            }
        }
        if(die_r2 != 0){
            Rabbit* temp = rabbit;
            rabbit = new Rabbit[r_num - die_r2];
            for(int i=0; i<r_num; i++){
                if(arr_fall_r[i] == 0){
                    rabbit[index4] = temp[i];
                    index4++;
                }
            }
            delete[] temp;
        }

        r_num = r_num - die_r2;

        index = 0;
        die_r1 = 0;
        int arr_die_r[100] = {0, };
        index2 = 0;

        //rabbit starve
        for(index = 0; index< r_num; index++){
            if(rabbit[index].get_lifetime() == 0){
                arr_die_r[index] = 1;
                die_r1++;
            }
        }

        if(die_r1 != 0){
            Rabbit* temp = rabbit;
            rabbit = new Rabbit[r_num-die_r1];
            for(int i=0; i<r_num; i++){
                if(arr_die_r[i] == 0){
                    rabbit[index2] = temp[i];
                    index2++;
                }
            }
            delete[] temp;
        }
        r_num = r_num - die_r1;

        //rabbit born
		if (count_add != 0) {
			Rabbit* temp = rabbit;
			rabbit = new Rabbit[r_num + count_add];
			for (int i = 0; i < r_num + count_add; i++) {
				if (i < (r_num)) {
					rabbit[i] = temp[i];
				}
				else {
					rabbit[i] = addrabbit[i - r_num];
				}
			}
            delete[] temp;
		}

        r_num = r_num + count_add;

        //grass die
        if(g_die!=0){
            for(int i=0; i<g_die; i++) {
                grass[arr_g[i]].create(grid_total);
                grass[arr_g[i]].set_grid_grass(grid_total);
            }
        }
        g_die = 0;

        time_step++;
        system("clear");
    }
    cout << "Your final score is "<< hunter.get_score() << endl << "End of program" << endl;
}