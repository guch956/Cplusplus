#include<iostream>
#include<vector>
using namespace std;
vector<int> g[1500];
int dp[1500][2];
void dfs(int u,int fa){
    int i,s=0,s2=0;
    for(i=0;i<g[u].size();i++){
        if(g[u][i]!=fa){
            dfs(g[u][i],u);
            s+=min(dp[g[u][i]][0],dp[g[u][i]][1]);
            s2+=dp[g[u][i]][1];
        }
    }
    s++;
    dp[u][1] = s;
    dp[u][0] = s2;
}
int main(){
    int n,a,i,j,m,x;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        cin>>m;
        for(j=0;j<m;j++){
            cin>>x;
            g[a].push_back(x);
            g[x].push_back(a);
        }
    }
    dfs(0,-1);
    cout<<min(dp[0][0],dp[0][1]);
    return 0;
}