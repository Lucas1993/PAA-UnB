#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct _string_dado{
	char s[10];
}string_dado;

string_dado *v;

void increasing(int tam){
	int i,j;
	char aux[10];
	strcpy(aux, "aaaaa");
	for(i = 0; i < tam; i++){
		strcpy(v[i].s, aux);
		j = 4;
		while(1){
			if(aux[j] == 'z') aux[j--] = 'a';
			else{
				aux[j]++;
				break;
			}
		}
	}
}

void string_swap(int i, int j){
	char aux[10];
	strcpy(aux, v[i].s);
	strcpy(v[i].s, v[j].s);
	strcpy(v[j].s, aux);
}

void shuffle(int tam){
	int i,j;
	srand(time(NULL));
	for(i = tam-1; i >= 0; i--){
		j = i + rand() / (RAND_MAX / (tam - i) + 1);
		string_swap(i,j);
	}
}

int main(int argc, char *argv[]){
	
	if(argc < 3){
		printf("Tem que passar 3 argumentos: op, tam, arq_saida\n");
		return 1;
	}
	int op = atoi(argv[1]);
	int tam = atoi(argv[2]);
	char arq[30];
	strcpy(arq,argv[3]);
	v = (string_dado*)malloc(tam*sizeof(string_dado));
	increasing(tam);
	int i;
	FILE *fp;
	fp = fopen(arq, "w");
	if(op == 1){
		for(i = 0; i < tam; i++)
			fprintf(fp,"%s\n", v[i].s);
	}
	else if(op == 2){
		for(i = tam; i >= 0; i--)
			fprintf(fp,"%s\n", v[i].s);
	}
	else{
		shuffle(tam);
		for(i = 0; i < tam; i++)
			fprintf(fp,"%s\n", v[i].s);
	}

	return 0;
}