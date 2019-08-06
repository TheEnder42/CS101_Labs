#include <stdio.h>
#include <math.h>
#include "Image.h"

// Arrays to store image color component data.
// Note that it is normally not a good practice to define
// variables/arrays in the global scope.  However, because
// these arrays have a large number of elements, they
// are too large to define within a function (such as main)
// on some systems.
int red[WIDTH][HEIGHT];
int green[WIDTH][HEIGHT];
int blue[WIDTH][HEIGHT];

int main(void)
{
	ReadImage("kitten.bmp", red, green, blue);

	// TODO: transform data
	for(int i=0; i<WIDTH; i++){
		for(int k=0; k<HEIGHT; k++){
			double hdist = (i+1.0)/WIDTH;
			double vdist = (k+1.0)/HEIGHT;
			double fade = sin(hdist*M_PI) * sin(vdist*M_PI);
			red[i][k] = fade * red[i][k];
			green[i][k] = fade * green[i][k];
			blue[i][k] = fade * blue[i][k];
		}
	}
	WriteImage("fade.bmp", red, green, blue);
	printf("Done writing image\n");

	return 0;
}
