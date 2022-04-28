#include <iostream>
#include <termios.h>
#include <stdio.h>

int board[3][3]={3,4,7,
				 0,8,2,
				 5,1,6};

int solved_board[3][3]={1,2,3,
						4,5,6,
						7,8,0};
int gap[2];
using namespace std;


void timer(){
	int second=0,minute=0;
	while (1){
		second++;
		system("sleep 1");
		if(second==60){
			second=0;
			minute++;
		}
		if(minute<10){
			cout<<"0"<<minute<<":";
		}else{
			cout<<minute<<":";
		}
		if(second<10){
			cout<<"0"<<second;
		}else{
			cout<<second<<":";	
		}
	}
}
bool is_solved(){
	bool result=false;
	int countt=0;
	for(int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if(board[i][j]==solved_board[i][j]){
				countt++;
			}
		}
	}
	if(countt==9){
		result=true;
	}
	return result;
}
void print_board(){
	system("clear");
	for(int i=0;i<3;i++){
		cout<<"|";
		for(int j=0;j<3;j++){
			if(board[i][j]!=0){
				cout<<board[i][j]<<"|";
			}else{
				cout<<" |";
			}
		}
		cout<<"\n";
	}
}
void find_gap(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]==0){
				gap[0]=i;
				gap[1]=j;
			}
		}
	}
}
void move_up(){
	find_gap();
	if(gap[0]!=2){
		swap(board[gap[0]][gap[1]],board[gap[0]+1][gap[1]]);
	}
}
void move_down(){
	find_gap();
	if(gap[0]!=0){
		swap(board[gap[0]][gap[1]],board[gap[0]-1][gap[1]]);
	}
}
void move_right(){
	find_gap();
	if(gap[1]!=0){
		swap(board[gap[0]][gap[1]],board[gap[0]][gap[1]-1]);	
	}
}
void move_left(){
	find_gap();
	if(gap[1]!=2){
		swap(board[gap[0]][gap[1]],board[gap[0]][gap[1]+1]);	
	}
}

static struct termios old, current;


void initTermios(int echo) {
  	tcgetattr(0, &old); 
  	current = old; 
  	current.c_lflag &= ~ICANON; 
  	if (echo) {
      	current.c_lflag |= ECHO;
  	} else {
      	current.c_lflag &= ~ECHO;
  	}
  	tcsetattr(0, TCSANOW, &current);
}


void resetTermios(void) {
  	tcsetattr(0, TCSANOW, &old);
}


char getch_(int echo) {
  	char ch;
  	initTermios(echo);
  	ch = getchar();
  	resetTermios();
  	return ch;
}

char getch(void) {
  	return getch_(0);
}


char getche(void) {
	return getch_(1);
}

int move(){
	switch(getch()){
		case 'w': 
			move_up();
			print_board();
			if(is_solved()){
				cout<<"\n\nCONGRAT YOU WON!";
				return 0;
			}
			break;
		case 'a':
			move_left();
			print_board();
			if(is_solved()){
				cout<<"\n\nCONGRAT YOU WON!";
				return 0;
			}
			break; 
		case 's':
			move_down();
			print_board();
			if(is_solved()){
				cout<<"\n\nCONGRAT YOU WON!";
				return 0;
			}
			break;
		case 'd':
			move_right();
			print_board();
			if(is_solved()){
				cout<<"\n\nCONGRAT YOU WON!";
				return 0;
			}
			break;
	}
}