#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int direction;
} Element;

void printPermutation(Element perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

int largestMobile(Element perm[], int n) {
    int largest = -1, index = -1;

    for (int i = 0; i < n; i++) {
        int neighborIndex = i + perm[i].direction;
        if (neighborIndex >= 0 && neighborIndex < n && perm[i].value > perm[neighborIndex].value) {
            if (perm[i].value > largest) {
                largest = perm[i].value;
                index = i;
            }
        }
    }

    return index;
}

void johnsonTrotter(int n) {
    Element perm[n];
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].direction = LEFT;
    }

    printPermutation(perm, n);

    int mobileIndex;
    while ((mobileIndex = largestMobile(perm, n)) != -1) {
        int swapIndex = mobileIndex + perm[mobileIndex].direction;

        Element temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        for (int i = 0; i < n; i++) {
            if (perm[i].value > perm[swapIndex].value) {
                perm[i].direction *= -1;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements for permutations: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
