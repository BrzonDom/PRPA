#include <stdio.h>

void fun_HW02a_list (int Input1, int Input2)	{

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

	int in01[] = {11, 24};
    int in02[] = {152, 0};
    int in03[] = {10001, 125};
    int in04[] = {212, -78, 5, 16, 32};

    fun_HW02a_list(in01[0], in01[1]);
    fun_HW02a_list(in02[0], in02[1]);
    fun_HW02a_list(in03[0], in03[1]);
    fun_HW02a_list(in04[0], in04[1]);

	return 0;
}