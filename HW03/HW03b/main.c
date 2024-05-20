
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int num, pocet, prev;
        pocet = 0;

    while (scanf("%d", &num) != EOF) {

        if (pocet == 0) {
            pocet++;
            }
        else if (num == prev) {   
            pocet++;
            }
        else if (num != prev) {
            if (pocet > 1) {
                printf("%dx %d\n", pocet, prev);
                pocet = 1;
            }
        }
        prev = num;

        if (100 < num | num < 0)   {
            printf("Error: Vstup je mimo interval!\n");
            return 100;     
        }
    }   

    if (pocet > 1) {
        printf("%dx %d\n", pocet, prev);
    }

    return 0;

}
