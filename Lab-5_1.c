#include <stdio.h>
#include "chcp.h"
#include "check_int.h"

int main(void) {
set_chcp();

int size = 0;
do{
printf("\r\nВведіть розмір масивів: a, b, c.\r\n\n");
size = scanf_check_int (0, "Розмір", 0, 0);
	
	if (size <=0)
	{
		printf("\r\n%sРозмір масивів не може дорівнювати, або бути меншим нулю!\r\n", Error);
	}
}while(size < 1);

int	a[size];
int b[size];
int c[size];

printf("\r\n\nВведіть масиви \"a\" та \"b\"\r\n\n");

	for (int i = 0; i < size; i++)
	{
		a[i] = scanf_check_int (1, "a", i, 0);
	}
	printf("\r\n");
	
		for (int i = 0; i < size; i++)
		{
			b[i] = scanf_check_int (1, "b", i, 0);
		}
		printf("\r\n");


			for (int i = 0; i < size; i++)
			{
				c[i] = a[i] - b[i];
			}
			

			// for (int i = 0; i < size; i++)
			// {
			// 	printf("c[%d] = %d - %d = %d", i, a[i], b[i], c[i]); printf("\r\n");
			// }

				printf("\r\n\t%43s\r\n\n", "Результат: a[i] - b[i] = c[i]");
				for (int i = 0; i < size; i++)
				{
					printf("\ta[%d] = %d \tb[%d] = %d \tc[%d] = %d", i, a[i], i, b[i], i, c[i]); printf("\r\n");
				}

	reset_chcp();
	return 0;
}
