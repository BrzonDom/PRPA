#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int a, b, c, i, j, k, l, m, size, disK, dig, dig_i;
    l = disK = dig = 0; 
    size = 4*5 + 5;

    // int koef[3];
    int para[4];
    int digPara[4];

    // scanf("%d%d%d", &koef[0], &koef[1], &koef[2]);

    // int koef[3] = {10, 20, 10};
    int koef[3] = {10, 0, -13};
    // int koef[3] = {3, 0, 2};
    // int koef[3] = {-10, 2, 30};
    // int koef[3] = {3, 3, 0};
    
    // koef[0] = 4;
    // koef[1] = -20;
    // koef[2] = 10;

    para[0] = koef[0];
    para[1] = koef[1];
    para[2] = koef[2];
    para[3] = koef[1] * koef[1] - 4 * koef[0] * koef[2];


    // for (i = 0; i < 4; i++) {
    //     printf("%d\n", para[i]);
    // }

    // for (i = 0; i < 4; i++) {
    //     if (para[i] == 0) digPara[i] = 1;
    //     else if (para[i] < 0) digPara[i] = (int)(log10(-para[i]) + 2);
    //     else digPara[i] = (int)(log10(para[i]) + 1);
    // }

    for (i = 0; i < 4; i++) {
        dig_i = para[i];
        if (dig_i >= 0)  {
            dig = 0;
            do   {  dig_i /= 10;
                    dig++; 
            } while (dig_i != 0);
            digPara[i] = dig;
        }
        else    {
            dig = 1;
            do   {  dig_i /= 10;
                    dig++; 
            } while (dig_i != 0);
            digPara[i] = dig;
        }
    }

    for (i = 0; i < 4; i++) {
        printf("%d\n", digPara[i]);
    }

    char koren_1[] = "Jeden koren";
    char koren_2[] = "Dva realne koreny";
    char koren_3[] = "Dva imaginarni koreny";
    char *koren[] = {koren_1, koren_2, koren_3};

    int digKoren[] = {strlen(koren_1), strlen(koren_2), strlen(koren_3)};

    // for (i = 0; i < 3; i++) {
    //     printf("%d\n", digKoren[i]);
    // }
    // int edge1, edge2;
    // edge1 = -999; edge2 = 999;
    // printf("%d\n",para[3]);

    if (para[3] < -999 | para[3] > 999) {
        printf("Diskriminant mimo povoleny interval!\n");
        return 0;
    }
    else if (para[3] == 0) disK = 0;
    else if (para[3] > 0) disK = 1;
    else if (para[3] < 0) disK = 2;

    char border_1[] = "+-----+-----+-----+-----+";
    char border_2[] = "+-----------------------+";

    for (i = 0; i < 5; i++) {
        if (i == 0 | i == 2) printf("%s\n", border_1);
        else if (i == 4) printf("%s\n", border_2);
        else if (i == 1) {
            for (j = 0; j < 4; j++) {
                printf("|");
    //                    if (j % 6 == 0) printf("|");
                for (m = 0; m < (4 - digPara[l]); m++) printf(" ");
                printf("%d",para[l]);
                printf(" ");
                l++;
            }
            printf("|\n");
        }
        else if (i == 3) {
            printf("|");
            for (j = 0; j < (size - (digKoren[disK] + 3)); j++) printf(" ");
            printf("%s |\n",koren[disK]);
        }
    }
    return 0;
}