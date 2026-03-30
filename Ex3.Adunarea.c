#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Functia de sortare QuickSort - Eficienta medie O(n log n)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1), temp;
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

int main() {
    int n = 10000;
    int *v = malloc(n * sizeof(int));
    
    if (v == NULL) {
        printf("Eroare: Nu s-a putut aloca memorie.\n");
        return 1;
    }

    // Generam numere aleatorii
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20001 - 10000; // Valori intre -10000 si 10000
    }

    // Pasul 1: Sortarea (esențiala pentru metoda Two Pointers)
    quickSort(v, 0, n - 1);
    printf("Vectorul a fost generat si sortat cu succes.\n");

    int sumaCautata;
    char optiune;

    // Pasul 2: Bucla pentru cautari multiple
    do {
        printf("\nIntroduceti suma pe care o cautati: ");
        if (scanf("%d", &sumaCautata) != 1) break;

        int stanga = 0;
        int dreapta = n - 1;
        int gasit = 0;

        // Algoritmul Two Pointers - Eficienta O(n)
        while (stanga < dreapta) {
            int sumaCurenta = v[stanga] + v[dreapta];

            if (sumaCurenta == sumaCautata) {
                printf("Pereche gasita: %d + %d = %d\n", v[stanga], v[dreapta], sumaCautata);
                gasit = 1;
                break; // Ne oprim la prima pereche gasita
            } 
            else if (sumaCurenta < sumaCautata) {
                stanga++; // Suma e prea mica, mergem spre numere mai mari
            } 
            else {
                dreapta--; // Suma e prea mare, mergem spre numere mai mici
            }
        }

        if (!gasit) {
            printf("Nu s-a gasit nicio pereche care sa insumeze %d.\n", sumaCautata);
        }

        printf("Mai cautati o alta suma? (d/n): ");
        scanf(" %c", &optiune); // Spatiul inainte de %c curata buffer-ul (tasta Enter)

    } while (optiune == 'd' || optiune == 'D');

    // Pasul 3: Eliberarea memoriei
    free(v);
    printf("Memorie eliberata. Programul s-a inchis.\n");

    return 0;
}

