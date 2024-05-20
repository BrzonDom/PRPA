#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int objCntFun(char*, int);

int objCntFun(char* data, int dataCnt) {

    int i, chCnt, objCnt;
        chCnt = objCnt = 0;

    for (i = 0; i < dataCnt; i++) {
        // if((data[i] == ' ')) { 
        if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':')) {
                
                // Char object count
            if (chCnt != 0) {               
                objCnt++;
                    chCnt = 0;
            }    
        }
        else 
            chCnt++;
    }

    return objCnt;
}

int* digitFun(char* data, int dataCnt) {

    int i, chCnt, objCnt;
        chCnt = objCnt = 0;


    int* digits = (int*) malloc(sizeof(int));

    for (i = 0; i < dataCnt; i++) {
        if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

            if (chCnt != 0) {

                if (objCnt != 0) digits = realloc(digits, (objCnt+1) * sizeof(int));

                digits[objCnt] = chCnt;
                    // Char object count            
                    objCnt++;
                chCnt = 0;
            }
        }
        else chCnt++;
    }

    //         // End of the digit list
    // digits = realloc(digits, (objCnt+1) * sizeof(int*));
    //     digits[objCnt] = 0;

    return digits;

}

void objListPrint(char* data, int dataCnt) {
    int i, j, l, chCnt, objCnt;
    
    printf("Print List:");
    chCnt = objCnt = 0;

    for (i = 0; i < dataCnt; i++) {
        if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

            if (chCnt != 0) {
                for (j = 0; j < (10 - chCnt); j++) printf(" ");

                printf("%d", chCnt);
                objCnt++;
                    chCnt = 0;
            }
        }
        else if (chCnt != 0) {

                printf("%c", data[i]);
            chCnt++;
        }
        else {
                printf("\n\t\t%2d. ", (objCnt+1));
                printf("%c", data[i]);
            chCnt++;
        }
    }

    printf("\n\nPrint LowList:");
    chCnt = objCnt = 0;
    
    for (i = 0; i < dataCnt; i++) {
        if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

            if (chCnt != 0) {
                for (j = 0; j < (10 - chCnt); j++) printf(" ");

                printf("%d", chCnt);
                objCnt++;
                    chCnt = 0;
            }
        }
        else if (chCnt != 0) {
            if (('A' <= data[i]) && (data[i] <= 'Z')) printf("%c", (data[i] + 32));
            else printf("%c", data[i]);
            chCnt++;
        }
        else {
                printf("\n\t\t%2d. ", (objCnt+1));
            if (('A' <= data[i]) && (data[i] <= 'Z')) printf("%c", (data[i] + 32));
            else printf("%c", data[i]);
            chCnt++;
        }
    }

}

char** objListFun(char* data, int dataCnt) {

    int i, j, l, chCnt, objCnt;

        // printf("\n\nPrint chList:");
    chCnt = objCnt = 0;

    char** chList = (char**) malloc(sizeof(char*));
    // char** chLowList = (char**) malloc(sizeof(char*));

    for (i = 0; i < dataCnt; i++) {
        if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

            if (chCnt != 0) {
                // for (j = 0; j < (10 - chCnt); j++) printf(" ");

                // printf("%d", chCnt);
                objCnt++;
                    chCnt = 0;
            }
        }
        else if (chCnt != 0) {

            chList[objCnt] = realloc(chList[objCnt], (chCnt+1) * sizeof(char));
                // chLowList[objCnt] = realloc(chLowList[objCnt], (chCnt+1) * sizeof(char));

            chList[objCnt][chCnt] = data[i];
                // if (('A' <= data[i]) && (data[i] <= 'Z')) chLowList[objCnt][chCnt] = (data[i] + 32);
                // else chLowList[objCnt][chCnt] = data[i];

                // printf("%c", chList[objCnt][chCnt]);
            chCnt++;
        }
        else {
            if (objCnt != 0) chList = realloc(chList, (objCnt+1) * sizeof(char*));
            // if (objCnt != 0) chLowList = realloc(chLowList, (objCnt+1) * sizeof(char*));

            chList[objCnt] = (char*) malloc(sizeof(char));
            // chLowList[objCnt] = (char*) malloc(sizeof(char));

                // printf("\n\t\t%2d. ", (objCnt+1));

            chList[objCnt][chCnt] = data[i];
                // if (('A' <= data[i]) && (data[i] <= 'Z')) chLowList[objCnt][chCnt] = (data[i] + 32);
                // else chLowList[objCnt][chCnt] = data[i];

                // printf("%c", chList[objCnt][chCnt]);
            chCnt++;
        }
    }

    return chList;
}

char** objLowListFun(char* data, int dataCnt) {

    int i, j, l, chCnt, objCnt;

        // printf("\n\nPrint chList:");
    chCnt = objCnt = 0;

    // char** chList = (char**) malloc(sizeof(char*));
    char** chLowList = (char**) malloc(sizeof(char*));

    for (i = 0; i < dataCnt; i++) {
        if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

            if (chCnt != 0) {
                // for (j = 0; j < (10 - chCnt); j++) printf(" ");

                // printf("%d", chCnt);
                objCnt++;
                    chCnt = 0;
            }
        }
        else if (chCnt != 0) {

            // chList[objCnt] = realloc(chList[objCnt], (chCnt+1) * sizeof(char));
                chLowList[objCnt] = realloc(chLowList[objCnt], (chCnt+1) * sizeof(char));

            // chList[objCnt][chCnt] = data[i];
                if (('A' <= data[i]) && (data[i] <= 'Z')) chLowList[objCnt][chCnt] = (data[i] + 32);
                else chLowList[objCnt][chCnt] = data[i];

                // printf("%c", chList[objCnt][chCnt]);
            chCnt++;
        }
        else {
            // if (objCnt != 0) chList = realloc(chList, (objCnt+1) * sizeof(char*));
            if (objCnt != 0) chLowList = realloc(chLowList, (objCnt+1) * sizeof(char*));

            // chList[objCnt] = (char*) malloc(sizeof(char));
            chLowList[objCnt] = (char*) malloc(sizeof(char));

                // printf("\n\t\t%2d. ", (objCnt+1));

            // chList[objCnt][chCnt] = data[i];
                if (('A' <= data[i]) && (data[i] <= 'Z')) chLowList[objCnt][chCnt] = (data[i] + 32);
                else chLowList[objCnt][chCnt] = data[i];

                // printf("%c", chList[objCnt][chCnt]);
            chCnt++;
        }
    }

    return chLowList;
}



int main() {

    int i, j, l, r, c, m, o, add, row, col, dataCnt;
    dataCnt = 0;
    char chScn;

    int objCnt, chCnt;


    // char StrInLoc[] = "07pub_c06.in";
    // char InLoc[sizeof(StrInLoc) + 7] = "data\\";

    // strcat(InLoc, StrInLoc);
    // printf("Source: %s\n\n", InLoc);

    char InLoc[] = "0_pub00.in";

        // data entery open
    FILE *In;	In = fopen(InLoc, "r");

        if (NULL == In) {
            printf("file can't be opened \n");
            exit(1);	
        }

        // data collection list
    char* data = (char*) malloc(sizeof(char));

    while(fscanf(In, "%c", &chScn) != EOF) {
        data[dataCnt] = chScn;

        dataCnt++;
        data = realloc(data, (dataCnt+1) * sizeof(char));
    }
        // data entery close
    fclose(In);

    printf("Data:\n\t");

        // Print Data
    for (i = 0; i < dataCnt; i++) {
        printf("%c", data[i]);
    }
    printf("\n");

        printf("\nData Scan Over\n");
            printf("\t\tData Count: %d\n\n", dataCnt);

    
        // int objCntFun(char* data, int dataCnt)
    int objN = objCntFun(data, dataCnt);

        printf("\nObjCnt Over\n");
            printf("\t\tObjCount: %d\n\n", objN);


        // int* digitFun(char* data, int dataCnt)
    int* digList = digitFun(data, dataCnt);

        // Print Digits
    for (i = 0; i < objN; i++)
        printf("%d, ", digList[i]);
    printf("\n");

        printf("\nDigit Scan Over\n");

    printf("\n");

    //     // void objListPrint(char* data, int dataCnt)
    // objListPrint(data, dataCnt);

/*     // printf("Print List:");
    // chCnt = objCnt = 0;

    // for (i = 0; i < dataCnt; i++) {
    //     if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

    //         if (chCnt != 0) {
    //             for (j = 0; j < (10 - chCnt); j++) printf(" ");

    //             printf("%d", chCnt);
    //             objCnt++;
    //                 chCnt = 0;
    //         }
    //     }
    //     else if (chCnt != 0) {

    //             printf("%c", data[i]);
    //         chCnt++;
    //     }
    //     else {
    //             printf("\n\t\t%2d. ", (objCnt+1));
    //             printf("%c", data[i]);
    //         chCnt++;
    //     }
    // }

    // printf("\n\nPrint LowList:");
    // chCnt = objCnt = 0;
    
    // for (i = 0; i < dataCnt; i++) {
    //     if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

    //         if (chCnt != 0) {
    //             for (j = 0; j < (10 - chCnt); j++) printf(" ");

    //             printf("%d", chCnt);
    //             objCnt++;
    //                 chCnt = 0;
    //         }
    //     }
    //     else if (chCnt != 0) {
    //         if (('A' <= data[i]) && (data[i] <= 'Z')) printf("%c", (data[i] + 32));
    //         else printf("%c", data[i]);
    //         chCnt++;
    //     }
    //     else {
    //             printf("\n\t\t%2d. ", (objCnt+1));
    //         if (('A' <= data[i]) && (data[i] <= 'Z')) printf("%c", (data[i] + 32));
    //         else printf("%c", data[i]);
    //         chCnt++;
    //     }
    // } */

    // printf("\n\nPrint chList:");
    chCnt = objCnt = 0;

/*     // char** chList = (char**) malloc(sizeof(char*));
    // char** chLowList = (char**) malloc(sizeof(char*));

    // for (i = 0; i < dataCnt; i++) {
    //     if((data[i] == ' ') || (data[i] == ',') || (data[i] == ';') || (data[i] == '.') || (data[i] == ':') || (data[i] == '?') || (data[i] == '!')) {

    //         if (chCnt != 0) {
    //             for (j = 0; j < (10 - chCnt); j++) printf(" ");

    //             printf("%d", digList[objCnt]);
    //             objCnt++;
    //                 chCnt = 0;
    //         }
    //     }
    //     else if (chCnt != 0) {

    //         chList[objCnt] = realloc(chList[objCnt], (chCnt+1) * sizeof(char));
    //             chLowList[objCnt] = realloc(chLowList[objCnt], (chCnt+1) * sizeof(char));

    //         chList[objCnt][chCnt] = data[i];
    //             if (('A' <= data[i]) && (data[i] <= 'Z')) chLowList[objCnt][chCnt] = (data[i] + 32);
    //             else chLowList[objCnt][chCnt] = data[i];

    //             printf("%c", chList[objCnt][chCnt]);
    //         chCnt++;
    //     }
    //     else {
    //         if (objCnt != 0) chList = realloc(chList, (objCnt+1) * sizeof(char*));
    //         if (objCnt != 0) chLowList = realloc(chLowList, (objCnt+1) * sizeof(char*));

    //         chList[objCnt] = (char*) malloc(sizeof(char));
    //         chLowList[objCnt] = (char*) malloc(sizeof(char));

    //             printf("\n\t\t%2d. ", (objCnt+1));

    //         chList[objCnt][chCnt] = data[i];
    //             if (('A' <= data[i]) && (data[i] <= 'Z')) chLowList[objCnt][chCnt] = (data[i] + 32);
    //             else chLowList[objCnt][chCnt] = data[i];

    //             printf("%c", chList[objCnt][chCnt]);
    //         chCnt++;
    //     }
    // } */

/*     // printf("\n\nPrint chLowList:");

    // for (i = 0; i < objN; i++) {
    //     printf("\n\t\t%2d. ", (i+1));
    //     for (j = 0; j < digList[i]; j++) {
    //         printf("%c", chLowList[i][j]);
    //     }
    //     for (j = 0; j < (10 - digList[i]); j++)
    //         printf(" ");
    //     printf("%d", digList[i]);
    // } */
    
        // char** objListFun(char* data, int dataCnt)
    char** chList = objListFun(data, dataCnt);    

        printf("\n\nPrint objList Fun:");

    for (i = 0; i < objN; i++) {
        printf("\n\t\t%2d. ", (i+1)); 
        for (j = 0; j < digList[i]; j++) {
            printf("%c", chList[i][j]);
        }
        for (j = 0; j < (10 - digList[i]); j++)
            printf(" ");
        printf("%d", digList[i]);
    }

    char** chLowList = objLowListFun(data, dataCnt);   

        printf("\n\nPrint objLowList Fun:");

    for (i = 0; i < objN; i++) {
        printf("\n\t\t%2d. ", (i+1)); 
        for (j = 0; j < digList[i]; j++) {
            printf("%c", chLowList[i][j]);
        }
        for (j = 0; j < (10 - digList[i]); j++)
            printf(" ");
        printf("%d", digList[i]);
    }


    for (i = 0; i < objN; i++)
        free(chList[i]);
    free(chList);

    for (i = 0; i < objN; i++)
        free(chLowList[i]);
    free(chLowList);
    
    free(digList);
    free(data);

    return 0;           
}