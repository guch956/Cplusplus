#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int head[N],to[N<<1],nex[N<<1];
int vis[N];
int sta[N];
int ans,ent;
void adde(int u,int v){
	ent++;
	to[ent]=v;
	nex[ent]=head[u];
	head[u]=ent;
}
void dfs(int s){
	ans++;
	vis[s]=1;
	int i;
	for(i=head[s];i;i=nex[i]){
		if(vis[to[i]]==0){
			dfs(to[i]);
		}
	}
}
int main(){
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&a,&b);
		if(a==0){
			sta[i]=1;
			continue;
		}
		adde(a,i);
		adde(b,i);
	}
	for(i=1;i<=n;i++){
		if(sta[i])dfs(i);
	}
	printf("%d",ans);
	return 0;
}
