#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;const int N=101;
int g[N][N],n,ans;
int dp[N][N];
void floyd(){
    int i,j,k;
    ans = INF;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dp[i][j] = g[i][j];
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<k;i++){
            for(j=1;j<i;j++){
                if(g[k][i]<INF && g[k][j]<INF){
                    ans = min(ans,dp[i][j]+g[k][i]+g[k][j]);
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dp[i][j] = min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
}
int main(){
    int m,i,j,w,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            g[i][j] = INF;
        }
    }
    for(i=1;i<=m;i++){
        cin>>a>>b>>w;
        g[a][b] = min(g[a][b],w);
        g[b][a] = min(g[b][a],w);
    }
    floyd();
    if(ans==INF){
        cout<<"No solution.";
    }
    else{
        cout<<ans;
    }
    return 0;
}