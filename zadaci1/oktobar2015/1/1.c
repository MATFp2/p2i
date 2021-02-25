#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
	if((argc - 1) % 3 != 0){
		printf("-1");
		return;
	}
	
	float max = 0;
	int i;
	for(i = 1; i < argc;){
		float a = atof(argv[i]);
		i++;
		float b = atof(argv[i]);
		i++;
		float c = atof(argv[i]);
		i++;
		
		float s = (a + b + c) / 2;
		float pov = sqrtf(s * (s - a) * (s - b) * (s - c));
		if(pov > max)
			max = pov;
	}
	
	printf("%.2f", max);
	return 0;
}