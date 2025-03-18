#include<stdio.h>
#include<time.h>

int a[20], n;

void merge_sort(int[], int, int);
void simple_sort(int[], int, int, int);

int main() {
    int i;
    clock_t start, end;
    double time_taken;
    
    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input array elements
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Measure time for merge sort
    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();
    
    // Calculate time taken for sorting
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Output sorted array
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Output time taken for merge sort
    printf("Time taken by merge sort: %f seconds\n", time_taken);
    return 0;
}

// Merge Sort function that divides the array
void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively split the array into two halves
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        
        // Merge the two sorted halves
        simple_sort(a, low, mid, high);
    }
}

// Simple sort (Merge function)
void simple_sort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[high + 1];  // Temporary array for merging

    // Merge the two halves into the temporary array c[]
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    // If any elements are left in the left half, add them
    while (i <= mid) {
        c[k++] = a[i++];
    }

    // If any elements are left in the right half, add them
    while (j <= high) {
        c[k++] = a[j++];
    }

    // Copy the sorted elements back to the original array
    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
