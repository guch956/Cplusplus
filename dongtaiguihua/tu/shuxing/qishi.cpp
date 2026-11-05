#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
struct {
    int to;
    int next;
}g[N<<2];
int head[N],ent=1;
ll dp[N][2];
int e1,e2,f1,f2;
ll w[N];bool done[N];
void adde(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
void dfs(int s){
    int v,i,f;
    if(done[s]){
        f1=e1;
        f2=e2;
        return ;
    }
    done[s]=1;
    f = e2;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(i != f){
            e1 = i;
            e2 = e1%2==0?e1-1:e1+1 ;
            dfs(v);
        }
    }
}
void jisuan(int s,int f){
    int i,v;
    dp[s][1]=dp[s][0]=0;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f && i!=f1 && i!=f2){
            jisuan(v,s);
            dp[s][1]+=dp[v][0];
            dp[s][0]+=max(dp[v][0],dp[v][1]);
        }
    }
    dp[s][1]+=w[s];
}
int main(){
    int n,i,a;
    ll b;
    ll ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %d",&w[i],&a);
        adde(i,a);
        adde(a,i);
    }
    for(i=1;i<=n;i++){
        if(done[i]==0){
            dfs(i);
            a = g[f1].to;
            jisuan(a,0);
            b = dp[a][0];
            a = g[f2].to;
            jisuan(a,0);
            ans+= max(b,dp[a][0]);
        }
    }
    printf("%lld",ans);
    return 0;
}