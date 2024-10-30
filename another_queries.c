//Obreja Ana-Maria 311CA
#include <stdio.h>
#include <math.h>
#define NMAX 400

void citire(int n, int a[NMAX][NMAX])
{
	int i, j;
	for (i = 0; i < n * n; i++)
		for (j = 0; j < n * n; j++)
			scanf("%d", &a[i][j]);
}

//verificare pentru linie
void check_linie(int n, int x, int v_linie[NMAX], int a[NMAX][NMAX])
{
	int j, k;
	//dam tuturor elemnetelor vectorului valoarea 0
	for (k = 0; k < n * n; k++)
		v_linie[k] = 0;
	for (j = 0; j < n * n; j++)
		//verificam daca valoarea dim matrice e mai mare decat 0
		if (a[x - 1][j] > 0)
		//crestem valoarea din vectorul de frecventa
			v_linie[a[x - 1][j] - 1]++;
}

//verificare pentru coloana
void check_coloana(int n, int y, int v_coloana[NMAX], int a[NMAX][NMAX])
{
	int j, k;
	for (k = 0; k < n * n; k++)
		v_coloana[k] = 0;
	for (j = 0; j < n * n; j++)
		//verificam daca valoarea dim matrice e mai mare decat 0
		if (a[j][y - 1] > 0)
		//crestem valoarea din vectorul de frecventa
			v_coloana[a[j][y - 1] - 1]++;
}

//verificare pentru careu
void check_careu(int n, int z, int v_careu[NMAX], int a[NMAX][NMAX])
{
	int j, i, k;
	for (k = 0; k < n * n; k++)
		v_careu[k] = 0;
	//incadrarea liniilor si a coloanelor intr-un careu
	for (i = ((z - 1) / n) * n; i <= ((z - 1) / n) * n + n - 1; i++)
		for (j = ((z - 1) % n) * n; j <= ((z - 1) % n) * n + n - 1; j++)
		//verificam daca valoarea dim matrice e mai mare decat 0
			if (a[i][j] > 0)
			//crestem valoarea din vectorul de frecventa
				v_careu[a[i][j] - 1]++;
}

void print_conditie(int n, int v[NMAX])
{
	int i;
	for (i = 0; i < n * n; i++)
	//daca valoarea vectorului este 0, cifra (i + 1) poate fi pusa in casuta
		if (v[i] == 0)
		//se afiseaza 1 daca cifra poate fi pusa in casuta
			printf("%d ", 1);
		else
			printf("%d ", 0);
	printf("\n");
}

//conditie afisare pentru cazul 6
void conditie_ok(int n, int ok, int a[NMAX][NMAX])
{
	int i, j;
	//daca ok are valoarea 0, am ajuns la o configuratie invalida
	if (ok == 0) {
		printf("%d\n", 1);
	//configuratie valida sau joc terminat
	} else {
		int ok_1 = 1;
		for (i = 0; i < n * n; i++)
			for (j = 0; j < n * n; j++)
				if (a[i][j] == 0) {
					ok_1 = 0;
					break;
				}
		if (ok_1 == 0)
			printf("%d\n", 0);
		else
			printf("%d\n", 2);
	}
}

int main(void)
{
	int n, a[NMAX][NMAX], x, y, z, k, i, val, ok, t;
	unsigned long long m, l;
	int v_linie[NMAX], v_coloana[NMAX], v_careu[NMAX];
	int v_verificare_4[NMAX];
	scanf("%d%llu", &n, &m);
	citire(n, a);
	for (l = 1; l <= m; l++) {
		scanf("%d", &t);
	if (t == 1) {
		scanf("%d", &x);
		check_linie(n, x, v_linie, a); //verificare
		print_conditie(n, v_linie); //afisare
	} else if (t == 2) {
		scanf("%d", &y);
		check_coloana(n, y, v_coloana, a);
		print_conditie(n, v_coloana);
	} else if (t == 3) {
		scanf("%d", &z);
		check_careu(n, z, v_careu, a);
		print_conditie(n, v_careu);
	} else if (t == 4) {
		scanf("%d", &x);
		scanf("%d", &y);
		for (i = 0; i < n * n; i++)
			v_verificare_4[i] = 0;
		if (a[x - 1][y - 1] != 0) { //daca valoarea din casuta nu este 0
			for (i = 0; i < n * n; i++)
				printf("%d ", 0); //afisam 0 pentru toate cifrele
		} else {
			check_linie(n, x, v_linie, a);
			check_coloana(n, y, v_coloana, a);
			z = ((x - 1) / n) * n + (y - 1) / n + 1; //incadrare in careu
			check_careu(n, z, v_careu, a);
			for (i = 1; i <= n * n; i++)
				if (v_linie[i - 1] == 0)
					if (v_coloana[i - 1] ==  0 && v_careu[i - 1] == 0)
					//dam vectorului valoarea 1 pt cifrele utilizabile
						v_verificare_4[i - 1] = 1;
			for (i = 0; i < n * n; i++)
				printf("%d ", v_verificare_4[i]);
			}
			printf("\n");
	} else if (t == 5) {
		scanf("%d%d%d", &x, &y, &val);
		if (a[x - 1][y - 1] == 0)
			a[x - 1][y - 1] = val; //schimbam valoarea din casuta
	} else {
		ok = 1;
		for (x = 1; x <= n * n; x++) {
			check_linie(n, x, v_linie, a);
			for (k = 0; k < n * n; k++)
				if (v_linie[k] > 1) { //verificare existenta linie invalida
					ok = 0;
					break;
				}
		}
		if (ok == 1) //verificare existenta coloana invalida
			for (y = 1; y <= n * n; y++) {
				check_coloana(n, y, v_linie, a);
				for (k = 0; k < n * n; k++)
					if (v_coloana[k] > 1) {
						ok = 0;
						break;
					}
			}
		if (ok == 1) { //verificare existenta careu invalid
			for (z = 1; z <= n * n; z++) {
				check_careu(n, z, v_careu, a);
				for (k = 0; k < n * n; k++)
					if (v_careu[k] > 1) {
						ok = 0;
						break;
					}
			}
		}
		conditie_ok(n, ok, a);
	}
	}
	return 0;
}
