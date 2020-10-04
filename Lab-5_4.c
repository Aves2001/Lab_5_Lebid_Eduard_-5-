#include <stdio.h>
#include "chcp.h"
#include "check_int.h"
#include <time.h>

#define Low -100
#define High 100

int main(void) {
set_chcp();

int n = 0;

do{
printf("\r\nВведіть розмір масива:\r\n");
n = scanf_check_int (0, "Розмір", 0, 0);

	if (n <= 0)
	{
		printf("\r\n%sРозмір масива не може дорівнювати, або бути меншим нулю!\r\n", Error);
	}
}while(n <= 0);

double A[n][n];
srand(time(0));

printf("\n");

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		int tmp = Low+rand()%(High - Low + 1);
		A[i][j] = tmp + pow(rand()%(100),0.1);
	}
}


for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		printf("A[%d][%d] = %.2lf \t", i, j, A[i][j]);
	}
	printf("\r\n");
}


double min = A[0][0];
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		if (A[i][j] < min && i+j < n-1)
		{
			min = A[i][j];
		}
	}
}

printf("\r\n\nМінімальний елемент серед елементiв,\r\nякi знаходяться вище бокової дiагоналi: %.2lf\r\n", min);


	reset_chcp();
	return 0;
}
