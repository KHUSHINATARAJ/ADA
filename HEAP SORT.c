#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && a[left] > a[largest]) {
        largest = left;
    }


    if (right < n && a[right] > a[largest]) {
        largest = right;
    }


    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;


        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }


    for (int i = n - 1; i >= 0; i--) {

        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;


        heapify(a, i, 0);
    }
}

int main() {
    int i, n, ch = 1;
    clock_t start, end;
    double time_taken;

    while (ch) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        int a[n];
        printf("\nEnter the elements to sort:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        start = clock();
        heapsort(a, n);
        end = clock();


        printf("\nThe sorted list of elements is:\n");
        for (i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nTime taken is %lf seconds\n", time_taken);

        printf("\nDo you wish to run again (0/1)? ");
        scanf("%d", &ch);
    }

    return 0;
}
