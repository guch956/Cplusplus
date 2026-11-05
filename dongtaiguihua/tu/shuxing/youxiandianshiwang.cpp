#include<iostream>
#include<cstdio>
using namespace std;
const int N=3003,INF=0x3f3f3f3f;
int dp[N][N];
int n,m;
struct {
    int to;
    int next;
    int len;
}g[N];
int head[N],ent;
int money[N],yezi[N];
void adde(int a,int b,int c){
    ent++;
    g[ent].to=b;
    g[ent].next=head[a];
    g[ent].len=c;
    head[a]=ent;
}
void dfs(int s){
    int v,i,j,k;
    if(s>=n-m+1){
        dp[s][1]=money[s];
        yezi[s]=1;
        return ;
    }
    for(i=1;i<=m;i++){
        dp[s][i]=-INF;
    }
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        dfs(v);
        yezi[s]+=yezi[v];
        for(j=yezi[s];j>=0;j--){
            for(k=1;k<=yezi[v];k++){
                dp[s][j]=max(dp[s][j],dp[s][j-k]+dp[v][k]-g[i].len);
            }
        }
    }
}
int main(){
    int i,k,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n-m;i++){
        scanf("%d",&k);
        while(k){
            scanf("%d %d",&a,&b);
            adde(i,a,b);
            k--;
        }
    }
    for(i=n-m+1;i<=n;i++){
        scanf("%d",&money[i]);
    }
    dfs(1);
    for(i=m;i>=0;i--){
        if(dp[1][i]>=0){
            cout<<i;
            return 0;
        }
    }
}