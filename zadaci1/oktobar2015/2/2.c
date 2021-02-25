#include <stdio.h>
#include <stdlib.h>

typedef struct _polinom{
	char naziv[21];
	int n;
	float *koef;
}polinom;

void greska(){
	printf("-1");
	exit(EXIT_FAILURE);
}

int poredi(polinom p1, polinom p2){
	if(p1.n < p2.n)
		return -1;
	if(p1.n > p2.n)
		return 1;
	
	int i;
	for(i = p1.n - 1; i >= 0; i--){
		if(p1.koef[i] < p2.koef[i])
			return -1;
		if(p1.koef[i] > p2.koef[i])
			return 1;
	}
	return 0;
}

int main(int argc, char **argv){
	FILE *f = fopen("polinomi.txt", "r");
	if(f == NULL)
		greska();
	
	int n;
	fscanf(f, "%d", &n);
	if(n < 0)
		greska();
	
	polinom* niz = malloc(n * sizeof(polinom));
	if(niz == NULL)
		greska();
	
	int i;
	int j;
	for(i = 0; i < n; i++){
		fscanf(f, "%s%d", niz[i].naziv, &niz[i].n);
		niz[i].koef = malloc(niz[i].n * sizeof(float));
		if(niz[i].koef == NULL)
			greska();
		for(j = 0; j < niz[i].n; j++)
			fscanf(f, "%f", &niz[i].koef[j]);
	}
	
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if(poredi(niz[i], niz[j]) < 0){
				polinom tmp = niz[i];
				niz[i] = niz[j];
				niz[j] = tmp;
			}
		}
	}
	
	for(i = 0; i < n; i++){
		printf("%s\n", niz[i].naziv);
	}
	
	for(i = 0; i < n; i++)
		free(niz[i].koef);
	free(niz);
	fclose(f);
}