//Obreja Ana-Maria 311CA
#include <stdio.h>
#include <math.h>
//conversia din baza 8 in baza 10
int conversion_b10(int x)
{
	int rez = 0;
	int p = 1;
	if (x == 0)
		return 0;
	while (x) {
		rez += (x % 10) * p;
		p *= 8;
		x /= 10;
	}

	return rez;
}

int main(void)
{
	unsigned long long i, n, ps = 0;
	long long first_a_max = -1, first_b_max = -1, a, b;
	long long a_max = -1, b_max = -1;
	double n_a = 0, n_b = 0;
	scanf("%llu", &n);
	for (i = 0; i < n; i++) {
		//se citesc coordonatele vectorilor
		scanf("%lld%lld", &a, &b);
		a = conversion_b10(a);
		b = conversion_b10(b);
		//se calculeaza produsul scalar
		ps += a * b;
		//se calculeaza normele
		n_a +=  a * a;
		n_b +=  b * b;
		//verificare pentru al 2 lea maxim
		if (a > first_a_max) {
			a_max = first_a_max;
			first_a_max = a;
		} else if (a > a_max && a < first_a_max) {
			a_max = a;
		}
		if (b > first_b_max) {
			b_max = first_b_max;
			first_b_max = b;
		} else if (b > b_max && b < first_b_max) {
			b_max = b;
		}
	}

	printf("%llu\n", ps);
	printf("%lld %lld\n", a_max, b_max);
	//afisarea cu 7 zecimale a normei
	printf("%.7lf %.7lf\n", sqrt(n_a), sqrt(n_b));
	return 0;
}
