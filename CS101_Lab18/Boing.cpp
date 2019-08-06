#include "Console.h"

void boing_init(int *px, int *py, int *pdx, int *pdy);
void boing_render(int x, int y);
void boing_update(int *px, int *py, int *pdx, int *pdy);

int main(void) {
	int x, y, dx, dy;

	// initialize variables
	boing_init(&x, &y, &dx, &dy);

	int keep_going = 1;
	while (keep_going == 1) {
		// print the character using x and y as its location
		boing_render(x, y);

		// update the terminal window
		cons_update();

		// update the variables so that the character will appear to move
		// the next time the boing_render function is called
		boing_update(&x, &y, &dx, &dy);

		// See if a key has been pressed
		int key = cons_get_keypress();
		if (key >= 0) {
			keep_going = 0;
		}

		// Pause for a short time
		cons_sleep_ms(1000/10);
	}

	return 0;
}

// TODO: add definitions for boing_init, boing_render, and boing_update
void boing_init(int *px, int *py, int *pdx, int *pdy){
	*px=0;
	*py=1;
	*pdx=1;
	*pdy=1;
}

void boing_update(int *px, int *py, int *pdx, int *pdy){
	if(*px + *pdx<0 || *px + *pdx>80){
		*pdx= -*pdx;
	}
	*px+=*pdx;
	if(*py + (*pdy+1)>24){
		*pdy= *pdy+1;
		*pdy= -*pdy;
		
		*py=24;
	}
	else{
		*pdy= *pdy+1;
		*py+=*pdy;
	}
	/*if(*py + *pdy>24){
		*pdx= -*pdx;
	}*/
	boing_render(*px,*py);
}

void boing_render(int x, int y){
	cons_clear_screen();
	cons_change_color(GREEN+INTENSE, BLACK);
	cons_move_cursor(y, x);
	cons_printw("*");
}


