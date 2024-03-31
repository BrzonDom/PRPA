
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    int shift, turn, same, max, lenC, lenE, i, j, k, l;
    shift = same = turn = max = i = j = 0;
    lenC = lenE = 0;

    char letter;
    char nL1, nL2;
    int len;

    scanf("%d", &len);

    // scanf("%c", &nL1);

    // printf("%d", len);

    char* coded = (char*) malloc((len+1)* sizeof(char));
    char* example = (char*) malloc((len+1)* sizeof(char));
    char* solution = (char*) malloc(len* sizeof(char));

    scanf("%c", &nL1);

    for (i = 0; i < (len + 1); i++) {
        scanf("%c", &coded[i]); 
        lenC++; }

    printf("Is: ");
    if (!(coded[lenC - 1] != '\n')) printf("true, on len: %d\n", (lenC));
    else printf("false, is '%c'\n", coded[lenC]);
    printf("LenC: %d\n", lenC);

    

    // scanf("%c", &nL2);
    
    for (i = 0; i < (len + 1); i++) {
        scanf("%c", &example[i]); 
        lenE++; }

    printf("Is: ");
    if (!(example[lenE - 1] != '\n')) printf("true, on len: %d\n", (lenE));
    else printf("false, is '%c'\n", example[lenE]);
    printf("LenE: %d\n", lenE);


    
    //     printf("%c", code[i]);
    //     if (('a' <= code[i] & code[i] <= 'z') | ('A' <= code[i] & code[i] <= 'Z')) {
    //         printf("%c",code[i]);
    //     }
    //     else if (code[i] == '\n') {
            
    //     }
    // }
    // i = 0;
    // while ((scanf("%c", &coded[i])) != '\n') {
    //     // coded[i] = letter; 
    //     i++;
    // }
    // if (i != (len - 1)) {fprintf(stderr,"Error: Chybna delka vstupu!\n"); return 101;}
    
    // do {
    //     scanf("%c", &coded[lenC++]);
    //     lenC++;
    // } while (coded[lenC - 1] != '\n');
    // if (lenC != (len)) {fprintf(stderr,"Error: Chybna delka vstupu!\n"); return 101;}
    
    // do {
    //     scanf("%c", &example[lenE]);
    //     lenE++;
    // } while (example[lenE - 1] != '\n');
    // if (lenE != (len)) {fprintf(stderr,"Error: Chybna delka vstupu!\n"); return 101;}
    
    // j = 0;
    // while ((scanf("%c", &example[j])) != '\n') {
    //     // example[j] = letter;
    //     j++;
    // }
    // if (j != (len - 1)) {fprintf(stderr,"Error: Chybna delka vstupu!\n"); return 101;}
    

    // scanf("%c" &nL2);
    
    printf("\n");
    for (k = 0; k < len; k++) {
        printf("%c", coded[k]);
    }

    printf("\n");

    for (k = 0; k < len; k++) {
        printf("%c", example[k]);
    }

    // printf("\n\n");
    // printf("---%c---%c---\n", nL1, nL2);

    // if (!(nL1 != '\n')) printf("true\n");
    // if (!(nL2 != '\n')) printf("true\n");

    // for (i = 0; i < len; i++) {
                    //     scanf("%c", &example[i]);
                    //     printf("%c", coded[i]);

    //     if (('a' <= coded[i] & coded[i] <= 'z') | ('A' <= coded[i] & coded[i] <= 'Z')) {
    //         printf("%c",coded[i]);
    //     }
                    //     else {}
                    // }
                    //     // else if (code[i] == '\n') {
                            
                    //     // }
                    // }
                    // printf("\n");
                    // for (i = 0; i < len; i++) {
                    //     printf("%c", example[i]);
                    // }

    // while (scanf("%c", &letter) != EOF) {
    //     if (!(('a' <= inputData & inputData <= 'z') | ('A' <= inputData & inputData <= 'Z'))) {
    //         fprintf(stderr,"Error: Chybny vstup!\n");
    //         return 100;
    //     }

    // }
    printf("\n");

        for (i = 0; i < 54; i++)    {
            printf("%d. ", i);
            for (j = 0; j < (len); j++)   {
                printf("%c", coded[j]);
                if (coded[j] == example[j]) same++;
            }

            if (same > max) {
                for (l = 0; l < len; l++)   {
                    solution[l] = coded[l];
                }

                turn = l;
                max = same;

            }
//            sameL[i] = same;
            printf(" %d same letters\n", same);
            same = 0;
            for (l = 0; l < (len); l++) {
                if (coded[l] == 'z')    coded[l] = 'A';
                else if (coded[l] == 'Z')     coded[l] = 'a';
                else coded[l] = (char)(coded[l] + 1);
            }
        }

        printf("\n");

        printf("On turn: %d is the solution: ", turn);
        for (i = 0; i < len; i++)   {
           printf("%c",solution[i]);
        }

}