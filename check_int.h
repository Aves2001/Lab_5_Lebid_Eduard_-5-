#include <math.h>

// char debug = 1;

//					   lvl	text   i  j
//				      [0-2]
// x = scanf_check_int (0, "text", 0, 0);

int scanf_check_int (char lvl, char printf_x[], int massiv_i, int massiv_j)
{
#define N 13
#define Error "\a[Error] "

char int_max[10] = "2147483647";
char int_min[11] = "-2147483648";

char error = 0;
char s[N] = "0";
int scan_sum = 0;
char minus = 0;
int result = 0;

do{
error = 0;
scan_sum = 0;
minus = 0;

if (lvl == 0)
{
	printf("%s = ", printf_x);

} else	if (lvl == 1)
		{
			printf("%s[%d] = ", printf_x, massiv_i);

		}else printf("%s[%d][%d] = ", printf_x, massiv_i, massiv_j);


fgets(s, N, stdin);
fflush(stdin);

if (s[0] == '\n')
{
	printf("\r\n%sВведіть хоть щось будьласка\r\n\n", Error);
	error = 1;
	continue;
} else	if (s[0] == '-' && s[1] == '\n')
		{
			printf("\r\n%sПросто мінус? Серйозно!?\r\n\n", Error);
			error = 1;
			continue;
		}

for (int i = 0; i < N; i++)
{
	if (s[i] == '.')
	{
		if (lvl == 0)
		{
			printf("\r\n%sВи ввели неправильне значення. \"%s\" Має бути цілим числом\r\n\n", Error, printf_x);
			error = 1;
			break;

		} else	if (lvl == 1)
				{
					printf("\r\n%sВи ввели неправильне значення. \"%s[%d]\" Має бути цілим числом\r\n\n", Error, printf_x, massiv_i);
					error = 1;
					break;
				
				} else	if (lvl == 2)
						{
							printf("\r\n%sВи ввели неправильне значення. %s[%d][%d] Має бути цілим числом\r\n\n", Error, printf_x, massiv_i, massiv_j);
							error = 1;
							break;
						}
	}

	if (s[i] == '-')
	{
		minus++;

	}

	if (s[i] == '\n')
	{
		break;

	} else scan_sum++;
}

// printf("-------|Кількість мінусів = %d |---------\n", minus); //debug
// printf("---------|Кількість введених символів| %d |-------\r\n", scan_sum); //debug

	if (scan_sum > 9)
	{
		if (s[0] == '-')
		{
			for (int i = 1; i < scan_sum; i++)
			{
				if (s[i] > int_min[i])
				{
					printf("\r\n\n%sПрограма не розрахована на обчислення таких великих чисел\r\n\n", Error);
					error = 1;
					break;
				}
			}
		} else	for (int i = 0; i < scan_sum; i++)
				{
					if (s[i] > int_max[i])
					{
						printf("\r\n\n%sПрограма не розрахована на обчислення таких великих чисел\r\n\n", Error);
						error = 1;
						break;
					}
				}

		if (error == 1)
		{
			continue;
		}
		
	}

	for (int i = 0; i < scan_sum; i++)
	{

		if (s[i] == ' ')
		{
			printf("\r\n%sПробіл був лишнім введіть нормально будьласка!\r\n\n", Error);
			error = 1;
			break;
					//45 = -				//від 0 до 9		// не більше 1-го мінуса
		} else  if ((s[0] == 45 || s[i] >= 48 && s[i] <= 57) && (minus <= 1))
				{
				// printf("\r\ns[%d] = %d ---| Добре |---\r\n\n", i, s[i]); //debug
				
				} else	if (lvl == 0)
						{
							printf("\r\n%sВи ввели неправильне значення \"%s\"\r\n\n", Error, printf_x);
							error = 1;
							break;

						} else	if (lvl == 1)
								{
									printf("\r\n%sВи ввели неправильне значення \"%s[%d]\"\r\n\n", Error, printf_x, massiv_i);
									error = 1;
									break;
								
								} else	if (lvl == 2)
										{
											printf("\r\n%sВи ввели неправильне значення %s[%d][%d]\r\n\n", Error, printf_x, massiv_i, massiv_j);
											error = 1;
											break;
										}
	}

}while (error == 1);


// printf("\r\n\n"); //debug
// for (int i = 0; i < N; i++) //debug
// { //debug
	// printf("---------| s[%d] = %d [%c]|-------\r\n", i, s[i], s[i]); //debug
// } //debug
// printf("\r\n\n"); //debug

result = atoi(s);
// printf("----|scanf_check_int| result = %d |-----\n", result); //debug

return result;
}
