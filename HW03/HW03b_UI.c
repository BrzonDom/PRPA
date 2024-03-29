
#include <stdio.h>

int main(int argc, char const *argv[])  {

    int num, pocet, prev;
        pocet = 0;

    int i, listNum, len;
    int list[] = {111, 2, 1, 1, 111, 1, 2};
    len = 7;

    
    for (i = 0; i < len; i++) {
        listNum = list[i];

        if (pocet == 0) {
            pocet++;
            }
        else if (listNum == prev) {   
            pocet++;
            }
        else if (listNum != prev) {
            if (pocet > 1) {
                printf("%dx %d\n", pocet, prev);
                pocet = 1;
            }
        }
        prev = listNum;

        if (listNum > 100 | listNum < 0)   {
            printf("Error: Vstup je mimo interval!\n");
            return 100;     
        }
    }

    if (pocet > 1) {
        printf("%dx %d\n", pocet, prev);
        pocet = 1;
    }

    // while (scanf("%d", &num) != EOF) {
    //     if (100 < num | num < 0)   {
    //         printf("\nError: Vstup je mimo interval!\n");
    //         return 100;     
    //         }
    //     else if (pocet == 0) {
    //         pocet++;
    //         }
    //     else if (num == prev) {   
    //         pocet++;
    //         }
    //     else if (num != prev) {
    //         if (pocet > 1) {
    //             printf("%dx %d\n", pocet, prev);
    //             pocet = 1;
    //         }
    //     }
    //     prev = num;
    // }  

    return 0;

}