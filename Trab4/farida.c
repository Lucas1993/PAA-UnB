#include <stdio.h>
#include <string.h>

typedef long long ll;

int v[10005];
ll DP[10005];

ll max(ll a, ll b){
    return (a>b?a:b);
}

ll f(int i){
    if(i < 0) return 0;
    if(DP[i] != -1) return DP[i];
    ll ret = max(f(i-1), f(i-2) + v[i]);
    return DP[i] = ret;
}

int main(){
    int t,n,i,tc=1;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%d", &v[i]);
        memset(DP,-1,sizeof(DP));
        printf("Case %d: %lld\n",tc++,f(n-1));
    }
    
    return 0;
}
