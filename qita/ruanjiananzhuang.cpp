#include<iostream>
#include<vector>
using namespace std;
vector <int> g[101];
int w[101],v[101],m;
int dp[101][501],p[501];
void dfs(int u,int r){
    if(r>=w[u]){
        int i,r1 = r-w[u],j,k,s=0;
        for(i=0;i<=r1;i++){
            p[i]=0;
        }
        for(i=0;i<g[u].size();i++){
            dfs(g[u][i],r1);
            for(j=r1;j>=0;j--){
                for(k=0;k<=j;k++){
                    p[j] = max(p[j],dp[g[u][i]][k]+p[j-k]);
                }
            }
        }
        for(j=w[u];j<=r;j++){
            dp[u][j] = p[j-w[u]]+v[u];
        }
    }
}
int main(){
    int n,i,a;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>w[i];
    }
    for(i=1;i<=n;i++){
        cin>>v[i];
    }
    for(i=1;i<=n;i++){
        cin>>a;
        g[a].push_back(i);
    }
    dfs(0,m);
    cout<<dp[0][m];
    return 0;
}