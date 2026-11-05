#include<iostream>
#include<vector>
using namespace std;
int p[1503];
vector <int> g[1503];
int dp[1503][3];
int father[1503];
void dfs(int u){
    int i,s=0;
    for(i=0;i<g[u].size();i++){
        dfs(g[u][i]);
        dp[u][0] += min(dp[g[u][i]][1],dp[g[u][i]][2]);
        dp[u][2] += min(dp[g[u][i]][0],dp[g[u][i]][2]);
    }
    dp[u][2] += p[u];
    dp[u][1] = 2147483647;
    for(i=0;i<g[u].size();i++){
        dp[u][1] = min(dp[u][1],dp[u][0]+dp[g[u][i]][2]-min(dp[g[u][i]][1],dp[g[u][i]][2]));
    }
}
int main(){
    int n,i,a,x,j,m;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a;
        cin>>p[a];
        cin>>m;
        for(j=1;j<=m;j++){
            cin>>x;
            g[a].push_back(x);
            father[x] = a;
        }
    }
    j = 1;
    while(father[j]!=0){
        j = father[j];
    }
    dfs(j);
    cout<<min(dp[j][1],dp[j][2]);
    return 0;
}