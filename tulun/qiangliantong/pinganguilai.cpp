#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
const int INF=0x3f3f3f3f;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
int low[N],dfm[N],dfn;
int scc;
ll w[N];
int zhan[N],top;
int sccn[N];
int n;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void tarjan(int s){
    int v,i;
    dfm[s]=++dfn;
    low[s]=dfm[s];
    zhan[++top]=s;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(!dfm[v]){
            tarjan(v);
            low[s]=min(low[s],low[v]);
        }
        else if(!sccn[v]){
            low[s]=min(low[s],dfm[v]);
        }
    }
    if(dfm[s]==low[s]){
        scc++;
        while(1){
            v = zhan[top--];
            sccn[v]=scc;
            w[scc]++;
            if(v==s){break;}
        }
    }
}
void suodian(){
    int i;
    ll ans=0;
    for(i=1;i<=n;i++){
        if(!dfm[i]){
            tarjan(i);
        }
    }
    for(i=1;i<=scc;i++){
        ans+=w[i]*(w[i]-1)/2;
    }
    printf("%lld",ans);
}
int main(){
    int m,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    suodian();
    return 0;
}