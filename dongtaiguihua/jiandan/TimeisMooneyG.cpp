#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1003;
const ll INF=0x3f3f3f3f3f3f3f3f;
int nex[N<<1],to[N<<1],head[N],ent;
ll dp[N][2];
ll c[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int main(){
    int i,n,m,a,k=0,b,now=1,old=0,j;
    ll cc,ans=0;
    scanf("%d %d %lld",&n,&m,&cc);
    for(i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        k = max(k,(int)c[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    dp[1][0]=0;
    for(i=2;i<=n;i++){dp[i][0]=-INF;}
    for(j=1;j<=k;j++){
        for(i=1;i<=n;i++){dp[i][now]=-INF;}
        for(i=1;i<=n;i++){
            for(a=head[i];a;a=nex[a]){
                dp[to[a]][now]=max(dp[to[a]][now],dp[i][old]+c[to[a]]);
            }
        }
        ans = max(ans,dp[1][now]-cc*j*j);
        swap(now,old);
    }
    cout<<ans;
    return 0;
}