#include <stdio.h>
#include <string.h>

int v[100005], aux[100005];

void merge_vec(int ini, int fim){
	int i;
	for(i = ini; i <= fim; i++)
		aux[i] = v[i];
	int i2,j,j2,ind,mid = (ini+fim)/2;
	i = ini;
	i2 = mid+1;
	j = mid+1;
	j2 = fim+1;
	ind = ini;
	while(i < i2 && j < j2){
		if(aux[i] < aux[j])
			v[ind] = aux[i++];
		else
			v[ind] = aux[j++];
		ind++;
	}
	while(i < i2)
		v[ind++] = aux[i++];
	while(j < j2)
		v[ind++] = aux[j++];
	
}

void merge_sort(int ini, int fim){
	if(ini != fim){
		int mid = (ini+fim)/2;
		merge_sort(ini, mid);
		merge_sort(mid+1, fim);
		merge_vec(ini, fim);
	}
}

int main(){
	int i,j,n;
	
	n = 0;
	while(scanf("%d", &v[n++]) == 1);
	n--;
	merge_sort(0,n-1);
	
	for(i = 0; i < n; i++){
		if(i == n-1) printf("%d\n", v[i]);
		else printf("%d ", v[i]);
	}
	return 0;
}