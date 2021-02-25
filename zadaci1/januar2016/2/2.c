#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	printf("-1");
	exit(EXIT_FAILURE);
}

int poredi(const void *a, const void *b){
	return strcmp(*((char**)a), *((char**)b));
}

int main(int argc, char **argv){
	FILE *f = fopen("recenice.txt", "r");
	if(f == NULL)
		greska();
	
	char s[101];
	char **niz = NULL;
	int n = 0;
	int i;
	while(fgets(s, 101, f) != NULL){
		
		int l = strlen(s);
		if(!(l > 0))
			continue;
		
		if(s[l-1] == '\n'){
			s[l - 1] = 0;
			l--;
		}
		
		if(l < 3)
			continue;
		if(!('A' <= s[0] && s[0] <= 'Z'))
			continue;
		if(!('a' <= s[1] && s[1] <= 'z'))
			continue;
		if(!('a' <= s[l-2] && s[l-2] <= 'z'))
			continue;
		if(!(s[l-1] == '.' || s[l-1] == '!' || s[l-1] == '?'))
			continue;
		n++;
		niz = realloc(niz, n * sizeof(char*));
		if(niz == NULL)
			greska();
		niz[n-1] = malloc((l + 1) * sizeof(char));
		if(niz[n-1] == NULL)
			greska();
		strcpy(niz[n-1], s);
	}
	fclose(f);
	
	qsort(niz, n, sizeof(char*), poredi);
	
	FILE *g = fopen("sort_recenice.txt", "w");
	if(g == NULL)
		greska();
	for(i = 0; i < n; i++)
		fprintf(g, "%s\n", niz[i]);
	fclose(g);
	
	for(i = 0; i < n; i++)
		free(niz[i]);
	free(niz);
}