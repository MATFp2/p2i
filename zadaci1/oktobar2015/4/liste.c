#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

cvor* kreiraj_novi_cvor(int vrednost)
{
	cvor* novi = (cvor*)malloc(sizeof(cvor));
	if(novi == NULL)
	{
		fprintf(stderr, "greska");
		exit(EXIT_FAILURE);
	}
	novi->vrednost = vrednost;
	novi->sledeci = NULL;
	return novi;
}

cvor* dodaj_na_pocetak(cvor *glava, int vrednost)
{
	cvor *novi = 
		kreiraj_novi_cvor(vrednost);
	
	novi->sledeci = glava;
	
	return novi;
}

cvor* dodaj_na_kraj(cvor *glava, int vrednost)
{
	if(glava == NULL)
		return kreiraj_novi_cvor(vrednost);
	else
	{
		glava->sledeci = 
			dodaj_na_kraj(glava->sledeci, vrednost);
		return glava;
	}
}

void ispis(cvor *glava)
{
	if(glava == NULL)
		printf("\n");
	else
	{
		printf("%d ", glava->vrednost);
		ispis(glava->sledeci);
	}
}

cvor* oslobodi(cvor *glava)
{
	if(glava == NULL)
		return NULL;
	else
	{
		oslobodi(glava->sledeci);
		free(glava);
		return NULL;
	}
}

cvor* ucitaj_listu()
{
	cvor *lista = NULL;
	int x;
	
	scanf("%d", &x);
	while(x != 0)
	{
		lista = dodaj_na_kraj(lista, x);
		scanf("%d", &x);
	}
	
	return lista;
}
