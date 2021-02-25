#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
	printf("-1");
	exit(EXIT_FAILURE);
}

int broj_jedinica(unsigned x){
	int rez = 0;
	unsigned k = 1;
	int i;
	for(i = 0; i < 8 * sizeof(unsigned); i++){
		unsigned a = x & k;
		if(a != 0)
			rez++;
		k = k << 1;
	}
	return rez;
}

int main(){
	unsigned x;
	unsigned n;
	unsigned *niz;
	
	scanf("%u", &x);
	scanf("%u", &n);
	if(n < 0)
		greska();
	
	niz = malloc(n * sizeof(unsigned));
	if(niz == NULL)
		greska();
	
	int i;
	for(i = 0; i < n; i++)
		scanf("%u", &niz[i]);
	
	unsigned k = 1;
	for(i = 0; i < n; i++){
		if(broj_jedinica(niz[i]) > broj_jedinica(x)){
			niz[i] = niz[i] & (~k);
		}
		else {
			niz[i] = niz[i] | k;
		}
		k = k << 1;
	}
	
	for(i = 0; i < n; i++)
		printf("%u ", niz[i]);
	
	free(niz);
}