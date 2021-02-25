#ifndef __LISTE_H__
#define __LISTE_H__ 1

typedef struct _cvor
{
	int vrednost;
	struct _cvor *sledeci;
}cvor;

cvor* kreiraj_novi_cvor(int vrednost);
cvor* dodaj_na_pocetak(cvor *glava, int vrednost);
cvor* dodaj_na_kraj(cvor *glava, int vrednost);
void ispis(cvor *glava);
cvor* oslobodi(cvor *glava);
cvor* ucitaj_listu();

#endif
