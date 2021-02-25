#ifndef __STABLA_H__
#define __STABLA_H__ 1

typedef struct _cvor{
  int broj;
  struct _cvor* levo, *desno;
} cvor;

cvor* napravi_cvor(int b );
cvor* oslobodi_stablo(cvor* koren);
cvor* dodaj_u_stablo(cvor* koren, int broj);
cvor* ucitaj_stablo();
void ispisi_stablo(cvor *koren);

#endif
