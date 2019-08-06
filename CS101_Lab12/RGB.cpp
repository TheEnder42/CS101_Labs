#include <stdio.h>
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
int red_out[WIDTH*2][HEIGHT*2];
int green_out[WIDTH*2][HEIGHT*2];
int blue_out[WIDTH*2][HEIGHT*2];

int main(void)
{
	ReadImage("kitten.bmp", red, green, blue);

	// TODO: transform data, storing transformed data in
	//       the red_out, green_out, and blue_out arrays
	for(int i=0; i<WIDTH; i++){
		for(int k=0; k<HEIGHT; k++){
		red_out[i][k]=red[i][k];
		red_out[i+WIDTH][k+HEIGHT]=red[i][k];
		}
	}
	for(int i=0; i<WIDTH; i++){
		for(int k=0; k<HEIGHT; k++){
		green_out[i+WIDTH][k]=green[i][k];
		green_out[i+WIDTH][k+HEIGHT]=green[i][k];
		}
	}
	for(int i=0; i<WIDTH; i++){
		for(int k=0; k<HEIGHT; k++){
		blue_out[i][k+HEIGHT]=blue[i][k];
		blue_out[i+WIDTH][k+HEIGHT]=blue[i][k]; 
		}
	}
	
	WriteDoubleSizeImage("rgb.bmp", red_out, green_out, blue_out);	
	printf("Done writing image\n");

	return 0;
}
