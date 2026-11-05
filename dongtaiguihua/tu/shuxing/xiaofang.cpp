#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300003;
struct {
    int to;
    int next;
    ll w;
}g[N<<1];
int head[N],ent;
void adde(int u,int v,ll c){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].w = c;
    head[u]=ent;
}
ll len[N],deep[N];
int fa[N],son[N];
int gen=1,gen1;
ll zhijing,ans=0,lenth;
void dfs1(int s,int f){
    int v,i;
    for(i = head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        deep[v] = deep[s]+g[i].w;
        if(deep[v]>=deep[gen]){gen = v;}
        dfs1(v,s);
    }
}
void dfs2(int s,int f){
    int v,i;
    ll l;
    fa[s] = f;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        deep[v] = deep[s]+g[i].w;
        if(deep[v]>=deep[gen1]){
            gen1=v;
            zhijing = max(zhijing,deep[v]);
        }
        dfs2(v,s);
        l = len[v]+g[i].w;
        if(l>=len[s]){
            ans = max(ans,len[s]);
            len[s] = l;
            son[s] = v;
        }
        else if(l>ans){ans = l;}
    }
}
void jisuan(){
    while(deep[gen]+len[gen1]+lenth<zhijing){
        if(deep[son[gen]]<len[fa[gen1]]){
            gen = son[gen];
        }
        else{
            gen1 = fa[gen1];
        }
    }
    ans = max(max(ans,deep[gen]),len[gen1]);
}
int main(){
    int n,i,a,b;
    ll c;
    scanf("%d %lld",&n,&lenth);
    for(i=1;i<=n-1;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dfs1(1,1);
    gen1 = gen;
    deep[gen]=0;
    dfs2(gen,gen);
    jisuan();
    printf("%lld",ans);
    return 0;
}
