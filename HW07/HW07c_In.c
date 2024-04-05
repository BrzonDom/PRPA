#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    
    int i, j, k, l, m, r, c, add;
    int row, col, numOp, numM, resRow, resCol, resM, inM, hasMul, nextMul;
    numM = numOp = 0;
    resRow = resCol = 1;
    char newL;

    /*    Input file name    */
    char StrInLoc[] = "pub_c06.in";
    char InLoc[sizeof(StrInLoc) + 7] = "data\\";
    strcat(InLoc, StrInLoc);
    printf("Source: %s\n\n", InLoc);

    /*    Open Read file function    */
    FILE *In;	In = fopen(InLoc, "r");

        if (NULL == In) {
        printf("File can't be opened \n");
        exit(1);	}


    /*    Dim Mat List    */
    int** dimMat = (int**) malloc((numM+1) * sizeof(int*));
        /*    Dim Mat (Row, Col)    */
        dimMat[numM] = (int*) malloc(2 * sizeof(int));

    /*    Dim 1.Mat    */
    fscanf(In, "%d%d", &dimMat[numM][0], &dimMat[numM][1]);
    printf("1.Mat\n  Row: %d   Col: %d\n\n", dimMat[numM][0], dimMat[numM][1]);

    /*    Input Mat List    */
    int*** Matrix = (int***) malloc((numM+1) * sizeof(int**));
        /*    Input Mat Row    */
        Matrix[numM] = (int**) malloc((dimMat[numM][0]) * sizeof(int*));
            /*    Input Mat Col    */
        for (col = 0; col < dimMat[numM][0]; col++)
            Matrix[numM][col] = (int*) malloc((dimMat[numM][1]) * sizeof(int*));

    /*    Operations List    */
    char* Operation = (char*) malloc(5 * sizeof(char));
    int OpPosList[5];
    
    inM = dimMat[numM][0] * dimMat[numM][1];
    // printf("Num. of items in 1.Mat: %d\n\n", inM);
        
    /*    Data 1.Mat    */
    for (row = 0; row < dimMat[numM][0]; row++) {
        for (col = 0; col < dimMat[numM][1]; col++) {
            fscanf(In, "%d", &Matrix[numM][row][col]);
            printf("%03d ", Matrix[numM][row][col]);
        }
        printf("\n");
    }
    printf("\n");


    /*    While cycle    */
    while(fscanf(In, "%c", &newL) != EOF) {

        /*    Get operation    */
        fscanf(In, "%c", &Operation[numM]);
        printf("%d.Operation: %c\n\n", (numM+1), Operation[numM]);
            /*    Num of multiplications    */
        if (Operation[numM] == '*') {
            OpPosList[numOp] = numM + 1;
            numOp++;
        }
        
        numM++;

        /*    Memory Dim Mat    */
        dimMat = realloc(dimMat, (numM+1) * sizeof(int*));
            dimMat[numM] = (int*) malloc(2 * sizeof(int));
        /*    Get Dim Mat    */
        fscanf(In, "%d%d", &dimMat[numM][0], &dimMat[numM][1]);
        printf("%d.Mat\n  Row: %d   Col: %d\n\n", (numM+1), dimMat[numM][0], dimMat[numM][1]);

        /*    Memory Dim Mat    */
        Matrix = realloc(Matrix, (numM+1) * sizeof(int**));
            Matrix[numM] = (int**) malloc((dimMat[numM][0]) * sizeof(int*));
            for (col = 0; col < dimMat[numM][0]; col++)
                Matrix[numM][col] = (int*) malloc((dimMat[numM][1]) * sizeof(int*));
        /*    Get Data Mat    */
        for (row = 0; row < dimMat[numM][0]; row++) {
            for (col = 0; col < dimMat[numM][1]; col++) {
                fscanf(In, "%d", &Matrix[numM][row][col]);
                printf("%03d ", Matrix[numM][row][col]);
            }
            printf("\n");
        }
        printf("\n");

    }

    /*    Close Read file function    */
    fclose(In);

    /*    Free Memory    */
    for (row = 0; row < numM+1; row++) {
        for (col = 0; col < dimMat[row][0]; col++) {
            free(Matrix[row][col]);
        }
        free(Matrix[row]);
    }
    free(Matrix);

    for (row = 0; row < numM+1; row++) {
        free(dimMat[row]);
    }
    free(dimMat);

    free(Operation);

    return 0;
}