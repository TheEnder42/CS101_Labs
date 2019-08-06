#include <stdio.h>
#include <math.h>
#include "Console.h"

struct Complex {
	// TODO: add fields
	double real, imag;
};

// Function prototypes
struct Complex complex_create(double real, double imag);
struct Complex complex_add(struct Complex c1, struct Complex c2);
struct Complex complex_multiply(struct Complex c1, struct Complex c2);
double complex_magnitude(struct Complex c);
double complex_get_real(struct Complex c);
double complex_get_imaginary(struct Complex c);

// Mandelbrot computation
int mandelbrot_num_iters(struct Complex c, int max_iters);

// Complex function tests, Mandelbrot set visualization
void test(void);
void mandelbrot(void);

int main(void)
{
	int choice;
	printf("(1) Run tests, or (2) Mandelbrot set? ");
	scanf("%i",  &choice);

	if (choice == 1) {
		test();
	} else if (choice == 2) {
		mandelbrot();
	} else {
		printf("Invalid choice\n");
	}

	return 0;
}

struct Complex complex_create(double real, double imag)
{
	// TODO
	struct Complex temp;
	temp.real = real;
	temp.imag = imag;
	return temp;
}

struct Complex complex_add(struct Complex c1, struct Complex c2)
{
	// TODO
	struct Complex temp;
	temp.real = c1.real+c2.real;
	temp.imag = c1.imag+c2.imag;
	return temp;
}

struct Complex complex_multiply(struct Complex c1, struct Complex c2)
{
	// TODO
	struct Complex temp;
	temp.real = c1.real*c2.real - c1.imag*c2.imag;
	temp.imag = c1.imag*c2.real + c1.real*c2.imag;
	return temp;
}

double complex_magnitude(struct Complex c)
{
	// TODO
	return sqrt(c.real*c.real + c.imag*c.imag);
}

double complex_get_real(struct Complex c)
{
	// TODO
	return c.real;
}

double complex_get_imaginary(struct Complex c)
{
	// TODO
	return c.imag;
}

void test(void)
{
	int fail_count = 0;
#define CHECK(expr, what) \
do { \
	int outcome = (expr); \
	printf("%s: %s\n", what, outcome ? "passed" : "failed"); \
	if (!outcome) { fail_count++; } \
} while (0)

	struct Complex c1 = complex_create(3.0, 4.0);
	struct Complex c2 = complex_create(5.0, 6.0);

	CHECK(complex_get_real(c1) == 3.0, "complex_get_real (first test)");
	CHECK(complex_get_real(c2) == 5.0, "complex_get_real (second test)");
	CHECK(complex_get_imaginary(c1) == 4.0, "complex_get_imaginary (first test)");
	CHECK(complex_get_imaginary(c2) == 6.0, "complex_get_imaginary (second test)");

	struct Complex sum = complex_add(c1, c2);
	CHECK(complex_get_real(sum) == (3.0 + 5.0), "complex_add (real part)");
	CHECK(complex_get_imaginary(sum) == (4.0 + 6.0), "complex_add (imaginary part)");

	struct Complex prod = complex_multiply(c1, c2);
	CHECK(complex_get_real(prod) == (3.0*5.0 - 4.0*6.0), "complex_multiply (real part)");
	CHECK(complex_get_imaginary(prod) == (4.0*5.0 + 3.0*6.0), "complex_multiply (imaginary part)");

	CHECK(complex_magnitude(c1) == sqrt(3.0*3.0 + 4.0*4.0), "complex_magnitude");

	if (fail_count == 0) {
		printf("All tests passed!\n");
	} else {
		printf("At least one test failed\n");
	}
}

int mandelbrot_num_iters(struct Complex c, int max_iters)
{
	// TODO
	int iters=0;
	bool done = false;
	struct Complex z;
	z = complex_create(0, 0);
	while(!done){
		z = complex_multiply(z, z);
		z = complex_add(z, c);
		if(complex_magnitude(z)<2 && iters<max_iters){
			iters++;
		}
		else{
			done=true;
		}
	}
	if(iters>max_iters){
		return max_iters;
	}
	return iters;
}

#define START_X -1.5
#define WIDTH   2.0
#define START_Y -1.0
#define HEIGHT  2.0

void mandelbrot(void)
{
	int nrows = cons_get_screen_height();
	int ncols = cons_get_screen_width();

	nrows--; // don't use bottom row

	cons_clear_screen();

	for (int j = 0; j < nrows; j++) {
		for (int i = 0; i < ncols; i++) {
			double real = START_X + i*(WIDTH/ncols);
			double imag = START_Y + j*(HEIGHT/nrows);
			int num_iters = mandelbrot_num_iters(complex_create(real, imag), 640);
			int color = BLACK;
			if (num_iters < 10) {
				color = MAGENTA;
			} else if (num_iters < 20) {
				color = BLUE;
			} else if (num_iters < 40) {
				color = BLUE+INTENSE;
			} else if (num_iters < 80) {
				color = GREEN;
			} else if (num_iters < 160) {
				color = GREEN+INTENSE;
			} else if (num_iters < 320) {
				color = YELLOW+INTENSE;
			} else if (num_iters < 640) {
				color = GRAY+INTENSE;
			}
			cons_change_color(BLACK, color);
			cons_move_cursor(j, i);
			cons_printw(" ");
		}
	}

	cons_change_color(GRAY, BLACK);
	cons_move_cursor(nrows, 0);
	cons_printw("Press any key to continue...");

	cons_update();

	cons_wait_for_keypress();
}
