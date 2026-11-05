#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct {
    int to;
    int next;
    ll len;
}g[N<<1];
int head[N],ent;
void adde(int u,int v,ll c){
    ent++;
    g[ent].to=v;
    g[ent].len=c;
    g[ent].next=head[u];
    head[u]=ent;
}
ll dp[N][2],max1[N],max2[N];
int xiabiao[N];
ll ans;
void update(ll a,int s,int v){
    if(a>max1[s]){
        max2[s]=max1[s];
        max1[s] = a;
        xiabiao[s] = v;
    }
    else if(a>max2[s]){
        max2[s] = a;
    }
}
void dfs1(int s,int f){
    int v,i;
    ll a;
    dp[s][1]=-INF;
    max1[s]=max2[s]=-INF;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
        dp[s][0]+=max(dp[v][0],g[i].len+dp[v][1]);
        a = g[i].len+dp[v][0]-max(dp[v][0],dp[v][1]+g[i].len);
        update(a,s,v);
    }
    dp[s][1] = dp[s][0]+max1[s];
}
void dfs2(int s,int f){
    int v,i;
    ll dps0,dps1,a;
    ans = max(ans,dp[s][0]);
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dps0 = dp[s][0]-max(dp[v][0],dp[v][1]+g[i].len);
        dps1 = dps0+(v==xiabiao[s]?max2[s]:max1[s]);
        dp[v][0]+=max(dps0,dps1+g[i].len);
        a = g[i].len+dps0-max(dps0,dps1+g[i].len);
        update(a,v,s);
        dfs2(v,s);
    }
}
int main(){
    int n,i,a,b;
    ll c;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dfs1(1,1);
    dfs2(1,1);
    printf("%lld",ans);
    return 0;
}