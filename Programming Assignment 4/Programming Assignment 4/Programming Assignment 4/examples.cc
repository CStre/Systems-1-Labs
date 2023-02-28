#include <stdio.h>
int count1 = 1;
int count2 = 3;
int count3 = 5;
int* ptr;

int main() {
    ptr = &count1;
    printf("%i - %i - %i\n", count1, count2, count3); // outputs 1 - 3 - 5

    for (int i = 0; i < 3; i++) {
        *ptr = *ptr + 1;    // could use  (*ptr)++;
        printf("%d - %d - %d\n", count1, count2, count3);
        ptr = ptr + 1;
    }
}