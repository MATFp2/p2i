#include <stdio.h>
#include <stdlib.h>

void greska(){
	printf("-1");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv){
	if(argc < 2)
		greska();
	
	int k = atoi(argv[1]);
	if(k < 1)
		greska();
	int i = 1;
	while(argv[i + 1]){
		if(i % k == 0)
			printf("%s ", argv[i+1]);
		i++;
	}
}