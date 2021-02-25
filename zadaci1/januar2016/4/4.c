#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

cvor* f4(cvor *g){
	if(g == NULL)
		return NULL;
	if(g->sledeci == NULL)
		return g;
	
	cvor *glava = g;
	cvor *sledeci = g->sledeci;
	
	g = f4(g->sledeci);
	sledeci->sledeci = glava;
	glava->sledeci = NULL;
	return g;
}

int main(){
	cvor *lista = ucitaj_listu();
	lista = f4(lista);
	ispis(lista);
	lista = oslobodi(lista);
	return 0;
}