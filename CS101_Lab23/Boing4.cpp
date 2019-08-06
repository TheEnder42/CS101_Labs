#include <stdbool.h>
#include <stdlib.h>
#include "Console.h"

// The scene should contain an array of this many Particles
#define NUM_PARTICLES 20

// Definition of the Point struct type
struct Point {
	double x, y;
};

// Definition of the Particle struct type
struct Particle {
	// TODO: add fields
};

// Definition of the Rect struct type
struct Rect {
	// TODO: add fields
};

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
};

// Function prototypes

void point_init(struct Point *p, double x, double y);
void point_move(struct Point *p, double dx, double dy);

void particle_init(struct Particle *p);
void particle_render(const struct Particle *p);
void particle_update(struct Particle *p);

void rect_init(struct Rect *r, struct Point p1, struct Point p2);
bool rect_contains_point(const struct Rect *r, struct Point p);

void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
	// NOTE: you don't need to change anything in the main() function

	struct Scene myScene;

	// TODO: add call to scene_init

	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		// TODO: add call to scene_render

		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		// TODO: add call to scene_update

		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

// TODO: add definitions for functions
