#include<iostream>
#include<cstdio>
using namespace std;
const int N=200002;
#define ll long long
const ll mod=1000000007;
struct{
    int to;
    int next;
}g[N<<1];
int n;
int head[N],ent;
ll siz[N];
ll dp[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int v,i;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs1(v,s);
            dp[s]+=dp[v];
            dp[s]+=siz[v]*(siz[v]-1)/2;
            dp[s] = dp[s]%mod;
            siz[s]+=siz[v];
        }
    }
    siz[s]++;
}
void dfs2(int s,int f){
    int v,i;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dp[v]=dp[s];
            dp[v]+=(n-siz[v])*(n-siz[v]-1)/2;
            dp[v]-=siz[v]*(siz[v]-1)/2;
            dp[v]+=mod;
            dp[v]=dp[v]%mod;
            siz[s]=n-siz[v];
            siz[v]=n;
            dfs2(v,s);
            siz[s]=n;
        }
    }
}
int main(){
    int i,a,b;
    ll ans=0;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(i=1;i<=n;i++){
        ans+=dp[i];
    }
    ans = ans%mod;
    cout<<ans;
    return 0;
}