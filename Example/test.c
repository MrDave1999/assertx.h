#include "assertx.h"

int function1(void)
{
	int x;
	printf("Ingrese un numero positivo:\n");
	scanf("%d", &x);
	assertr(x >= 0, "ERROR: Debes ingresar un numero positivo.")
	printf("%d es un numero positivo.\n", x);
	return 1;
}

int main(void)
{
	while (1)
	{
		assertc(function1() != 0, "")
		break;
	}
	getchar();
	getchar();
	return 0;
}
