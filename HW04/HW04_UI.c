
#include <stdio.h>

int main(int argc, char const *argv[])
{

    int pocet, nah, komp;
        pocet = nah = komp = 0;
    double procento;
    char let, prev;

    while (scanf("%c", &let) != EOF) {
    // while (pocet < listCount) {
        

        if (pocet == 0) {
            pocet++;
            }
        else if (let == prev) {   
            pocet++;
            }
        else if (let != prev) {
            if (pocet == 1) {
                printf("%c", prev);
                komp++;
            }
            else if (pocet == 2) {
                printf("%c", prev);
                printf("%c", prev);
                komp += 2;
                }
            else if (pocet > 2 & pocet < 256){
                printf("%c%d", prev, pocet);
                if (pocet < 10) komp += 2;
                else if (pocet < 100) komp += 3;
                else komp += 4;
            }
            else if (pocet > 255) {
                while (pocet > 255) {
                    printf("%c255", prev);
                    pocet -= 255;
                    komp += 4;
                }
                if (pocet == 1) {
                    printf("%c", prev);
                    komp ++;
                }
                else if (pocet == 2) {
                    printf("%c", prev);
                    printf("%c", prev);
                    komp += 2;
                    }
                else if (pocet > 2 & pocet < 256){
                    printf("%c%d", prev, pocet);
                    if (pocet < 10) komp += 2;
                    else if (pocet < 100) komp += 3;
                    else komp += 4;
                    }
                
            }

            // if (pocet > 1) {
            //     printf("%dx %d\n", pocet, prev);
            //     pocet = 1;
            // }
            pocet = 1;
        }
        prev = let;
        nah++;

        if ('A' > let | let > 'Z')   {
            fprintf(stderr,"Error: Vstup je mimo interval!\n");
            return 100;     
        }
    }   

    if (pocet == 1) {
        printf("%c", prev);
        komp++; }
    else if (pocet == 2) {
        printf("%c", prev);
        printf("%c", prev);
        komp += 2;
        }
    else if (pocet > 2 & pocet < 256){
        printf("%c%d", prev, pocet);
        if (pocet < 10) komp += 2;
        else if (pocet < 100) komp += 3;
        else komp += 4;
        }
    else if (pocet > 256) {
        while (pocet > 256) {
            printf("%c255", prev);
            pocet -= 255;
            komp += 4;
        }
        if (pocet == 1) {
            printf("%c", prev);
            komp++;
        }
        else if (pocet == 2) {
            printf("%c", prev);
            printf("%c", prev);
            komp += 2;
            }
        else if (pocet > 2 & pocet < 256){
            printf("%c%d", prev, pocet);
            if (pocet < 10) komp += 2;
            else if (pocet < 100) komp += 3;
            else komp += 4;
            }
        
    }



    procento = (double)(komp) / nah;
    fprintf(stderr,"\nPocet vstupnich symbolu: %d\n", nah);
    fprintf(stderr,"Pocet zakodovanych symbolu: %d\n", komp);
    fprintf(stderr,"Kompresni pomer: %.2f\n", procento);


    return 0;

}