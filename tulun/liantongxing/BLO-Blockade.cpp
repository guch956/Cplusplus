#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
struct {
    int to;
    int next;
}g[N*10];
int head[N],ent=0;
ll siz[N],ans[N];
int dfm[N],low[N];
int dfn,n;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int v,i;
    ll child=s==f?1:0;
    dfm[s]=++dfn;
    low[s]=dfm[s];
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        if(dfm[v]){
            low[s]=min(low[s],dfm[v]);
        }
        else{
            dfs(v,s);
            siz[s]+=siz[v];
            low[s]=min(low[s],low[v]);
            if(low[v]>=dfm[s] && s!=f){
                ans[s]+=siz[v]*(n-siz[v]);
                child+=siz[v];
            }
            if(s==f){
                ans[s]+=siz[v]*child;
                child+=siz[v];
            }
        }
    }
    siz[s]++;
    if(s==f){ans[s]=ans[s]<<1;}        
    else{
        child++;
        ans[s]+=child*(n-child);
        ans[s]+=n-1;
    }
}
int main(){
    int m,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    for(m=1;m<=n;m++){
        printf("%lld\n",ans[m]);
    }
    return 0;
}
