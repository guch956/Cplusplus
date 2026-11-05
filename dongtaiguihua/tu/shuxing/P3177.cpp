#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=2003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[N][N];
ll siz[N];
int n;
ll k,q;
int head[N],nex[N<<1],to[N<<1],len[N<<1],ent;
void adde(int u,int v,ll l){
    ent++;
    to[ent]=v;
    len[ent]=l;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    ll t1,t2,p1,p2,t;
    siz[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f)continue;
        dfs(to[i],s);
        for(t=min(siz[s]+siz[to[i]],k);t>=0;t--){
            for(t2=max((ll)0,t-siz[s]);t2<=siz[to[i]];t2++){
                t1 = t-t2;
                if(t1<0)break;
                p1 = siz[s]-t1;
                p2 = siz[to[i]]-t2;
                dp[s][t]=max(dp[s][t],dp[s][t1]+dp[to[i]][t2]+(t2*(k-t2)+p2*(q-p2))*len[i]);
            }
        }
        siz[s]+=siz[to[i]];
    }
}
int main(){
    int i,a,b;
    ll c;
    scanf("%d %lld",&n,&k);
    q = n-k;
    for(i=1;i<n;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dfs(1,1);
    printf("%lld",dp[1][k]);
    return 0;
}