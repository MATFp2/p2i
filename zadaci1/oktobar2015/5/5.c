#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int f5(cvor *s, int k){
	if(s == NULL)
		return 0;
	
	if(k % 2 == 0){
		return s->broj + f5(s->levo, k + 1) + f5(s->desno, k + 1);
	}
	else{
		return -(s->broj) + f5(s->levo, k + 1) + f5(s->desno, k + 1);
	}
}

int main(){
	cvor *stablo = ucitaj_stablo();
	printf("%d\n", f5(stablo, 1));
	stablo = oslobodi_stablo(stablo);
	return 0;
}