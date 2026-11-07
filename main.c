#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10000

// Tri à bulles (lent sur de grands tableaux)
void triBulles(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Tri par insertion (plus efficace pour des données partiellement triées)
void triInsertion(int arr[], int n) {
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

// Fonction pour remplir un tableau avec des nombres aléatoires identiques pour les deux tests
void copierTableau(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int *tab1 = (int *)malloc(TAILLE * sizeof(int));
    int *tab2 = (int *)malloc(TAILLE * sizeof(int));

    if (tab1 == NULL || tab2 == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Génération de nombres aléatoires
    srand(time(NULL));
    for (int i = 0; i < TAILLE; i++) {
        tab1[i] = rand() % 100000;
    }

    copierTableau(tab1, tab2, TAILLE);

    printf("=== COMPARATEUR DE PERFORMANCES DE TRIS (%d elements) ===\n\n", TAILLE);

    // Test du Tri à Bulles
    clock_t debut = clock();
    triBulles(tab1, TAILLE);
    clock_t fin = clock();
    double tempsBulles = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("1. Tri a bulles     : %.4f secondes\n", tempsBulles);

    // Test du Tri par Insertion
    debut = clock();
    triInsertion(tab2, TAILLE);
    fin = clock();
    double tempsInsertion = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("2. Tri par insertion : %.4f secondes\n", tempsInsertion);

    // Libération de la mémoire
    free(tab1);
    free(tab2);

    printf("\nTest termine avec succes !\n");
    return 0;
}
