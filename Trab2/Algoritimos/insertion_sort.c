#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _string_dado{
	char s[10];
}string_dado;

string_dado *v;

void insertion_sort(int size){
	int i, j;
	char atual[10];

	for (i = 1; i < size; i++){
		strcpy(atual, v[i].s);
		j = i - 1;

		while ((j >= 0) && strcmp(atual, v[j].s) < 0){
			strcpy(v[j + 1].s, v[j].s);
            j = j - 1;
		}
    
		strcpy(v[j + 1].s, atual);
	}
}

int main(){
	int n = 0;
	
	v = malloc(3300000*sizeof(string_dado));

	for(; scanf("%s", v[n].s) == 1; n++);
	
	insertion_sort(n);
	
	int i;
	for(i = 0; i < n; i++)
		printf("%s\n", v[i].s);
	
	return 0;
}
