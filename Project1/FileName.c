#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> // Pridané na použitie matematických funkcií

#define PERMUTATION_SIZE 10 // Konštanta pre veľkosť permutácie
#define M_PI 3.14159265358979323846

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

    // Kreslíme indexy nad a pod obrázkom
    for (int i = 0; i < n; ++i) {
        fprintf(svg_file, "<text x='%d' y='15' font-size='12' text-anchor='middle'>%d</text>\n", 50 * i + 25, i);
        fprintf(svg_file, "<text x='%d' y='%zu' font-size='12' text-anchor='middle'>%d</text>\n", 50 * i + 25, height - 10, perm[i]);
    }

    // Kreslíme vektory so "šípkami" na koncoch
    for (int i = 0; i < n; ++i) {
        int startX = 50 * i + 25;
        int startY = height - 25;
        int endX = 50 * perm[i] + 25;
        int endY = 25;

        // Kreslíme líniu vektora
        fprintf(svg_file, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='green' stroke-width='2' />\n", startX, startY, endX, endY);

        // Nájdeme uhol smeru vektora
        double angle = atan2(endY - startY, endX - startX);

        // Dĺžka "šípky"
        double arrow_length = 15.0;
        double arrow_angle = M_PI / 6;

        // Koordináty koncov "šípky"
        double arrow_end1_x = endX - arrow_length * cos(angle - arrow_angle);
        double arrow_end1_y = endY - arrow_length * sin(angle - arrow_angle);
        double arrow_end2_x = endX - arrow_length * cos(angle + arrow_angle);
        double arrow_end2_y = endY - arrow_length * sin(angle + arrow_angle);

        // Kreslíme "šípku" na konci vektora
        fprintf(svg_file, "<polygon points='%d,%d %d,%d %d,%d' style='fill:green;' />\n",
            (int)arrow_end1_x, (int)arrow_end1_y, endX, endY, (int)arrow_end2_x, (int)arrow_end2_y);
    }

    fprintf(svg_file, "</svg>");
    fclose(svg_file);

    printf("SVG súbor úspešne vytvorený: permutation.svg\n");
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
