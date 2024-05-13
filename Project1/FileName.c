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

}
int main() {

}