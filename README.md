# assertx.h

Detiene errores lógicos o de ejecución por medio de dos macros.

# Instalación

Agrega el archivo `assertx.h` en la carpeta del proyecto (donde está el código fuente del programa).

# Macros

- `assertr(condicion, mensaje)` = Esta macro se la usa especialmente en funciones que devuelvan un valor y si la condición llega a ser falsa, detiene la ejecución de la subrutina/función.

- `assertc(condicion, mensaje)` = Esta macro se la usa únicamente en bucles. Sí la condición llegara a dar un resultado de falsedad, genera otra iteración y detiene la ejecución del código que esté debajo de dicha macro.

- `CHANGE_VALUE_RETURN` = Esta macro cambia el valor de retorno de la macro `àssertr` (por defecto es 0).

# Aplicaciones

- Un ejemplo para prevenir un error de ejecución, el típico desbordamiento de búfer.
```C
#include "assertx.h"

int main(void)
{
	int array[10];
	int n;
	int i;
	while (1)
	{
		printf("Cuantos elementos quieres en el array?\n");
		scanf("%d", &n);
		assertc(n != 0, "ERROR: 0 elementos? No existe eso")
		assertc(n >= 1 && n <= 10, "ERROR: Posible buffer overflow")
		for (i = 0; i != n; ++i)
			array[i] = i;
		break;
	}
	for (i = 0; i != n; ++i)
		printf("%d\n", array[i]);
	getchar();
	getchar();
	return 0;
}
```
- Un ejemplo para prevenir un error lógico.
```C
#include <stdlib.h>

#define CHANGE_VALUE_RETURN EXIT_FAILURE
#include "assertx.h"

int main(void)
{
	int num;
	printf("Ingrese un numero par:\n");
	scanf("%d", &num);
	assertr(num % 2 == 0, "ERROR: No es par.")
	printf("%d es par\n", num);
	getchar();
	getchar();
	return EXIT_SUCCESS;
}
```

El mensaje de error de la macro `assertr` & `assertc` también puede ser una cadena formateada. 
- Ejemplo:
```C
#include "assertx.h"

int main(void)
{
	int option = 0;
	while (!(option >= 1 && option <= 3))
	{
		printf("Ingrese una opcion <1-3>:\n");
		scanf("%d", &option);
		assertc(option >= 1 && option <= 3, "ERROR: El numero %d no es una opcion valida", option)
		switch (option)
		{
			case 1:
				puts("Se cumplio la opcion 1");
				break;
			case 2:
				puts("Se cumplio la opcion 2");
				break;
			case 3:
				puts("Se cumplio la opcion 3");
		}
	}
	getchar();
	getchar();
	return 0;
}
```
La cadena formateada en ese ejemplo es: `"ERROR: El numero %d no es una opcion valida"`

# Código de prueba

```C
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
```

# Resultado en pantalla

[![prueba](https://i.imgur.com/XmAH6HB.png)](https://github.com/MrDave1999/assertx.h)

# Créditos

- [MrDave](https://github.com/MrDave1999) 
	- Por el desarrollo de assertx.h
- [Microsoft Corporation](https://github.com/Microsoft) 
	- Se usó el compilador `cl.exe` para poder compilar los códigos de prueba, de ese modo se comprueba sí no hubo algún error.
