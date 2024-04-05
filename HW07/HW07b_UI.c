#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    int i, j, k, l, add;
    char operation, newL;
    int rowA, colA, rowB, colB, row, col;
    row = col = 0;

    scanf("%d%d", &rowA, &colA);

    scanf("%c", &newL);
    
    int** matA = (int**) malloc(rowA* sizeof(int*));
        for (i = 0; i < rowA; i++) matA[i] = (int*) malloc(colA* sizeof(int));

    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            scanf("%d", &matA[i][j]);
            // printf("%d ", matA[i][j]);
        }
        scanf("%c", &newL);
        // printf("\n");
    }

    scanf("%c", &operation);

    if (!((operation == '+') | (operation == '-') | (operation == '*'))) {
        for (i = 0; i < rowA; i++) free(matA[i]); 
        free(matA);
        fprintf(stderr, "Error: Chybny vstup!\n"); return 100;
    }

    scanf("%c",&newL);

    scanf("%d%d", &rowB, &colB);

    scanf("%c",&newL);

    int** matB = (int**) malloc(rowB* sizeof(int));
        for (i = 0; i < rowB; i++) matB[i] = (int*) malloc(colB* sizeof(int));

    for (i = 0; i < rowB; i++) {
        for (j = 0; j < colB; j++) {
            scanf("%d", &matB[i][j]);
            // printf("%d ", matB[i][j]);
        }
        scanf("%c",&newL);
        // printf("\n");
    }

    printf("\nMatA: %d %d\n", rowA, colA);

    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }

    printf("\nOperation: '%c'\n\nMatB: %d %d\n", operation, rowB, colB);

    for (i = 0; i < rowB; i++) {
        for (j = 0; j < colB; j++) {
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }

    printf("\nMatC: ");

    if ((operation == '+') | (operation == '-')) {
        if ((rowA == rowB) & (colA == colB)) {
            int rowC = rowA;
            int colC = colA;

            int** matC = (int**) malloc(rowC* sizeof(int));
                for (i = 0; i < rowC; i++) matC[i] = (int*) malloc(colC* sizeof(int));

        printf("%d %d\n", rowC, colC);

        for (i = 0; i < rowC; i++)   {
            for (j = 0; j < colC; j++)  {
                if (operation == '+') matC[i][j] = matA[i][j] + matB[i][j];
                else matC[i][j] = matA[i][j] - matB[i][j];

                if (j == (colC - 1)) printf("%d", matC[i][j]);
                else printf("%d ", matC[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i < rowA; i++) free(matA[i]);
        for (i = 0; i < rowB; i++) free(matB[i]);
        for (i = 0; i < rowC; i++) free(matC[i]);

        free(matA); free(matB); free(matC);

        return 0;
        }
        else {  for (i = 0; i < rowA; i++) free(matA[i]);
                for (i = 0; i < rowB; i++) free(matB[i]);
                free(matA); free(matB); 
                fprintf(stderr, "Error: Chybny vstup!\n"); return 100;}
    }
    else if (operation == '*') {
        if (colA == rowB) {
            int rowC = rowA;
            int colC = colB;

            printf("%d %d\n", rowC, colC);

            int** matC = (int**) malloc(rowC* sizeof(int));
                for (i = 0; i < rowC; i++) matC[i] = (int*) malloc(colC* sizeof(int));

        for (int i = 0; i < rowC; i++) {
            for (int j = 0; j < colC; j++) {
                add = 0;
                for (k = 0; k < rowB; k++) add += matA[i][k] * matB[k][j];

                matC[i][j] = add;
                if (j == (colC - 1)) printf("%d", matC[i][j]);
                else printf("%d ", matC[i][j]);
                }
            printf("\n");
            }

        for (i = 0; i < rowA; i++) free(matA[i]);
        for (i = 0; i < rowB; i++) free(matB[i]);
        for (i = 0; i < rowC; i++) free(matC[i]);           


        free(matA); free(matB); free(matC);

        return 0;
        }
        else {  for (i = 0; i < rowA; i++) free(matA[i]);
                for (i = 0; i < rowB; i++) free(matB[i]);
                free(matA); free(matB);
                fprintf(stderr, "Error: Chybny vstup!\n"); return 100;}
    }
    else {  for (i = 0; i < rowA; i++) free(matA[i]);
            for (i = 0; i < rowB; i++) free(matB[i]);
            free(matA); free(matB); 
            fprintf(stderr, "Error: Chybny vstup!\n"); return 100;}

    for (i = 0; i < rowA; i++) free(matA[i]);
    for (i = 0; i < rowB; i++) free(matB[i]);

    free(matA); free(matB);

    return 0;

}