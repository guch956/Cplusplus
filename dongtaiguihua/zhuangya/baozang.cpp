#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f;
ll g[13][13];
ll dp[1<<12][13];
ll zuixiao[1<<12][1<<12];
int main(){
    int n,m,i,j,a,b,d,k;
    ll c,ans=INF;
    scanf("%d %d",&n,&m);
    d=(1<<n)-1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            g[i][j]=INF;
        }
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %lld",&a,&b,&c);
        g[a][b]=min(g[a][b],c);
        g[b][a]=min(g[b][a],c);
    }
    for(i=0;i<n;i++){
        zuixiao[1<<i][0]=INF;
        for(j=1;j<=n;j++){
            for(k=1<<(j-1);k<=(1<<j)-1;k++){
                zuixiao[1<<i][k]=min(zuixiao[1<<i][k-(1<<(j-1))],g[i+1][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(k=1<<(i-1);k<=(1<<i)-1;k++){
            for(j=1;j<=d;j++){
                zuixiao[k][j]=zuixiao[k-(1<<(i-1))][j]+zuixiao[1<<(i-1)][j];
            }
        }
    }
    for(i=1;i<=n;i++){
        dp[1<<(i-1)][0]=0;
        for(k=(1<<(i-1))+1;k<=(1<<i)-1;k++){
            dp[k][0]=INF;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=d;j++){
            dp[j][i]=INF;
        }
        for(j=1;j<=d;j++){
            for(k=1;k<=d;k++){
                if((j&k)==0){
                    dp[j|k][i]=min(dp[j|k][i],zuixiao[k][j]*i+dp[j][i-1]);
                }
            }
        }
        ans=min(ans,dp[d][i]);
    }
    if(ans<INF){cout<<ans;}
    else {cout<<0;}
    return 0;
}