// TODO: add your code to this file
#include<stdio.h>

float hours, pay, overHrs;

int main(void){
	printf("Enter your hours: ");
	scanf("%f", &hours);
	printf("Enter your hourly rate: ");
	scanf("%f", &pay);
	printf("\n");
	printf("Number of hours worked: %.2fh \n", hours);
	printf("Hourly rate: $%.2f \n", pay);
	if (hours>=40){
		overHrs = hours-40;
		hours = 40;
	}
	printf("Overtime hours: %.2fh \n", overHrs);
	printf("Overtime rate: $%.2f \n", 1.5*pay);
	printf("Regular pay: $%.2f \n", pay*hours);
	printf("Overtime pay: $%.2f \n", 1.5*pay*overHrs);
	printf("Gross salary: $%.2f \n", (1.5*pay*overHrs)+(pay*hours));
	
	return 0;
}
