#include "Console.h"

// game mode constants
#define PLACING     0  // player is choosing the initial ball placement
#define BALL_MOVING 1  // ball is moving, but not in the cup yet
#define IN_CUP      2  // ball is in the cup
#define DONE        3  // player pressed 'q' to quit

struct Point {
	int x, y;
};

struct Ball {
	struct Point pos;
	int dx, dy;
};

struct Rect {
	struct Point topleft;
	int width, height;
};

struct Scene {
	struct Rect obstacle;
	struct Rect cup;
	struct Ball ball;
	int mode; // game mode
};

// Functions
void point_init(struct Point *p, int x, int y);
void ball_init(struct Ball *b, int x, int y, int dx, int dy);
void rect_init(struct Rect *r, int x, int y, int w, int h);
bool rect_contains_point(const struct Rect *r, const struct Point *p);
void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);

// This function is useful for drawing rectangles filled with a solid color
void fill(int x, int y, int w, int h, int color);

int main(void) {
	struct Scene the_scene;

	scene_init(&the_scene);

	while (the_scene.mode != DONE) {
		cons_clear_screen();
		scene_render(&the_scene);
		cons_update();
		cons_sleep_ms(1000/10);
		scene_update(&the_scene);
	}

	return 0;
}

void point_init(struct Point *p, int x, int y) {
	// TODO: implement
	p->x=x;
	p->y=y;
}

void ball_init(struct Ball *b, int x, int y, int dx, int dy) {
	// TODO: implement
	b->pos.x=x;
	b->pos.y=y;
	b->dx=dx;
	b->dy=dy;
}

void rect_init(struct Rect *r, int x, int y, int w, int h) {
	// TODO: implement
	r->topleft.x=x;
	r->topleft.y=y;
	r->width=w;
	r->height=h;
}

bool rect_contains_point(const struct Rect *r, const struct Point *p) {
	// TODO: implement
	if(p->x > r->topleft.x && p->x < r->topleft.x+r->width && p->y > r->topleft.y && p->y < r->topleft.y+r->height){
		return true;
	}
	return false;
}

void scene_init(struct Scene *s) {
	// You won't need to modify this function
	rect_init(&s->obstacle, 40, 6, 10, 12);
	rect_init(&s->cup, 60, 12, 2, 2);
	ball_init(&s->ball, 10, 12, 0, 0);
	s->mode = PLACING;
}

void scene_render(const struct Scene *s) {
	// draw background and bumpers
	fill(0, 0, 80, 1, GREEN+INTENSE); // top bumper
	fill(0, 23, 80, 1, GREEN+INTENSE); // bottom bumper
	fill(0, 1, 1, 22, GREEN+INTENSE); // left bumper
	fill(79, 1, 1, 22, GREEN+INTENSE); // right bumper
	//fill(1, 1, 78, 22, GREEN); // background

	// TODO: draw obstacle
	fill(40, 6, 10, 12, GREEN+INTENSE);
	
	// TODO: draw cup
	fill(60, 12, 2, 2, BLUE+INTENSE);
	
	// TODO: draw ball
	cons_change_color(YELLOW+INTENSE, BLACK);
	cons_move_cursor(s->ball.pos.y, s->ball.pos.x);
	cons_printw("@");
	
	// TODO: if the ball is in the cup, print "Hole in one!!!"
	if(rect_contains_point(&s->cup, &s->ball.pos)){
		cons_change_color(BLUE, BLUE);
		cons_move_cursor(11, 20);
		for(int i=0; i<40; i++){
			cons_printw(" ");
		}
	
		cons_move_cursor(12, 20);
		cons_printw("  ");
		cons_change_color(BLUE, BLUE);
		for(int i=0; i<10; i++){
			cons_printw(" ");
		}
	
		cons_change_color(YELLOW+INTENSE, BLUE);
		cons_move_cursor(12, 33);
		cons_printw("Hole in one!!!");
	
		cons_change_color(BLUE, BLUE);
		for(int i=0; i<10; i++){
			cons_printw(" ");
		}
		cons_change_color(BLUE, BLUE);
		cons_printw("  ");
	
		cons_move_cursor(13, 20);
		for(int i=0; i<40; i++){
			cons_printw(" ");
		}
	}
	
	// leave the cursor in the lower right
	cons_move_cursor(23, 79);
}

void scene_update(struct Scene *s) {
	int key = cons_get_keypress();
	if (key == 'q') {
		s->mode = DONE;
		return;
	}

	if (s->mode == PLACING) {
		if (key == UP_ARROW && s->ball.pos.y > 1) {
			s->ball.pos.y--;
		} else if (key == DOWN_ARROW && s->ball.pos.y < 22) {
			s->ball.pos.y++;
		} else if (key == 'j') {
			// ball released, moving up and right
			s->ball.dx = 1;
			s->ball.dy = -1;
			s->mode = BALL_MOVING;
		} else if (key == 'k') {
			// ball released, moving down and right
			s->ball.dx = 1;
			s->ball.dy = 1;
			s->mode = BALL_MOVING;
		}
	} else if (s->mode == BALL_MOVING) {
		// TODO: determine ball's next position
		struct Point temp;
		temp.x = s->ball.dx + s->ball.pos.x;
		temp.y = s->ball.pos.y + s->ball.dy;

		// TODO: check for collision with bumper(s)
		if(s->ball.pos.x+s->ball.dx>79 || s->ball.pos.x+s->ball.dx<1){
			s->ball.dx = -s->ball.dx;
		}
		if(s->ball.pos.y+s->ball.dy>22 || s->ball.pos.y+s->ball.dy<1){
			s->ball.dy = -s->ball.dy;
		}

		// TODO: check for collision with obstacle
		if(rect_contains_point(&s->obstacle, &temp)){
			if(s->ball.pos.x > s->obstacle.topleft.x || s->ball.pos.x < s->obstacle.topleft.x+s->obstacle.width){
				s->ball.dx = -s->ball.dx;
			}
			else if(s->ball.pos.y > s->obstacle.topleft.y || s->ball.pos.y < s->obstacle.topleft.y+s->obstacle.height){
				s->ball.dy = -s->ball.dy;
			}
			else{
				s->ball.dx = -s->ball.dx;
				s->ball.dy = -s->ball.dy;
			}
		}
		
		// TODO: move ball
		s->ball.pos.x += s->ball.dx;
		s->ball.pos.y += s->ball.dy;
		
		// TODO: check to see if ball is in the cup
		if(rect_contains_point(&s->obstacle, &s->ball.pos)){
			s->mode = IN_CUP;
			cons_change_color(BLUE+INTENSE, BLACK);
			cons_move_cursor(12, 35);
			cons_printw(" Hole in 1!!! ");
		}
		
	}
}

void fill(int x, int y, int w, int h, int color) {
	cons_change_color(color, color);
	for (int j = y; j < y+h; j++) {
		for (int i = x; i < x+w; i++) {
			cons_move_cursor(j, i);
			cons_printw(" ");
		}
	}
}
