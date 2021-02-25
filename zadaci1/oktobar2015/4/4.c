#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int cifre(int x){
	int s  = 0;
	while(x != 0){
		s += x % 10;
		x = x / 10;
	}
	return s;
}

void f4(cvor *g, int k){
	if(g == NULL || g->sledeci == NULL)
		return;
	
	f4(g->sledeci, k);
	
	int x1 = g->vrednost;
	int x2 = g->sledeci->vrednost;
	
	if(x1 + x2 == k || x1 - x2 == k || x2 - x1 == k)
	{
		cvor *n = kreiraj_novi_cvor(cifre(x1) + cifre(x2));
		n->sledeci = g->sledeci;
		g->sledeci = n;
	}
}

int main(){
	cvor *lista = ucitaj_listu();
	int k;
	scanf("%d", &k);
	f4(lista, k);
	ispis(lista);
	lista = oslobodi(lista);
	return 0;
}