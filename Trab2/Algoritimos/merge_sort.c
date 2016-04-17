#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _string_dado{
	char s[10];
}string_dado;

string_dado *v;
string_dado *aux;

void merge_vec(int ini, int fim){
	int i;
	for(i = ini; i <= fim; i++)
		strcpy(aux[i].s, v[i].s);
	int i2,j,j2,ind,mid = (ini+fim)/2;
	i = ini;
	i2 = mid+1;
	j = mid+1;
	j2 = fim+1;
	ind = ini;
	while(i < i2 && j < j2){
		if(strcmp(aux[i].s, aux[j].s) < 0)
			strcpy(v[ind].s, aux[i++].s);
		else
			strcpy(v[ind].s, aux[j++].s);
		ind++;
	}
	while(i < i2)
		strcpy(v[ind++].s, aux[i++].s);
	while(j < j2)
		strcpy(v[ind++].s, aux[j++].s);
	
}

void merge_sort(int ini, int fim){
	if(ini != fim){
		int mid = (ini+fim)/2;
		merge_sort(ini, mid);
		merge_sort(mid+1, fim);
		merge_vec(ini, fim);
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
	aux = malloc(3300000*sizeof(string_dado));
	for(; fscanf(fp,"%s", v[n].s) == 1; n++);
	
	merge_sort(0,n-1);
	
	int i;
//	for(i = 0; i < n; i++)
//		printf("%s\n", v[i].s);
	
	return 0;
}
