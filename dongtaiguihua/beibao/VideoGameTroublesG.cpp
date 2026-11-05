#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
const int INF=0x3f3f3f3f;
int dp[2][N];
int price[53];
int pri[503];
int val[503];
int fa[503];
int main(){
    int i,n,d=0,m,j,k,now=1,old=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&price[i]);
        scanf("%d",&k);
        for(j=1;j<=k;j++){
            d++;
            scanf("%d %d",&pri[d],&val[d]);
            fa[d]=i;
        }
    }
    d = 1;
    for(i=1;i<=n;i++){
        for(j=0;j<price[i];j++){
            dp[now][j]=-INF;
        }
        for(j=price[i];j<=m;j++){
            dp[now][j]=dp[old][j-price[i]];
        }
        while(fa[d]==i){
            for(j=m;j>=pri[d];j--){
                dp[now][j]=max(dp[now][j],dp[now][j-pri[d]]+val[d]);
            }
            d++;
        }
        for(j=0;j<=m;j++){
            dp[now][j] = max(dp[now][j],dp[old][j]);
        }
        swap(now,old);
    }
    cout<<dp[old][m];
    return 0;
}