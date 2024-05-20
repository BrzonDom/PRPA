#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    int numIn, add, max, min, count, calLen, histo, i;
    count = 0;
    calLen = 1;
    double med;

    int* listIn; listIn = (int*) calloc(calLen, sizeof(int));

    scanf("%d", &histo);

    while (scanf("%d", &numIn) != EOF) {
        if (count == 0) {
            min = max = add = numIn;
            listIn[count] = numIn;
            count++;
        }
        else {
            count++;
            listIn = realloc(listIn, count * sizeof(int));
            listIn[count - 1] = numIn;

            add += numIn;
            if (numIn > max) max = numIn;

            if (numIn < min) min = numIn;
        }
    }
    for (i = 0; i < count; i++) {
        printf("%d, ", listIn[i]);
    }

    // if (count % 2 == 1) med = (double) 
    
    return 0;

}
