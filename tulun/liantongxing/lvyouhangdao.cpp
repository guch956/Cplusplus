#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=30003;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent=-1;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int dfm[N],low[N],ans,dfn;
void dfs(int s,int e){
    int i,v;
    dfm[s]=++dfn;
    low[s]=dfm[s];
    for(i=head[s];i!=-1;i=g[i].next){
        if(i==(e^1)){continue;}
        v = g[i].to;
        if(!dfm[v]){
            dfs(v,i);
            if(low[v]==dfm[v]){
                ans++;
            }
        }
        low[s]=min(low[s],low[v]);
    }
}
int main(){
    int n,m,i,a,b;
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0){break;}
        memset(head,-1,sizeof(head));
        memset(dfm,0,sizeof(dfm));
        ans=0;
        ent=-1;
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        dfs(1,1000000);
        printf("%d\n",ans);
    }
    return 0;
}