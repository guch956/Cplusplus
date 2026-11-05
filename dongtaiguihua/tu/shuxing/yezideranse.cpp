#include<iostream>
#include<cstdio>
const int N=10002;
const int INF=0x3f3f3f3f;
using namespace std;
struct{
    int to;
    int next;
}g[N<<1];
int n;
int head[N],ent=1;
int c[N];
int dp[N][2];
int yezishu;
void adde(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
int ans=INF;
void dfs1(int s,int f){
    int i,v;
    if(s<=yezishu){
        if(c[s]==0){
            dp[s][0]=1;
            dp[s][1]=INF;
        }
        else{
            dp[s][1]=1;
            dp[s][0]=INF;
        }
    }
    else{
        for(i=head[s];i!=0;i=g[i].next){
            v = g[i].to;
            if(v!=f){
                dfs1(v,s);
                dp[s][1]+=min(dp[v][0],dp[v][1]-1);
                dp[s][0]+=min(dp[v][0]-1,dp[v][1]);
            }
        }
        dp[s][1]++;
        dp[s][0]++;
    }
}
void dfs2(int s,int f){
    int i,v;
    if(s>yezishu){
        dp[f][0]-=min(dp[s][0]-1,dp[s][1]);
        dp[f][1]-=min(dp[s][0],dp[s][1]-1);
        dp[s][0]+=min(dp[f][0]-1,dp[f][1]);
        dp[s][1]+=min(dp[f][0],dp[f][1]-1);
        ans=min(ans,min(dp[s][0],dp[s][1]));
        for(i=head[s];i!=0;i=g[i].next){
            v = g[i].to;
            if(v!=f){
                dfs2(v,s);
            }
        }
        dp[s][0]-=min(dp[f][0]-1,dp[f][1]);
        dp[s][1]-=min(dp[f][0],dp[f][1]-1);
        dp[f][0]+=min(dp[s][0]-1,dp[s][1]);
        dp[f][1]+=min(dp[s][0],dp[s][1]-1);
    }
}
int main(){
    int i,a,b,v,u;
    scanf("%d %d",&n,&yezishu);
    for(i=1;i<=yezishu;i++){
        scanf("%d",&c[i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    u = yezishu+1;
    dfs1(u,u);
    ans=min(ans,min(dp[u][0],dp[u][1]));
    for(i=head[u];i!=0;i=g[i].next){
        v = g[i].to;
        dfs2(v,u);
    }
    printf("%d\n",ans);
    return 0;
}