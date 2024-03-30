
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int let, chLen, var, spaces, i, j, k, l, m, n, o;
    spaces = chLen = i = j = k = l = m = n = o = 0;
    char inputData;
    char chNum [3][2];
    int koef[3] = {0, 0, 0};
    int koefA = 0;
    int koefB = 0;

    char testArr[] = "5"; int pocet = 0; int listCount = 1;
 

    // while (scanf("%c", &inputData) != EOF) {
    while (pocet < listCount) {
        inputData = testArr[pocet]; pocet++;

        if (inputData == '\n') break;
        else if (!('0' <= inputData & inputData <= '9') & (inputData != ' ')) {
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
        else {
            // printf("else");
            if (inputData == ' ') {
                m++; n = 0;
                spaces++;
                chLen++;
                // printf("-if-");
            }
            else{
                chNum[m][n] = inputData;
                n++; chLen++;
                koef[m]++;

                // printf("koef");
            }

        }

    }
    n=0; m=0;
    for (i = 0; i < 3; i++) {
        while (n < koef[m]) {
        printf("%c", chNum[m][n]);
        n++;
        }
        printf(" "); m++; n=0;
    }
    printf("\n");

        printf("%d\n", koef[0]);
        printf("%d\n", koef[1]);
        printf("%d\n", koef[2]);


        int widthDig, width = 0, heightDig, height = 0, sideDig, side = 0;
        widthDig = koef[0]; heightDig = koef[1]; sideDig = koef[2];


        // char* widthDig_1 = &chNum[0][0];
        // char* widthDig_2 = &chNum[0][1];


        printf("Char width: %c%c\n", chNum[0][0], chNum[0][1]);
        printf("Char height: %c%c\n", chNum[1][0], chNum[1][1]);
        printf("Char side: %c%c\n", chNum[2][0], chNum[2][1]);

        // printf("2. %c\n", chNum[0][1]);

            if (widthDig == 2) width = (10 * (chNum[0][0] - '0')) + (chNum[0][1] - '0');
            else if (widthDig == 1) width = (chNum[0][0] - '0');
            else {fprintf(stderr,"Error: Vstup mimo interval!\n"); return 101;}

        printf("Width: %d\n", width);
        // printf("1. %d\n", atoi(*widthDig_2));
        // printf("2. %d\n", atoi(*widthDig_1));

                if ((69 < width) | (2 > width)) {
                    fprintf(stderr,"Error: Vstup mimo interval!\n"); return 101;
                }

                if (width % 2 == 0) {fprintf(stderr,"Error: Sirka neni liche cislo!\n"); return 102;}

        if (spaces > 0) {
            // heightDig = spaces[1] - (spaces[0] + 1);
                if (heightDig == 2) height = (10 * (chNum[1][0] - '0')) + (chNum[1][1] - '0');
                else if (heightDig == 1) height = (chNum[1][0] - '0');
                else {fprintf(stderr,"Error: Vstup mimo interval!\n"); return 101;}
                printf("Height: %d\n", height);

                    if ((69 < height) | (2 > height)) {
                        fprintf(stderr,"Error: Vstup mimo interval!\n"); return 101;
                    }

        }
        if (spaces > 1) {
            // sideDig = chLen - (spaces[1] + 1);
                if (sideDig == 2) side = (10 * (chNum[2][0] - '0')) + (chNum[2][1] - '0');
                else if (sideDig == 1) side = (chNum[2][0] - '0');
                else {fprintf(stderr,"Error: Vstup mimo interval!\n"); return 101;}
                printf("Side: %d\n", side);

                    if ((69 < side) | (2 > side)) {
                        fprintf(stderr,"Error: Vstup mimo interval!\n"); return 101;
                    }

            if (side >= height) {fprintf(stderr,"Error: Neplatna velikost plotu!\n"); return 103;}
        }

        int top, out, in, BodyFill, SideFill, SideStart, fill;
        top = out = (width - 3) / 2;    /* Roof: top = space from left ; out = space from left adjustable */
        in = 1;                         /* Roof: in = space in between adjustable */
        BodyFill = 1;                   /* Fill: BodyFill = alternating filling */
        SideStart = height - side;      /* Side: SideStart = start of the side */
        SideFill = (side % 2);          /* Side: SideFill = changing filling */

    switch (spaces) {
        case 0:

            for (i = 0; i < width; i++) {
                if (i == 0 | i == (width - 1)) {
                    for (j = 0; j < width; j++) {
                        printf("#");
                    }
                    printf("\n");
                }
                else {
                    printf("#");
                    for (j = 0; j < (width - 2); j++) {
                        printf(" ");
                    }
                    printf("#\n");
                }
            } break;

        case 1:

            for ( j = 0; j < (width - 1) / 2; j++)	{
                printf(" ");
            }
            printf("#\n");

            for ( i = 0; i < (top); i++)	{
                for ( j = 0; j < (out); j++)		{
                    printf(" ");
                }	out--;
                printf("#");
                for (l = 0; l < (in); l++)	{
                    printf(" ");
                }	in += 2;
                printf("#\n");
            }

            for (i = 0; i < height; i++) {
                if (height == width) {
                    if (i == 0 || i == (height - 1)) {
                        for (j = 0; j < width; j++) {
                            printf("#");
                        }
                        printf("\n");
                    } else {
                        printf("#");
                        for (j = 0; j < (width - 2); j++) {
                            if ((BodyFill % 2) == 0) printf("o");
                            else printf("*");
                            BodyFill++;
                        }
                        printf("#\n");
                    }
                }
                else {
                    if (i == 0 || i == (height - 1)) {
                        for (j = 0; j < width; j++) {
                            printf("#");
                        }
                        printf("\n");
                    } else {
                        printf("#");
                        for (j = 0; j < (width - 2); j++) {
                            printf(" ");
                        }
                        printf("#\n");
                    }
                }
            } break;

        case 2:
            /* Roof: Top */
            for ( j = 0; j < (width - 1) / 2; j++)	{
                printf(" ");
            }
            printf("#\n");

            /* Roof: Body */
            for ( i = 0; i < top; i++)	{
                for ( j = 0; j < out; j++)		{
                    printf(" ");
                }	out--;
                printf("#");
                for (l = 0; l < in; l++)	{
                    printf(" ");
                }	in += 2;
                printf("#\n");
            }

            /* Body */
            for (i = 0; i < height; i++) {

                /* Body: square with fill */
                if (height == width) {
                    /* Body: first line */
                    if (i == 0) {
                        for (j = 0; j < width; j++) {
                            printf("#");
                        }
                        printf("\n");
                    }

                    /* Body: last line */
                    else if (i == (height - 1)) {
                        for (j = 0; j < width; j++) {
                            printf("#");
                        }
                        for (j = 0; j < side; j++) {
                            if (SideFill % 2 == 0) {
                                printf("-");
                            } else printf("|");
                            SideFill++;
                        }
                        SideFill = (side % 2);
                        printf("\n");
                    }
                    /* Body: middle lines */
                    else {
                        printf("#");
                        for (j = 0; j < (width - 2); j++) {
                            if ((BodyFill % 2) == 0) printf("o");
                            else printf("*");
                            BodyFill++;
                        }
                        printf("#");

                        /* Side: Start of the side */
                        if (i == SideStart) {
                            for (j = 0; j < side; j++) {
                                if (SideFill % 2 == 0) {
                                    printf("-");
                                } else printf("|");
                                SideFill++;
                            }
                            SideFill = (side % 2);
                            printf("\n");
                        }

                        /* Side: Middle lines */
                        else if (i > SideStart) {
                            for (j = 0; j < side; j++) {
                                if (SideFill % 2 == 0) {
                                    printf(" ");
                                } else printf("|");
                                SideFill++;
                            }
                            SideFill = (side % 2);
                            printf("\n");
                        }

                        /* Body: Rows without side */
                        else printf("\n");
                    }
                }
                /* Body: rectangle */
                else {

                    /* Body: first line*/
                    if (i == 0) {
                        for (j = 0; j < width; j++) {
                            printf("#");
                        }
                        printf("\n");
                    }
                    /* Body: last lines */
                    else if (i == (height - 1)) {
                        for (j = 0; j < width; j++) {
                            printf("#");
                        }
                        for (j = 0; j < side; j++) {
                            if (SideFill % 2 == 0) {
                                printf("-");
                            } else printf("|");
                            SideFill++;
                        }
                        SideFill = (side % 2);
                        printf("\n");
                    }

                    /* Body: middle lines */
                    else {
                        printf("#");
                        for (j = 0; j < (width - 2); j++) {
                            printf(" ");
                        }
                        printf("#");

                        /* Side: Start of the side */
                        if (i == SideStart) {
                            for (j = 0; j < side; j++) {
                                if (SideFill % 2 == 0) {
                                    printf("-");
                                } else printf("|");
                                SideFill++;
                            }
                            SideFill = (side % 2);
                            printf("\n");
                        }

                        /* Side: Middle lines */
                        else if (i > SideStart) {
                            for (j = 0; j < side; j++) {
                                if (SideFill % 2 == 0) {
                                    printf(" ");
                                } else printf("|");
                                SideFill++;
                            }
                            SideFill = (side % 2);
                            printf("\n");
                        }

                        /* Body: Rows without side */
                        else printf("\n");
                    }
                }
            }
    }



    return 0;
}
