#include<stdio.h>

int main(void) {
	int inputs, sum, quit, temp;

  // TODO: add your code for Part 1 here
  while(quit==0){
	  printf("Enter a value to include in the average: ");
	  scanf("%i", &temp);
	  if(temp>=0){
		  sum += temp;
		  inputs += 1;
	  }
	  else{
		  quit = 1;
		  if(inputs==0){
			  printf("No values were input");
		  }
		  else{
			  printf("The average of the %i values input is: %.02f", inputs, (float)sum/(float)inputs);
		  }
	  }
 }
    printf("\n \n");


  // TODO: add your code for Part 2 here
	float cents=.01, total=0, desired;
	int day = 1;
	printf("How much money do you want (in dollars)? ");
	scanf("%f", &desired);
	while(total<desired){
		total += cents;
		printf("Day %i: Given $%.02f, you now have $%.02f \n", day, cents, total);
		day += 1;
		cents *= 2;
	}
	printf("On day %i, you will have met (or exceeded) your request for $%.02f with a total of $%.02f.", day-1, desired, total);


}


