#include <stdlib.h>
#include <stdio.h>
<<<<<< < Updated upstream
#include <time.h> // Pridané na použitie funkcie time().
#pragma warning (disable:4996) // Pridané pre kompilátor VS

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
	fprintf(svg_file, "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\">\n", width, height); // Otvorte značku SVG

	for (int i = 0; i < n; ++i) { // Kreslenie permutačných čiar
		fprintf(svg_file, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='green' />\n",
			50 * i + 25, 25, 50 * perm[i] + 25, 50 * n - 25);
	}

	fprintf(svg_file, "</svg>"); // Zatvorte značku SVG
	fclose(svg_file); // Zatvorte súbor

	printf("Obraz bol úspešne vytvorený ");
	return 1;
}

int main() {

}