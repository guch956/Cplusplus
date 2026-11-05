#include<iostream>
#include<cstdio>
#define ll long long
const int N=100003;const ll mod=1e9+7;
int colour[N];
ll dp[N][4];
struct node{
    int to;
    int next;
};
node g[N<<1];int ent;
int head[N];
void addg(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs(int s,int fa){
    int i,v;
    dp[s][1]=1;dp[s][2]=1;dp[s][3]=1;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=fa){
            dfs(v,s);
            dp[s][1]= (dp[v][2]+dp[v][3])%mod*dp[s][1]%mod;
            dp[s][2]= (dp[v][1]+dp[v][3])%mod*dp[s][2]%mod;
            dp[s][3]= (dp[v][1]+dp[v][2])%mod*dp[s][3]%mod;
        }
    }
    if(colour[s]>0){
        for(i=1;i<=3;i++){
            if(i!=colour[s]){
                dp[s][i]=0;
            }
        }
    }
}
int main(){
    int n,a,b,k,i;
    ll x;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        addg(a,b);
        addg(b,a);
    }
    for(i=1;i<=k;i++){
        scanf("%d %d",&a,&b);
        colour[a]=b;
    }
    dfs(1,-1);
    x=0;
    for(i=1;i<=3;i++){
        x+=dp[1][i];
    }
    x = x%mod;
    printf("%lld",x);
    return 0;
}