#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
const ll INF=0x3f3f3f3f3f3f3f3f;
class tu{
    public:
        int head[N],to[N*5],nex[N*5],ent;
        ll len[N*5];
        void adde(int u,int v,ll l){
            ent++;
            to[ent]=v;
            len[ent]=l;
            nex[ent]=head[u];
            head[u]=ent;
        }
}g,g1;
int dfm[N],dfn,low[N];
int scc[N],sccn;
int zhan[N],top;
ll dp[N];
bool vis[N];
void dfs1(int s){
    int i,v;
    vis[s]=1;
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(!vis[v]){dfs1(v);}
        dp[s]=min(dp[s],dp[v]+g.len[i]);
    }
}
void dfs(int s){
    int i,v;
    zhan[++top]=s;
    dfm[s]=low[s]=++dfn;
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(!dfm[v]){
            dfs(v);
            low[s]=min(low[s],low[v]);
        }
        else if(!scc[v]){
            low[s]=min(low[s],low[v]);
        }
    }
    if(dfm[s]==low[s]){
        sccn++;
        while(1){
            scc[zhan[top]]=sccn;
            if(zhan[top--]==s){break;}
        }
    }
}
int main(){
    int n,m,i,a,b;
    ll c;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %lld",&a,&b,&c);
        g1.adde(a,b,c);
    }
    dfs(1);
    for(a=1;a<=n;a++){
        for(i=g1.head[a];i;i=g1.nex[i]){
            b = g1.to[i];
            if(scc[a]!=scc[b]){
                g.adde(scc[a],scc[b],g1.len[i]);
            }
        }
        dp[a]=INF;
    }
    dp[scc[n]]=0;
    dfs1(scc[1]);
    printf("%lld",dp[scc[1]]);
    return 0;
}