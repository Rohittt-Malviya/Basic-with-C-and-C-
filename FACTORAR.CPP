#include<stdio.h>
#include<conio.h>

void main() {
    int numbers[5];
    int factorial[5];
    int i, j;


    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) {
	printf("Number %d: ", i + 1);
	scanf("%d", &numbers[i]);
    }


    for (i = 0; i < 5; i++) {
	int fact = 1;
	for (j = 1; j <= numbers[i]; j++) {
	    fact *= j;
	}
	factorial[i] = fact;
    }


    printf("\nFactorials value is:\n");
    for (i = 0; i < 5; i++) {
	printf("Factorial of %d is %d\n", numbers[i], factorial[i]);
    }


}