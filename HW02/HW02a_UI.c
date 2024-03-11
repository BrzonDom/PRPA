#include <stdio.h>

void fun_HW02a_UI (int Input1, int Input2)	{

	if (Input1 < -10000 | Input1 > 10000 | Input2 < -10000 | Input2 > 10000) {
		printf("Mimo interval");
				}
	else	{
		printf("Desitkova soustava: %d %d\n",Input1, Input2);
		printf("Sestnackova soustava: %x %x\n", Input1, Input2);
		printf("Soucet: %d + %d = %d\n", Input1, Input2, Input1 + Input2);
		printf("Rozdil: %d - %d = %d\n", Input1, Input2, Input1 - Input2);
		printf("Soucin: %d * %d = %d\n", Input1, Input2, Input1 * Input2);
		if (Input2 == 0)	{
			printf("Nedefinovany vysledek\n");	}
		else	{
			printf("Podil: %d / %d = %d\n", Input1, Input2, Input1 / Input2);	}
		double add = Input1 + Input2;
		double procento = add / 2;
		printf("Prumer: %.1lf\n", procento);


	}
		printf("\n");

}


int main(int argc, char const *argv[])
{

	int Input1, Input2;
	scanf("%d%d", &Input1, &Input2);
	// printf("1. cislo: ");
	// scanf("%d", &Input1);
	// printf("2. cislo: ");
	// scanf("%d", &Input2);


    fun_HW02a_UI(Input1, Input2);
    
    // int Input3;
    // scanf ("%i", &Input3);


	return 0;
}