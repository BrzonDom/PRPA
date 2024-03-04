
#include <stdio.h>
#include <string.h>


void fun_04_list (const char* list) {

    int len, chLen, next, seq, space, i, j, k, l;
    seq = next = 0;

    chLen = (strlen(list));
    
    char letter[chLen];
    int times[chLen];

    for (i = 1; i < chLen; i++) {
        if ('A' <= list[i] & list[i] <= 'Z') {
            if (list[i] == list[i - 1]) {
                seq++;
                if (i == (chLen - 1)) {
                    letter[next] = list[i - 1];
                    times[next] = seq;
                    seq = 1; next++;
                }
            }
            else {
                    letter[next] = list[i - 1];
                    times[next] = seq;
                    seq = 1;    next++;
            }
        }
    }
    char EditList[next];

            for (i = 0; i < next; i++) {
            if (times[i] == 1)
                printf("%c",letter[i]);
            else if (times[i] == 2) {
                printf("%c",letter[i]);
                printf("%c",letter[i]);}
            else if (times[i] > 2 & times[i] < 256){
                printf("%c",letter[i]);
                printf("%d",times[i]);}
        }
}

int main(int argc, char const *argv[])
{
    int len, chLen, next, space, i, j, k, l;

    const char* pub00 = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
    const char* pub01 = "BWWBBBWWWWWWWBBBBBBBWWWBBBWWWWBBBWWWWWWBBBBBBBBBWWWWWWBBBBBB";
    const char* pub02 = "ABC";
    const char* pub03 = "AABTTT";
    const char* pub04 = "ABBbdfbYYYY";

    // chLen = sizeof(pub00);
    // chLen = (strlen(pub02));

    // printf("%d",chLen);

    // char letter[sizeof(pub00)];
    // int time[sizeof(pub00)];


    fun_04_list(pub01);

     
    return 0;
}