#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

// Merge function for Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int *temp = (int *)malloc((r - l + 1) * sizeof(int));

    while (i <= m && j <= r)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (i = l, k = 0; i <= r; i++, k++) arr[i] = temp[k];

    free(temp);
}

// Parallel Merge Sort
void parallelMergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(arr, l, m);

            #pragma omp section
            parallelMergeSort(arr, m + 1, r);
        }

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    double start = omp_get_wtime();

    parallelMergeSort(arr, 0, n - 1);

    double end = omp_get_wtime();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTime taken by Parallel Merge Sort: %f seconds\n", end - start);

    free(arr);
    return 0;
}
