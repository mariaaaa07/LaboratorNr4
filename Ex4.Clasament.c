#include <stdio.h>
#include <string.h>

// Definim structura pentru un alergator
typedef struct {
    char nume[50];
    float timp;
} Alergator;

int main() {
    int n = 10;
    Alergator lista[10] = {
        {"George", 10.22}, {"Ana", 8.75}, {"Ionut", 9.15}, 
        {"Maria", 8.90}, {"Dan", 11.05}, {"Elena", 9.40}, 
        {"Radu", 10.01}, {"Andreea", 8.82}, {"Victor", 12.30}, {"Oana", 9.95}
    };

    // Algoritm de sortare (Bubble Sort) pentru a ordona dupa timp
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j].timp > lista[j + 1].timp) {
                // Interschimbam obiectele de tip Alergator
                Alergator temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }

    // Afisarea rezultatelor sub forma de clasament
    printf("Clasament Final:\n");
    printf("---------------------------\n");
    for (int i = 0; i < n; i++) {
        // i + 1 reprezinta locul (indexul incepe de la 0)
        printf("Locul %d: %s\n", i + 1, lista[i].nume);
    }

    return 0;
}
