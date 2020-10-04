#include <windows.h>
// #include <conio.h>

int chcp, chcpOut;

void set_chcp()
{	
// Збереження значення chcp
	chcp = GetConsoleCP();
	chcpOut = GetConsoleOutputCP();

//------------UTF-8--------------
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
//-------------------------------
}

void reset_chcp()
{
	// Повернення значення chcp яке було до запуску програми
	SetConsoleCP(chcp);
	SetConsoleOutputCP(chcpOut);
	// getch();
	printf("\r\n");
	system("pause");
	
}
