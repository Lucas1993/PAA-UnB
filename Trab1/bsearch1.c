#include <stdio.h>

int v[100005];

int bsearch(int tam, int num){
	int hi,mid,lo;
	hi = tam-1;
	lo = -1;
	while(hi > lo+1){
		mid = (hi+lo)/2;
		if(v[mid] >= num) hi = mid;
		else lo = mid;
	}
	if(v[hi] == num) return hi;
	return -1;
}

int main(){
	int i,q,n,num;
	
	n = 0;
	scanf("%d %d" ,&n, &q);
	for(i = 0; i < n; i++) scanf("%d", &v[i]);
	
	while(q--){
		scanf("%d", &num);
		printf("%d\n", bsearch(n,num));
	}
	return 0;
}