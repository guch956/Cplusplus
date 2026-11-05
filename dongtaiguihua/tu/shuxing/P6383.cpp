#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 3003;
const ll P = 998244353;
ll dp[N][N];
int head[N];
int to[N<<1];
int nex[N<<1];
int ent;
int deep[N];
void adde(int a,int b){
    ent++;
    to[ent] = b;
    nex[ent] = head[a];
    head[a] = ent;
}
void dfs(int s,int f){
    int i,j;
    deep[s] = deep[f]+1;
    for(j=1;j<=deep[s];j++){
        dp[s][j] = 1;
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f)continue;
        dfs(to[i],s);
        for(j=1;j<=deep[s];j++){
            dp[s][j] = dp[s][j]*dp[to[i]][j+1]%P;
        }
    }
    for(j=2;j<=deep[s];j++){
        dp[s][j] = (dp[s][j]+dp[s][j-1])%P;
    }
}
int main(){
    int n,i,a,b;
    ll ans = 1;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=head[n];i;i=nex[i]){
        dfs(to[i],n);
        ans = ans*dp[to[i]][1]%P;
    }
    printf("%lld",ans);
    return 0;
}