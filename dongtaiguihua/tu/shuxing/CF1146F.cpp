#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=200003;
int to[N];
int head[N];
int nex[N];
ll dp[N][2];
int ent;
const ll P=998244353;
void adde(int a,int b){
    ent++;
    to[ent] = b;
    nex[ent] = head[a];
    head[a] = ent; 
}
void dfs(int s){
    int i;
    ll d = 1;
    dp[s][1] = 1;
    if(head[s]==0){
        dp[s][0] = 1;return ;
    }
    for(i=head[s];i;i=nex[i]){
        dfs(to[i]);
        dp[s][1] = dp[s][1]*(dp[to[i]][0]+dp[to[i]][1])%P;
        dp[s][0] = dp[s][0]*dp[to[i]][0]%P;
        dp[s][0] = (dp[s][0]+d*dp[to[i]][1])%P;
        d = d*dp[to[i]][0]%P;
    }
    dp[s][0] = (P-dp[s][0]+dp[s][1])%P;
    dp[s][1] = (dp[s][1]-d+P)%P;
}
int main(){
    int n,i,a;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        adde(a,i);
    }
    dfs(1);
    printf("%lld",dp[1][0]);
    return 0;
}