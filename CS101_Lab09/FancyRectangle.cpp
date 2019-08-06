// TODO: add your code to this file
#include<stdio.h>

int main(void){
	int rows, columns;
	char special;
	printf("Number of rows: ");
	scanf("%i", &rows);
	printf("Number of columns: ");
	scanf("%i", &columns);
	printf("Special character: ");
	scanf(" %c", &special);
	
	printf("\n");
	for(int i=0; i<rows; i++){
		for(int k=0; k<columns; k++){
			if((i==1 or i==rows-2)&&(k==1 or k==columns-2)){
				printf("%c", special);
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}
}