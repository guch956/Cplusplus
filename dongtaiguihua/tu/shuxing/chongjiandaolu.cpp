#include<iostream>
#include<cstdio>
using namespace std;
const int N=200;
int dp[N][N];
int n,p;
const int INF=0x3f3f3f;
struct {
    int to;
    int next;
}g[N<<2];
int head[N],ent=1;
void adde(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
void dfs(int s,int f){
    int v,i,j,k;
    for(i=2;i<=n;i++){
        dp[s][i]=INF;
    }
    dp[s][1]=0;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs(v,s);
            for(j=n;j>=1;j--){
                dp[s][j]++;
                for(k=j-1;k>=1;k--){
                    dp[s][j]=min(dp[s][j],dp[s][j-k]+dp[v][k]);
                }
            }
        }
    }
}
int main(){
    int i,a,b;
    scanf("%d %d",&n,&p);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    a = dp[1][p];
    for(i=2;i<=n;i++){
        a = min(a,dp[i][p]+1);
    }
    printf("%d",a);
    return 0;
}