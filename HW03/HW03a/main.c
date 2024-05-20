
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int num, klad, zapor, sud, lich, add, max, min, pocet, i;
        klad = zapor = sud = lich = add = pocet = 0;
    double procento;

    while (scanf("%d", &num) != EOF) {

        if (10000 < num | num < -10000)   {
            printf("\nError: Vstup je mimo interval!\n");
            return 100;     }
        else if (pocet == 0) {
            printf("%d", num);
            max = min = num;
            pocet++;
        }
        else    {
            printf(", %d", num);   
            pocet++;
            }
        
        add += num;
            if (num > 0) {
                klad ++;
                if (num % 2 == 0)
                    sud ++;
                else
                    lich ++;
            }
            else if (num < 0) {
                zapor ++;
                if (num % 2 == 0)
                    sud ++;
                else
                    lich ++;
                }
            else if (num == 0) sud++;
        

        for (int i = 0; i < pocet; i++)  {
            if (num > max)
                max = num;
            else if (num < min)
                min = num;
        }
    }


    printf("\nPocet cisel: %d", pocet);
    printf("\nPocet kladnych: %d", klad);
    printf("\nPocet zapornych: %d", zapor);
            procento = ((100 * (double) klad) / pocet);
    printf("\nProcento kladnych: %.2f", procento);
            procento = ((100 * (double) zapor) / pocet);
    printf("\nProcento zapornych: %.2f",procento);
    printf("\nPocet sudych: %d", sud);
    printf("\nPocet lichych: %d", lich);
            procento = ((100 * (double) sud) / pocet);
    printf("\nProcento sudych: %.2f", procento);
            procento = ((100 * (double) lich) / pocet);
    printf("\nProcento lichych: %.2f", procento);
            procento = ((double) add / pocet);
    printf("\nPrumer: %.2lf",procento);
    printf("\nMaximum: %d", max);
    printf("\nMinimum: %d", min);
    printf("\n");
        
    return 0;

}
