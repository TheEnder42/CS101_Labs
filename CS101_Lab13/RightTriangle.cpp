#include<stdio.h>
#include<stdbool.h>


/* function prototypes */
void print_spaces(int num_spaces);
void print_line(int line_length, int height);


int main(void) {
	int height;
    // TODO: Enter your code here
    printf("Enter the height for your triangle: ");
	scanf("%i", &height);
	for(int i=1; i<height+1; i++){
		print_spaces(height-i);
		print_line(i, height);
		printf("\n");
	}
    
    return 0;
}


//prints a specified number of spaces
void print_spaces(int num_spaces) {
    for (int i=1; i <= num_spaces; i++) {
        printf(" ");
    }
}


//prints a specified number of stars
void print_line(int line_length, int height) {
    for (int i=1; i <= line_length; i++) {
        if(i==1){
			printf("/");
		}
		else if(i==line_length && line_length>1){
			printf("|");
		}
		else{
			if(line_length==height){
				printf("-");
			}
			else{
				printf(" ");
			}
		}
    }
}