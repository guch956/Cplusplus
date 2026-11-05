#include<iostream>
#include<cstdio>
using namespace std;
const int N=203;
const int INF=0x3f3f3f3f;
int dp[N][N];
int ti[N];
int main(){
    int n,q,i,j,k,b,a,l,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dp[i][j]=INF;
        }
    }
    for(i=0;i<n;i++){
        dp[i][i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&ti[i]);
    }
    ti[n]=INF;
    while(m--){
        scanf("%d %d %d",&i,&j,&a);
        dp[i][j]=min(dp[i][j],a);
        dp[j][i]=dp[i][j];
    }
    l = 0;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&k);
        while(ti[l]<=k){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
                }
            }
            l++;
        }
        if(a>=l || b>=l){cout<<-1<<endl;}
        else if(dp[a][b]==INF){cout<<-1<<endl;}
        else {cout<<dp[a][b]<<endl;}
    }
    return 0;
}