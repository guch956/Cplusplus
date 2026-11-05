#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=500003;
const ll P=1000000007;
struct {
    int to;
    int next;
}g[N<<2],g1[N<<1];
ll power2[N<<1],ni2[N<<1];
int head[N],ent=0;
int head1[N],ent1;
ll dp0[N],siz[N],dfn;
ll dp1[N];
int sccn[N];
int zhan[N],top;
int scc;
int w[N];
void adde(int u,int v){
    ent++;
    g[ent].next=head[u];
    g[ent].to=v;
    head[u]=ent;
}
void adde1(int u,int v){
    ent1++;
    g1[ent1].next=head1[u];
    g1[ent1].to=v;
    head1[u]=ent1;
}
void tarjan(int s,int f){
    int v,i;
    dp0[s]=++dfn;
    siz[s]=dp0[s];
    zhan[++top]=s;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        if(dp0[v]){
            siz[s]=min(siz[s],dp0[v]);
        }
        else{
            tarjan(v,s);
            siz[s]=min(siz[s],siz[v]);
        }
    }
    if(siz[s]==dp0[s]){
        scc++;
        while(zhan[top]!=s){
            sccn[zhan[top]]=scc;
            w[scc]++;
            top--;
        }
        w[scc]++;
        top--;
        sccn[s]=scc;
    }
}
void dfs(int s,int f){
    int i,v;
    ll ji=1,sum=0;
    siz[s]=0;
    for(i=head1[s];i;i=g1[i].next){
        v = g1[i].to;
        if(v==f){continue;}
        dfs(v,s);
        siz[s]+=siz[v]+1;
        ji *= (1+((dp1[v]*ni2[siz[v]+1])%P));
        ji = ji%P;
        sum+=dp0[v]*ni2[siz[v]]-dp1[v]*ni2[siz[v]+1];
        sum = ((sum%P)+P)%P;
    }
    ji = ji*power2[w[s]+siz[s]]%P;
    sum = sum*power2[siz[s]]%P;
    dp0[s]=(ji+sum-power2[siz[s]]+P)%P;
    dp1[s]=(ji-power2[siz[s]]+P)%P;
}
int main(){
    int n,m,i,a,b;
    ll ans;
    scanf("%d %d",&n,&m);
    power2[0]=ni2[0]=1;
    ni2[1]=(1+P)>>1;
    for(i=1;i<=m;i++){
        power2[i]=(power2[i-1]<<1)%P;
        ni2[i]=(ni2[i-1]*ni2[1])%P;
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    power2[m+1]=(power2[m]<<1)%P;
    tarjan(1,1);
    for(a=1;a<=n;a++){
        for(i=head[a];i;i=g[i].next){
            b = g[i].to;
            if(sccn[a]!=sccn[b]){
                adde1(sccn[a],sccn[b]);
            }
        }
    }
    dfs(1,1);
    ans=dp0[1]*power2[m-scc+1]%P;
    printf("%lld",ans);
    return 0;
}
