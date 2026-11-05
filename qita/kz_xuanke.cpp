#include<iostream>
#include<vector>
using namespace std;
vector<int> g[1001];
int father[1001],xuefen[1001],dp[1001][1001],p[1001];
void dfs(int t,int k){
	if(k>=2){
		int i,j,l;
		for(i=0;i<g[t].size();i++){
			dfs(g[t][i],k-1);
		}
		for(j=k-1;j>=0;j--){
			p[j] = 0;
		}
		for(i=0;i<g[t].size();i++){
			for(j=k-1;j>=0;j--){
				for(l=0;l<=j;l++){
					p[j] = max(p[j],p[j-l]+dp[g[t][i]][l]);
				}
			}
		}
		for(i=2;i<=k;i++){
			dp[t][i] = xuefen[t]+p[i-1];
		}
	}
}
int main(){
	int n,i,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>father[i]>>xuefen[i];
		g[father[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		dp[i][1] = xuefen[i];
	}
	dfs(0,m);
	cout<<dp[0][m];
	return 0;
}