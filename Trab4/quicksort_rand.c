#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int v[1000005];

void swap(int a, int b){
    int aux;
    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int hoare_partition(int p, int r){
    int x = v[p + rand()%(r-p)];
    int i = p-1;
    int j = r+1;
    while(1){
        do{
            j--;
        }while(v[j] > x);
        do{
            i++;
        }while(v[i] < x);
        if(i < j) swap(i, j);
        else return j;
    }
}

void quicksort(int p, int r){
    int q;
    if(p < r){
        q = hoare_partition(p,r);
        quicksort(p,q);
        quicksort(q+1,r);
    }
}

int main(){
    int n,i,ans;

	srand(time(NULL));
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);
    quicksort(0,n-1);
    for(i = 0; i < n; i++)
        printf("%d\n", v[i]);

	return 0;
}
