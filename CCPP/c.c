#include <stdio.h>
#include <stdlib.h>

int sumaManjihOdPet(int niz[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] < 5) {
            suma += niz[i];
        }
    }
    return suma;
}

int prebrojVeceOdDevet(int niz[], int n) {
    int br = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] > 9) {
            br++;
        }
    }
    return br;
}

int najmanjaVrednost(int niz[], int n) {
    int najmanji = niz[0];
    for (int i = 1; i < n; i++) {
        if (niz[i] < najmanji) {
            najmanji = niz[i];
        }
    }
    return najmanji;
}

int main() {
    int n;

    printf("Koliko elemenata zelite da unesete? ");
    scanf("%d", &n);

    int* niz = malloc(n * sizeof(int));

    printf("Unesite %d brojeva:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }

    int zbirManjih = sumaManjihOdPet(niz, n);
    int veciOdDevet = prebrojVeceOdDevet(niz, n);
    int minEl = najmanjaVrednost(niz, n);

    printf("\nNajmanja vrednost u nizu: %d\n", minEl);
    printf("Broj elemenata vecih od 9: %d\n", veciOdDevet);
    printf("Suma elemenata manjih od 5: %d\n", zbirManjih);

    system("pause");
    return 0;
}