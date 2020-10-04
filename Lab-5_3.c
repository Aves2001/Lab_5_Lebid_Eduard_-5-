#include <stdio.h>
#include "chcp.h"
#include "check_int.h"

int main(void) {
set_chcp();

int n = 0;
int m = 0;

do{
printf("\r\nВведіть розмір масива:\r\n\n");
n = scanf_check_int (0, "Кількість рядків", 0, 0);
m = scanf_check_int (0, "Кількість стовпчиків", 0, 0);

	if (n <= 0 || m <= 0)
	{
		printf("\r\n%sРозмір масива не може дорівнювати, або бути меншим нулю!\r\n", Error);
	}
}while(n <= 0 || m <= 0);

int	A[n][m];

printf("\n");
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		A[i][j] = scanf_check_int (2, "A", i, j);
	}
	printf("\r\n");
}


printf("\r\nМатриця А:\r\n\n");
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		printf("A[%d][%d] = %d\t", i, j, A[i][j]);
	}
	printf("\r\n");
}


int max = A[0][0];
int min = A[0][0];
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		if (A[i][j] > max)
		{
			max = A[i][j];
		}

		if (A[i][j] < min)
		{
			min = A[i][j];
		}
	}
}

printf("\r\n\nМаксимальне число: %d\r\n", max);
printf("Мінімальне число: %d\r\n", min);

printf("\r\nСереднє арифметичне максимального\r\nта мінімального елементів матриці: %d\r\n", (max+min)/2);

	reset_chcp();
	return 0;
}
