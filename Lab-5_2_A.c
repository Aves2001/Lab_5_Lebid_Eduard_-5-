#include <stdio.h>
#include "chcp.h"
#include "check_int.h"

int main(void) {
set_chcp();

int size = 0;
do{
printf("\r\nВведіть розмір масивів:\r\n\n");
size = scanf_check_int (0, "Розмір", 0, 0);
	
	if (size <=0)
	{
		printf("\r\n%sРозмір масива не може дорівнювати, або бути меншим нулю!\r\n\n", Error);
	}
}while(size < 1);

int	n[size];

printf("\r\n");

	for (int i = 0; i < size; i++)
	{
		n[i] = scanf_check_int (1, "n", i, 0);
	}
	printf("\r\n");

int max = n[0];
	for (int i = 0; i < size; i++)
	{
		if (n[i] > max)
		{
			max = n[i];
		}
	}

	printf("\r\n1) Максимальний елемент масиву: %d\r\n", max);


int d_1 = -1, d_2 = -1, summ = 0;
for (int i = 0; i < size; i++)
{
	if (n[i] > 0)
	{
		d_1 = i;

			for (int k = i+1; k < size; k++)
			{
				if (n[k] > d_2)
						{
							d_2 = k;
							break;
						}		
			}
	break;
	}
}

if (d_1 != -1 && d_2 != -1)
{
	printf("\r\nПерше додатне число: n[%d] = %d\r\n", d_1, n[d_1]);
	printf("Друге додатне число: n[%d] = %d\r\n", d_2, n[d_2]);

		for (; d_1 <= d_2; d_1++)
		{
			summ += n[d_1];
		}
			printf("\r\n2) Сумма елементів масиву,\n   розташованих між першим й другим\n   додатними елементами: %d\r\n", summ);

}else	if (d_1 != -1 && d_2 == -1)
		{
			printf("\r\n2) В масиві тільке одне додатнє число\r\n");
		} else printf("\r\n2) В масиві немає додатніх чисел\r\n");







	reset_chcp();
	return 0;
}
