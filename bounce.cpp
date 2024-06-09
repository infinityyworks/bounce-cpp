#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <math.h>

using namespace std;

void setup() {
	initscr();
	noecho();
	curs_set(FALSE);
}

int main(int argc, char *argv[]) {

const int delay = 20 * 1000;
int x = 0, y = 0;
int maxX = 0, maxY = 0;
int nextX = 0, nextY = 0;
int translation[2] = {1,1};
setup();

while(1) {

	getmaxyx(stdscr,maxY,maxX);
	clear();
	mvprintw(y,x,"o");
	refresh();
	usleep(delay);
	nextX = x + translation[0];
	nextY = y + translation[1];
	

	if (nextX >= maxX || nextX < 0) {
		translation[0] *= -1;
	}
	else {x += translation[0];}
	
	if (nextY >= maxY || nextY < 0) {
		translation[1] *= -1;
	}
	else {y += translation[1];}
}
endwin();
// cout << maxX << ", " << maxY;
return 0;
}
