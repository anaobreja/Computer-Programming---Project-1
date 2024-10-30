//Obreja Ana-Maria 311CA
#include <stdio.h>
#include <math.h>
#define NMAX 1000
// functie pentru aflarea indexului coloanei
void conversion(int n)
{
	int i = 0;
	char x[NMAX];
	if (n / 26 == 0) {
		//daca n < 26 atunci indexul ia valoarea intre A si Z
		x[i] = 'A' + n % 26;
		//daca n >= 26 si n < 701 atunci indexul ia valoare intre AA si ZZ
	} else if (n < 701) {
		x[i] = 'A' + n / 26 - 1;
		x[++i] = 'A' + n % 26;
		//daca n >= 701 si n<=1000 indexul va avea 3 caractere (ex. AAA)
	} else {
		x[i] = 'A';
		n -= 701;
		i += 1;
		x[i] = 'A' + n / 26 - 1;
		i += 1;
		x[i] = 'A' + n % 26;
	}

	printf("%s", x);
}

int main(void)
{
	int n, i, j, k, l;
	unsigned long d = 0;
	int a[NMAX][NMAX], freq_a[NMAX][NMAX] = {0};
	scanf("%d", &n);
	for (k = 0; k < n; k++)
		for (l = 0; l < n; l++)
			scanf("%d", &a[k][l]);
	//pornim de la prima casuta din stanga sus
	int start = a[0][0];
	while (freq_a[i][j] == 0 && start != 0) {
	//marcam in matricea de frecventa pozitia curenta
		freq_a[i][j] = 1;
	//calcularea distantei
		if (a[i][j] < 0)

			d -= a[i][j];
		else

			d += a[i][j];
		//in cazul in care ne aflam pe casuta alba
		if (i % 2 == j % 2) {
			j += a[i][j];
		//daca noua pozitie depaseste tabla la dreapta
		while (j > n - 1)
			j -= n;
		//daca noua pozitie despaseste tabla la stanga
		while (j < 0)
			j += n;
		//in cazul in care ne aflam pe casuta neagra
		} else {
			i += a[i][j];
		//daca noua pozitie depaseste tabla la dreapta
		while (i > n - 1)
			i -= n;
		//daca noua pozitie despaseste tabla la stanga
		while (i < 0)
			i += n;
		}
		//mutarea pe o noua pozitie
		start = a[i][j];
	}

	printf("%lu\n", d);
	//afisarea liniei de jos in sus
	printf("%d ", n - i);
	conversion(j);
	printf("\n");
	return 0;
}
