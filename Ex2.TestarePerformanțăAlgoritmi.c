#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 20000 // Marit la 20k pentru a vedea diferente la Quick/Merge


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = (low - 1), temp;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- Main ---

int main() {
    int *original = malloc(N * sizeof(int));
    int *work = malloc(N * sizeof(int));
    double times[5];
    const char *names[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Merge Sort"};

    if (!original || !work) return 1;

    srand(time(NULL));
    for (int i = 0; i < N; i++) original[i] = rand() % 50000;

    printf("Testare performanta pentru N = %d\n", N);
    printf("--------------------------------------------\n");

    for (int alg = 0; alg < 5; alg++) {
        memcpy(work, original, N * sizeof(int));
        
        clock_t start = clock();
        switch(alg) {
            case 0: bubbleSort(work, N); break;
            case 1: selectionSort(work, N); break;
            case 2: insertionSort(work, N); break;
            case 3: quickSort(work, 0, N - 1); break;
            case 4: mergeSort(work, 0, N - 1); break;
        }
        clock_t end = clock();

        times[alg] = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%-15s: %f secunde\n", names[alg], times[alg]);
    }


    int best = 0;
    for (int i = 1; i < 5; i++) {
        if (times[i] < times[best]) best = i;
    }

    printf("--------------------------------------------\n");
    printf("Cel mai performant: %s\n", names[best]);

    free(original);
    free(work);
    return 0;
}
