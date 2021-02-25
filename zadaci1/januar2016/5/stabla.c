#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

cvor* napravi_cvor(int b )
{
  cvor* novi = (cvor*) malloc(sizeof(cvor));
  
  if( novi == NULL)
    return NULL;	
  
  novi->broj = b;
  novi->levo = NULL;
  novi->desno = NULL;
  
  return novi;
}

cvor* oslobodi_stablo(cvor* koren)
{	
  if(koren == NULL)
	return NULL;
  oslobodi_stablo(koren->levo);
  oslobodi_stablo(koren->desno);
  free(koren);
  return NULL;
}

cvor* dodaj_u_stablo(cvor* koren, int broj)
{
  if( koren == NULL){
    cvor *novi =napravi_cvor(broj);
    if(novi == NULL) {
      fprintf(stderr, "GRESKA: malloc() u funkciji napravi_cvor()!\n");
      oslobodi_stablo(koren);
      exit(EXIT_FAILURE);
    }
    
    return novi;
  }
  
  
  if( broj < koren->broj)		
    koren->levo = dodaj_u_stablo(koren->levo, broj);
  else 
    koren->desno = dodaj_u_stablo(koren->desno, broj);
  return koren;	
}

cvor* ucitaj_stablo() {
  cvor* koren = NULL;
  int x = 1;
  while(1) {
    scanf("%d", &x);
    if (x == 0)
      break;
    koren = dodaj_u_stablo(koren, x);
  }
  return koren;
}

void ispisi_stablo(cvor *koren) {
  if (koren == NULL)
    return;
  ispisi_stablo(koren -> levo);
  printf("%d ", koren -> broj);
  ispisi_stablo(koren -> desno);
}
