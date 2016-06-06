#include <stdio.h>
#include <string.h>

typedef long long ll;

int v[2005], s[2005];
ll DP[2005][2005];

ll max(ll a, ll b){
    return (a>b?a:b);
}

int main(){
    int sz,n,i,j;

    scanf("%d%d", &sz, &n);
    for(i = 0; i < n; i++) scanf("%d%d", &s[i],&v[i]);
    
    for(j = 0; j < s[0]; j++) DP[0][j] = 0;
    for(j = s[0]; j <= sz; j++) DP[0][j] = v[0];

    for(i = 1; i < n; i++){
        for(j = 0; j <= sz; j++){
            if(j >= s[i])
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-s[i]] + v[i]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    printf("%lld\n", DP[n-1][sz]);

    return 0;
}
