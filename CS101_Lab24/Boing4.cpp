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
	Point pt;
	double dx, dy;
	int color;
};

// Definition of the Rect struct type
struct Rect {
	// TODO: add fields
	//int x, y, w, h;
	Point max, min;
};

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
	Particle cloud[NUM_PARTICLES];
	Rect box;
};

// Function prototypes

void point_init(struct Point *p, double x, double y);
void point_move(struct Point *p, double dx, double dy);

void particle_init(struct Particle *p);
void particle_render(const struct Particle *p);
void particle_update(struct Particle *p, struct Rect *box);

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
	scene_init(&myScene);
	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		// TODO: add call to scene_render
		scene_render(&myScene);
		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		// TODO: add call to scene_update
		scene_update(&myScene);
		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

// TODO: add definitions for functions
void point_init(struct Point *p, double x, double y){
	p->x = x;
	p->y = y;
}

void point_move(struct Point *p, double dx, double dy){
	p->x = p->x+dx;
	p->y = p->y+dy;
}

void particle_init(struct Particle *p){
	p->pt.x = (rand() % 8000) / 100.0;
	p->pt.y = (rand() % 2300) / 100.0;
	p->dx = ((rand() % 300) / 100.0) - 1.5 ;
	p->dy = ((rand() % 300) / 100.0) - 1.5 ;
	p->color = (rand() % 15) + 1;
}

void particle_render(const struct Particle *p){
	cons_change_color(p->color, BLACK);
	cons_move_cursor(p->pt.y, p->pt.x);
	cons_printw("*");
}

void particle_update(struct Particle *p, struct Rect *box){
	if(p->pt.x+p->dx>80 || p->pt.x+p->dx<0){
		p->dx = -p->dx;
	}
	if(p->pt.y+p->dy>23 || p->pt.y+p->dy<0){
		p->dy = -p->dy;
	}
	Point temp;
	point_init(&temp, p->pt.x+p->dx, p->pt.y+p->dy);
	if(rect_contains_point(box, temp)){
		if(temp.x>box->min.x && temp.x<box->max.x){
			p->dx = -p->dx;
		}
		else if(temp.y>box->min.y && temp.x<box->max.y){
			p->dy = -p->dy;
		}
		else{
			p->dx = -p->dx;
			p->dy = -p->dy;
		}
		
	}
	point_move(&p->pt, p->dx, p->dy);
}

void scene_init(struct Scene *s){
	struct Point t1, t2;
	point_init(&t1, 20, 8);
	point_init(&t2, 60, 16);
	rect_init(&s->box, t1, t2);
	for(int i=0; i<NUM_PARTICLES; i++){
		particle_init(&s->cloud[i]);
		while(rect_contains_point(&s->box, s->cloud[i].pt)){
			particle_init(&s->cloud[i]);
		}
	}
	
}

void scene_render(const struct Scene *s){
	for(int i=0; i<NUM_PARTICLES; i++){
		particle_render(&s->cloud[i]);
	}
	cons_change_color(GREEN, GREEN);
	for (int j = s->box.min.y; j < s->box.max.y; j++) {
		for (int i = s->box.min.x; i < s->box.max.x; i++) {
			cons_move_cursor(j, i);
			cons_printw(" ");
		}
	}
}

void scene_update(struct Scene *s){
	for(int i=0; i<NUM_PARTICLES; i++){
		particle_update(&s->cloud[i], &s->box);
	}
}

void rect_init(struct Rect *r, struct Point p1, struct Point p2){
	r->min = p1;
	r->max = p2;
}

bool rect_contains_point(const struct Rect *r, struct Point p){
	if(p.x>r->min.x && p.x<r->max.x && p.y>r->min.y && p.y<r->max.y){
		return true;
	}
	return false;
}

