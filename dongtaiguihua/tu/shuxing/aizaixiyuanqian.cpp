#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
ll dp[N][3];
ll ans;
ll p[N];
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int i,v;
    dp[s][1]=p[s];
    dp[s][2]=1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
        dp[s][0]+=max(dp[v][0],dp[v][1]);
        dp[s][1]+=dp[v][0];
        if(dp[v][1]>dp[v][0]){
            dp[s][2]+=dp[v][2];
        }
    }
}
void dfs2(int s,int f){
    int i,v;
    ll dp0,dp1,dp2;
    ans=max(ans,dp[s][0]==dp[s][1]?0:dp[s][2]);
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dp0=dp[s][0]-max(dp[v][0],dp[v][1]);
        dp1=dp[s][1]-dp[v][0];
        dp2=dp[s][2]-(dp[v][1]>dp[v][0]?dp[v][2]:0);
        dp[v][0]+=max(dp0,dp1);
        dp[v][1]+=dp0;
        dp[v][2]+=dp1>dp0?dp2:0;
        dfs2(v,s);
    }
}
int main(){
    int n,t,i,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&p[i]);
        }
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        dfs1(1,0);
        dfs2(1,0);
        for(i=1;i<=n;i++){
            dp[i][0]=dp[i][1]=dp[i][2]=0;
            head[i]=0;
        }
        ent=0;
        printf("%lld\n",ans);
    }
    return 0;
}
