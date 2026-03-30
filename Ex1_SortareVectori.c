#include <stdio.h>
#include <stdlib.h>

// --- FUNCTII DE AFISARE ---
void printInt(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void printDouble(double arr[], int n) {
    for (int i = 0; i < n; i++) printf("%.4f ", arr[i]);
    printf("\n");
}

void printChar(char arr[], int n) {
    for (int i = 0; i < n; i++) printf("'%c' ", arr[i]);
    printf("\n");
}

// --- 1. BUBBLE SORT (Complexitate O(n^2)) ---
// "Fierbe" elementele mari spre finalul vectorului prin comparatii adiacente.
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// --- 2. SELECTION SORT (Complexitate O(n^2)) ---
// Cauta minimul in partea nesortata si il schimba cu elementul de pe pozitia curenta.
void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        double temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// --- 3. INSERTION SORT (Complexitate O(n^2)) ---
// Ca la sortarea cartilor de joc: insereaza elementul curent la locul lui printre cele deja sortate.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// --- 4. QUICK SORT (Complexitate medie O(n log n)) ---
// Alege un PIVOT si partitioneaza vectorul (mici la stanga, mari la dreapta).
void quickSort(char arr[], int low, int high) {
    if (low < high) {
        char pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                char temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        char temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// --- 5. MERGE SORT (Complexitate O(n log n)) ---
// Imparte vectorul in jumatati pana ajunge la elemente individuale, apoi le combina sortat.
void merge(double arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    double *L = (double*)malloc(n1 * sizeof(double));
    double *R = (double*)malloc(n2 * sizeof(double));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(double arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int vInt[] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
    double vDouble[] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
    char vChar[] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'};
    int n = 10;

    printf("1. Bubble Sort (Int):    "); bubbleSort(vInt, n); printInt(vInt, n);
    printf("2. Selection Sort (Dbl): "); selectionSort(vDouble, n); printDouble(vDouble, n);
    printf("3. Quick Sort (Char):    "); quickSort(vChar, 0, n - 1); printChar(vChar, n);
    
    // Reset pentru Merge/Insertion demo
    double vDouble2[] = {90.675, -60.98, 86.10, 4.99, 30.26, -29.17, -86.58, -51.15, -76.40, 32.16};
    printf("4. Merge Sort (Dbl):     "); mergeSort(vDouble2, 0, n - 1); printDouble(vDouble2, n);

    return 0;
}
