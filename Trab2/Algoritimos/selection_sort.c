#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _string_dado{
	char s[10];
}string_dado;

string_dado *v;

void selection_sort(int tam) { 
	int i, j, min;
	char aux[10];
	for (i = 0; i < (tam-1); i++){
		min = i;
		for (j = (i+1); j < tam; j++){
			if(strcmp(v[j].s, v[min].s) < 0) 
				min = j;
		}
		if(i != min) {
			strcpy(aux,v[i].s);
			strcpy(v[i].s, v[min].s);
			strcpy(v[min].s, aux);
		}
	}
}

int main(){
	int n = 0;
	
	v = malloc(3300000*sizeof(string_dado));
	for(; scanf("%s", v[n].s) == 1; n++);
	
	selection_sort(n);
	
	int i;
//	for(i = 0; i < n; i++)
//		printf("%s\n", v[i].s);
	
	return 0;
}
