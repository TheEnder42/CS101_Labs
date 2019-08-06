#include "Console.h"

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
};

// Function prototypes
void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
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

// TODO: add definitions for scene_init, scene_render, and scene_update
