#include <stdio.h>
#include <string.h>

typedef long long ll;

int DP[2005][2005];
char s1[2005], s2[2005];

int min(int a, int b){
    return (a<b?a:b);
}

int f(int i, int j){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(DP[i][j] != -1) return DP[i][j];
    int ret = min(f(i-1,j)+1,f(i,j-1)+1);
    if(s1[i] == s2[j]) ret = min(ret,f(i-1,j-1));
    else ret = min(ret,f(i-1,j-1)+1);
    return DP[i][j] = ret;
}

int main(){
    int t,n,i;

    scanf("%d", &t);
    while(t--){
        scanf(" %s %s", s1,s2);
        memset(DP,-1,sizeof(DP));
        printf("%d\n",f(strlen(s1),strlen(s2)));
    }
    
    return 0;
}
