// TODO: add your code to this file
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	printf("Enter the current temperature: ");
	float temp;
	scanf("%f", &temp);
	printf("What is the chance of precipitation (in percentage): ");
	float perc;
	scanf("%f", &perc);
	printf("\n");
	//printf("temp: %f \n", temp);
	//printf("chance: %f \n", perc);
	if(temp>90){
		printf("It’s a scorcher!\n");
	}
	else if(temp<=90 && temp>70){
		printf("It’s a warm day.\n");
	}
	else if(temp<=70 && temp>32){
		printf("It’s a cool day.\n");
	}
	else if(temp<=32 && temp>0){
		printf("It’s very cold outside.\n");
	}
	else{
		printf("You’ll freeze out there.\n");
	}
	
	srand(time(0));
	int rain = rand()%100;
	//printf("rndm: %i \n", rain);
	if(rain<perc && temp>=32){
		printf("It's raining, better bring an umbrella.");
	}
	else if(rain<perc && temp<32){
		printf("It's snowing, put on your boots.");
	}
	else if(rain>=perc && temp<32){
		printf("No snow today.");
	}
	else{
		printf("No rain today.");
	}
	return 0;
}