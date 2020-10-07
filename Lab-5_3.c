#include <stdio.h>
#include "chcp.h"
#include "check_int.h"

int main(void) {
set_chcp();

int n = 0;
int m = 0;

printf("\r\nВведіть розмір масива:\r\n\n");
n = scanf_check_int (0, "Кількість рядків", 0, 0, bil_0 = 1);
m = scanf_check_int (0, "Кількість стовпчиків", 0, 0, bil_0 = 1);

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

int max_i = 0;
int max_j = 0;

int min_i = 0;
int min_j = 0;

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		if (A[i][j] > max)
		{
			max = A[i][j];
			max_i = i;
			max_j = j;
		}

		if (A[i][j] < min)
		{
			min = A[i][j];
			min_i = i;
			min_j = j;
		}
	}
}

printf("\r\n\nМаксимальне число: \tA[%d][%d] = %d\r\n",max_i, max_j, max);
printf("Мінімальне число: \tA[%d][%d] = %d\r\n",min_i, min_j, min);

printf("\r\nСереднє арифметичне максимального\r\nта мінімального елементів матриці: %.2f\r\n", (float)(max+min)/2);

	reset_chcp();
	return 0;
}
