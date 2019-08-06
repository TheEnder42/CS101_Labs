#include<stdio.h>
#include<math.h>

/* function prototypes */
double meanf(int stats[]);
double stdvf(int stats[], double mean);
int minf(int stats[]);
int maxf(int stats[]);


int main(void){
	int stats[4];
	int min, max;
	double mean, stdv;
	
	printf("Enter four integer values: ");
	scanf("%i %i %i %i", &stats[0], &stats[1], &stats[2], &stats[3]);
	
	min = minf(stats);
	max = maxf(stats);
	mean = meanf(stats);
	stdv = stdvf(stats, mean);
	
	printf("\nThe mean of your values is %.02lf\n", mean);
	printf("The standard deviation of your values is %.02lf\n", stdv);
	printf("The max of your values is %i\n", max);
	printf("The min of your values is %i\n", min);
}

int minf(int stats[]){
	int temp = stats[0];
	for(int i=0; i<4; i++){
		if(stats[i]<temp){
			temp = stats[i];
		}
	}
	return temp;
}

int maxf(int stats[]){
	int temp = stats[0];
	for(int i=0; i<4; i++){
		if(stats[i]>temp){
			temp = stats[i];
		}
	}
	return temp;
}

double meanf(int stats[]){
	double sum;
	for(int i=0; i<4; i++){
		sum += stats[i];
	}
	sum /= 4.0;
	return sum;
}

double stdvf(int stats[], double mean) {
    double stdvTemp[4];
	double temp=0,sum=0;
	for(int i=0; i<4; i++){
		stdvTemp[i]= pow((stats[i]-mean),2);
	}
	for(int i=0; i<4; i++){
		sum += stdvTemp[i];
	}
	temp=sqrt(sum/4.0);
	return temp;
}