//Obreja Ana-Maria 311CA
#include <stdio.h>
#define NMAX 150

void fractie(unsigned long long n, unsigned long long m)
{
unsigned long r = n % m, n1 = n, m1 = m;
//algoritm cel mai mare divizor comun
while (r != 0) {
	n1 = m1;
	m1 = r;
r = n1 % m1;
}

printf("%llu/%llu\n", n / m1, m / m1);
}

int main(void)
{
	unsigned long long i, v[NMAX] = {0}, max = 0, n;
	unsigned long long nr = 0;
	unsigned long long max_top, nr_alerta = 0;
	char k;
	while (1) {
		scanf("%s", &k);
	if (!((k >= 'a' && k <= 'z') || (k == 'Q' || k == 'E' || k == 'T')))
		//verificare caracter invalid
		break;
	if (k >= 'a' && k <= 'z') {
		i = k;
		v[i]++;
		//creste valoarea vectorului de frecventa pentru caracterul citit
		nr++;
		//creste valoarea numerelor citite
		nr_alerta++;
		//creste valoarea numerelor citite de la ultima alerta
	if (v[i] > max)
		max = v[i]; //schimba valoarea maximului
		//verificare conditii pentru afisarea alertei
	if (nr > max && nr_alerta >= 5 && max >= (float)nr / 2) {
		for (i = 97; i < 123; i++) {
			k = i;
		if (v[i] == max) {
			printf("%c ", k);
			fractie(max, nr);
		//luam in considerare primul element cu nr max de aparitii
			break;
			}
		}
		nr_alerta = 0; //resetare pt urmatoarea alerta
		}
		}
		if (k == 'Q') { //afisare nr aparitii pt un caracter
			scanf("%s", &k);
			i = k;
			printf("%c %llu\n", k, v[i]);
		} else if (k == 'E') { //stergere nr aparitii pt un caracter
			scanf("%s", &k);
			i = k;
		//scadem nr aparitii ale caracterului pt corectitudinea alertei viitoare
			nr -= v[i];
			v[i] = 0;
			max = 0;
			//cautarea unui nou maxim
	for (int j = 97; j < 123; j++)
		if (v[j] > max)
			max = v[j];
			//afisarea top n caractere in functie de nr aparitii
		} else if (k == 'T') {
			scanf("%llu", &n);
			//facem o copie a maximului, pentru a nu il distruge
			max_top = max;
		while (n > 0) {
			for (i = 97; i < 123; i++)
				//cautam in caracter care are nr de aparitii egal cu maximul
				if (v[i] == max_top) {
					char j = i;
					printf("%c", j);
					n--;
					//scadem nr de elemente care mai trebuie afisate
					if (n > 0) {
						printf(" ");
					} else {
						printf("\n");
					break;
					}
				}
			//max e de tip intreg; trecem la urmatoarea valoare descrescator
				max_top--;
		}
	}
	}

	return 0;
	}
