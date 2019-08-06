#include "Console.h"

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
	int x, y, dx, dy;
};

// Function prototypes
void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
	struct Scene s;
	
	// TODO: add call to scene_init
	scene_init(&s);
	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		// TODO: add call to scene_render
		scene_render(&s);
		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		// TODO: add call to scene_update
		scene_update(&s);
		
		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

// TODO: add definitions for scene_init, scene_render, and scene_update
void scene_init(struct Scene *s){
	//struct Scene s;

	// TODO: initialize fields
	s->x = 1;
	s->y = 1;
	s->dx = 1;
	s->dy = 1;
	
	//return s;
}


void scene_render(const struct Scene *s){
	cons_clear_screen();
	cons_move_cursor(s->y, s->x);
	cons_printw("*");
}


void scene_update(struct Scene *s){
	if(s->x+s->dx>80 || s->x+s->dx<0){
		s->dx = -s->dx;
	}
	if(s->y+s->dy>23 || s->y+s->dy<0){
		s->dy = -s->dy;
	}
	s->x = s->x + s->dx;
	s->y = s->y + s->dy;
	s->dx = s->dx;
	s->dy = s->dy;
}

