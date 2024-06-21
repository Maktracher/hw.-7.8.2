#include <stdlib.h>
#include <stdio.h>
#include <time.h> // Pridané na použitie funkcie time().
#pragma warning (disable:4996) // Pridané pre kompilátor VS

#define PERMUTATION_SIZE 10  // Konštanta pre veľkosť permutácie

// Funkcia na vizualizáciu permutácie vo formáte SVG
char svg_draw_permutation(int* perm, int n) {
    if (perm == NULL || n <= 0) { // Overenie
        printf("Error: Nesprávne vstupné údaje");
        return -1;
    }
    FILE* svg_file = fopen("permutation.svg", "w"); // Otvorenie súboru na zápis
    if (svg_file == NULL) { // Kontrola chyby pri otváraní súboru
        printf("Error: nepodarilo sa otvoriť súbor");
        return -1;
    }
    size_t width = 50 * n, height = 50 * n; // Rozmery obrázka SVG
    fprintf(svg_file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"); // Hlavička SVG
    fprintf(svg_file, "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%zu\" height=\"%zu\">\n", width, height); // Otvorte značku SVG

    // Kreslenie indexov nad a pod obrázkom
    for (int i = 0; i < n; ++i) {
        fprintf(svg_file, "<text x='%d' y='15' font-size='12' text-anchor='middle'>%d</text>\n", 50 * i + 25, i);
        fprintf(svg_file, "<text x='%d' y='%zu' font-size='12' text-anchor='middle'>%d</text>\n", 50 * i + 25, height - 10, perm[i]);
    }

    for (int i = 0; i < n; ++i) { // Kreslenie permutačných čiar
        fprintf(svg_file, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='green' />\n",
            50 * i + 25, 25, 50 * perm[i] + 25, 50 * n - 25);
    }

    fprintf(svg_file, "<defs>\n<marker id='arrow' markerWidth='10' markerHeight='10' refX='0' refY='3' orient='auto' markerUnits='strokeWidth'>\n");
    fprintf(svg_file, "<path d='M0,0 L0,6 L9,3 z' fill='green' />\n</marker>\n</defs>\n");

    fprintf(svg_file, "</svg>");
    fclose(svg_file);

    printf("Obraz bol úspešne vytvorený\n");
    return 1;
}

int main() {
    srand((unsigned)time(NULL));

    int permut[PERMUTATION_SIZE];
    for (size_t i = 0; i < PERMUTATION_SIZE; i++) {
        permut[i] = i;
    }

    // Generovanie permutácie pomocou algoritmu Fisher-Yates
    for (size_t i = PERMUTATION_SIZE - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        int temp = permut[i];
        permut[i] = permut[j];
        permut[j] = temp;
    }

    svg_draw_permutation(permut, PERMUTATION_SIZE);

    return 0;
}
