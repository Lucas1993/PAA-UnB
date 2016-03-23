#include <stdio.h>
#include <string.h>

int v[100005], aux[100005];
long long ans = 0;

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
		if(aux[i] <= aux[j]){
			v[ind] = aux[i++];
		}
		else{
			v[ind] = aux[j++];
			ans+=(i2-i);
		}
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
	int i,j,n,t;
	
	n = 0;
	scanf("%d" ,&t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", &v[i]);
		ans = 0;
		merge_sort(0,n-1);
	
		printf("%lld\n", ans);
	}
	return 0;
}
