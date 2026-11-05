#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int head[N],to[N],nex[N],ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int xuhao[N],top;
int vis[N];
void dfs(int s){
    int i;
    vis[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(!vis[to[i]]){dfs(to[i]);}
    }
    xuhao[s]=++top;
}
int main(){
    int n,m1,m2,i,a,b;
    scanf("%d %d %d",&n,&m1,&m2);
    for(i=1;i<=m1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){dfs(i);}
    }
    for(i=1;i<=m2;i++){
        scanf("%d %d",&a,&b);
        if(xuhao[a]<xuhao[b]){swap(a,b);}
        printf("%d %d\n",a,b);
    }
    return 0;
}