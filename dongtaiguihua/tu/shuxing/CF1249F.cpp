#include<iostream>
#include<cstdio>
using namespace std;
const int N=203;
const int INF=0x3f3f3f3f;
int dp[N][N];
int head[N],nex[N<<1],to[N<<1],ent;
int val[N];
int k,n;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i,t,j,sum,ma;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        dp[s][0]+=dp[to[i]][k];
    }
    dp[s][0]+=val[s];
    for(t=1;2*t<=k;t++){
        sum=0;ma=-INF;
        for(i=head[s];i;i=nex[i]){
            if(to[i]==f){continue;}
            sum+=dp[to[i]][k-t];
            ma = max(ma,dp[to[i]][t-1]-dp[to[i]][k-t]);
        }
        sum = sum+ma;
        dp[s][t]=max(dp[s][t],sum);
    }
    for(t=k/2+1;t<=n;t++){
        sum = 0;
        for(i=head[s];i;i=nex[i]){
            if(to[i]==f){continue;}
            sum+=dp[to[i]][t-1];
        }
        dp[s][t]=max(dp[s][t],sum);
    }
    for(t=n-1;t>=0;t--){
        dp[s][t]=max(dp[s][t],dp[s][t+1]);
    }
}
int main(){
    int i,a,b;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    printf("%d",dp[1][0]);
    return 0;
}