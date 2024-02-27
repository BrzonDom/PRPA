#include <stdio.h>
#include <math.h>
#include <string.h>


void fun_HW03a (int Input[], int pocet)	{
	int klad, zapor, sud, lich, add, max, min;
        klad = zapor = sud = lich = add = max = min = 0;
    double procento;

    for (int i = 0; i < pocet; i++)  {
        if (10000 < Input[i] | Input[i] < -10000)   {
            printf("\nVstup je mimo interval!\n");
            return;     }
        else    {
            printf("%d, ", Input[i]);   }
        }


    for (int i = 0; i < pocet; i++)  {
        add += Input[i];
            if (Input[i] > 0) {
                klad += 1;
                if (Input[i] % 2 == 0)
                    sud += 1;
                else
                    lich += 1;
            }
            else if (Input[i] < 0) {
                zapor += 1;
                if (Input[i] % 2 == 0)
                    sud += 1;
                else
                    lich += 1;
                }
        }

            for (int i = 0; i < pocet; i++)  {
            if (Input[i] > max)
                max = Input[i];
            else if (Input[i] < min)
                min = Input[i];
        }


        printf("\nPocet cisel: %d", pocet);
        printf("\nPocet kladnych cisel: %d", klad);
        printf("\nPocet zapornych cisel: %d", zapor);
                procento = ((100 * (double) klad) / pocet);
        printf("\nProcento kladnych cisel: %.2f", procento);
                procento = ((100 * (double) zapor) / pocet);
        printf("\nProcento zapornych cisel: %.2f",procento);
        printf("\nPocet sudych cisel: %d", sud);
        printf("\nPocet lichych cisel: %d", lich);
                procento = ((100 * (double) sud) / pocet);
        printf("\nProcento sudych cisel: %.2f", procento);
                procento = ((100 * (double) lich) / pocet);
        printf("\nProcento lichych cisel: %.2f", procento);
                procento = ((double) add / pocet);
        printf("\nPrumer: %.2lf",procento);
        printf("\nMaximum: %d", max);
        printf("\nMinimum: %d", min);
        printf("\n\n");


}

int main(int argc, char const *argv[])
{

	int pocet;

	int in01[] = {212, -78, 5, 16, 32};
	pocet = sizeof(in01)/sizeof(int);
	fun_HW03a(in01, pocet);


    int in02[] = {140, 128, 8, 1603, 4905, -3, -2, 0, 0,
                  9166, 255, -1322, 8900, 10000, -1, 6543};
    pocet = sizeof(in02)/sizeof(int);
	fun_HW03a(in02, pocet);

    int in03[] = {-12, 15, 523, 26, -15000, 1};
    pocet = sizeof(in03)/sizeof(int);
	fun_HW03a(in03, pocet);

    // char Inloc1[] = "data\\pub01.in"; char Outloc1[] = "data\\pub01.out";
    // char Inloc2[] = "data\\pub02.in"; char Outloc2[] = "data\\pub02.out";
    // char Inloc3[] = "data\\pub03.in"; char Outloc3[] = "data\\pub03.out";

    // fun_HW03a_InOut(Inloc1, Outloc1);
    // fun_HW03a_InOut(Inloc2, Outloc2);
    // fun_HW03a_InOut(Inloc3, Outloc3);


	return 0;
}