#include <iostream>
#include "main.h"
using namespace std;

void find_gap();
void print_board();
int move();
void move_up();
void move_down();
void move_right();
void move_left();
bool is_solved();
void timer();

int main(int argc, char const *argv[]){
	print_board();
	while(1){
		move();
	}
	return 0;
}
