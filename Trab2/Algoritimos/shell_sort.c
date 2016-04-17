#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _string_dado{
	char s[10];
}string_dado;

string_dado *v;

void shell_sort(int size) {
	int i , j;
	int gap = 1;
	char value[10];
	
	while(gap < size){
		gap = 3*gap+1;
	}
	while(gap > 1) {
		gap /= 3;
		for(i = gap; i < size; i++) {
			strcpy(value, v[i].s);
			j = i - gap;
			while (j >= 0 && strcmp(value, v[j].s) < 0 ){
				strcpy(v[j + gap].s, v[j].s);
				j -= gap;
			}
			strcpy(v[j + gap].s, value);
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
	
	shell_sort(n);
	
	int i;
//	for(i = 0; i < n; i++)
//		printf("%s\n", v[i].s);
	
	return 0;
}
