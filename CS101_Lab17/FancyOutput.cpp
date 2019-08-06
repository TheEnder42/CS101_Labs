#include "Console.h"

int main(void)
{
	cons_clear_screen();
	// Don't change anything above this line
	// TODO: Add your code here
	cons_change_color(GREEN, GREEN);
	cons_move_cursor(11, 20);
	for(int i=0; i<40; i++){
		cons_printw(" ");
	}
	
	cons_move_cursor(12, 20);
	cons_printw("  ");
	cons_change_color(GREEN, BLACK);
	for(int i=0; i<10; i++){
		cons_printw(" ");
	}
	
	cons_change_color(YELLOW+INTENSE, BLACK);
	cons_move_cursor(12, 32);
	cons_printw("Hello, CS 101!!!");
	
	cons_change_color(GREEN, BLACK);
	for(int i=0; i<10; i++){
		cons_printw(" ");
	}
	cons_change_color(GREEN, GREEN);
	cons_printw("  ");
	
	cons_move_cursor(13, 20);
	for(int i=0; i<40; i++){
		cons_printw(" ");
	}

	// Don't change anything below this line	
	cons_update();
	cons_wait_for_keypress();
	
	return 0;
}
