#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int zbir(cvor *s){
	if(s == NULL)
		return 0;
	return zbir(s->levo) + zbir(s->desno) + s->broj;
}

void f5(cvor *s){
	if(s == NULL)
		return;
	
	f5(s->levo);
	
	if(s->desno != NULL){
		if(zbir(s->levo) < s->desno->broj)
			printf("%d ", s->broj);
	}
	 
	f5(s->desno);
}

int main(){
	cvor *stablo = ucitaj_stablo();
	f5(stablo);
	stablo = oslobodi_stablo(stablo);
	return 0;
}