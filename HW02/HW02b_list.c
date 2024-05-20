
#include <stdio.h>
#include <string.h>

void border_1 (int digitA, int digitB, int digitC, int digitD)  {
                            
    printf("+");
    for (int i = 0; i < (6 + digitA); i++)  {
        printf("-");    
    }
    printf("+");

    for (int i = 0; i < (6 + digitB); i++)  {
        printf("-");    
    }
    printf("+");

    for (int i = 0; i < (6 + digitC); i++)  {
        printf("-");    
    }
    printf("+");

    for (int i = 0; i < (6 + digitD); i++)  {
        printf("-");    
    }
    printf("+\n");
}


void border_2 (int size)    {

    printf("+");
    for (int i = 0; i < size; i++)  {
        printf("-");
    }   
    printf("+");
}    


void state (char *koren, int size)    {
    
    printf("|");
    for (int i = 0; i < (size - 3 - strlen(koren)); i++)    {
        printf(" ");
    }
    printf(koren);
    printf("   |\n");
}

void results (int koefA, int koefB, int koefC, int dis) {
    printf("|   %d   |   %d   |   %d   |   %d   |\n", koefA, koefB, koefC, dis);
}


int digits (int koef)  {

        if (koef >= 0)  {
            int digit = 0;
            do   {  koef /= 10;
                    ++digit; 
            } while (koef != 0);
            return digit;
        }
        else    {
            int digit = 1;
            do   {  koef /= 10;
                    ++digit; 
            } while (koef != 0);
            return digit;
        }
    }


void table (int koefA, int koefB, int koefC)    {

    char koren_1[] = {"Jeden koren"};
    char koren_2[] = {"Dva realne koreny"};
    char koren_3[] = {"Dva imaginarni koreny"};

    int dis = koefB * koefB - 4 * koefA * koefC;

    int digitA = digits(koefA);
    int digitB = digits(koefB);
    int digitC = digits(koefC);
    int digitD = digits(dis);

    int size = 8*3 + 3 + digitA + digitB + digitC + digitD;

    if (dis < -999 || dis > 999)
        printf("Diskriminant mimo povoleny interval!\n");

    else if (dis == 0) {
        border_1(digitA, digitB, digitC, digitD);
        results(koefA, koefB, koefC, dis);
        border_1(digitA, digitB, digitC, digitD);
        state(koren_1, size);
        border_2(size);
    }
    else if (dis > 0) {
        border_1(digitA, digitB, digitC, digitD);
        results(koefA, koefB, koefC, dis);
        border_1(digitA, digitB, digitC, digitD);
        state(koren_2, size);
        border_2(size);
    }
    else if (dis < 0) {
        border_1(digitA, digitB, digitC, digitD);
        results(koefA, koefB, koefC, dis);
        border_1(digitA, digitB, digitC, digitD);
        state(koren_3, size);
        border_2(size);
    }

    printf("\n\n\n");
}



int main(int argc, char const *argv[])
{

    int in01[] = {10, 20, 10};
    int in02[] = {3, 0, 2};
    int in03[] = {-10, 2, 30};
    int in04[] = {3, 3, 0};

    table(in01[0], in01[1], in01[2]);
    table(in02[0], in02[1], in02[2]);
    table(in03[0], in03[1], in03[2]);
    table(in04[0], in04[1], in04[2]);

    return 0;
}