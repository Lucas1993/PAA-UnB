#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _string_dado{
	char s[10];
}string_dado;

string_dado *v;

void bubble_sort(int size){
	int i, j;
	char aux[10];

	for(int i=size-1; i >= 1; i--){  
		for( int j=0; j < i ; j++){
			if(strcmp(v[j].s, v[j+1].s) > 0){
				strcpy(aux, v[j].s);
				strcpy(v[j].s, v[j+1].s);
				strcpy(v[j+1].s, aux);
			}
		}
	}
}

int main(int argc, char *argv[]){
	int n = 0;

	if(argc < 2){
		printf("Passar um parametro: arq_ent\n");
		return 1;
	}
	FILE *fp;
	fp = fopen(argv[1], "r");
	v = malloc(3300000*sizeof(string_dado));

	for(; fscanf(fp,"%s", v[n].s) == 1; n++);
	
	bubble_sort(n);
	
	int i;
//	for(i = 0; i < n; i++)
//		printf("%s\n", v[i].s);
	
	return 0;
}
