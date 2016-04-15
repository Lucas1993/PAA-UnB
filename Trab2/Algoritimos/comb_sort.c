#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _string_dado{
	char s[10];
}string_dado;

string_dado *v;

void comb_sort(int size) {
	float shrink_factor = 1.247330950103979;
	int gap = size, swapped = 1, i;
	char swap[10];

	while (gap > 1 || swapped) {
		if (gap > 1)
		gap = gap / shrink_factor;

		swapped = 0;
		i = 0;

		while (gap + i < size) {
			if (strcmp(v[i].s, v[i + gap].s) > 0) {
				strcpy(swap, v[i].s);
				strcpy(v[i].s, v[i + gap].s);
				strcpy(v[i + gap].s, swap);
				swapped = 1;
			}
			++i;
		}
	}
}

int main(){
	int n = 0;
	
	v = malloc(3300000*sizeof(string_dado));
	for(; scanf("%s", v[n].s) == 1; n++);
	
	comb_sort(n);
	
	int i;
	for(i = 0; i < n; i++)
		printf("%s\n", v[i].s);
	
	return 0;
}
