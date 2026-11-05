#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[N][3];
int head[N],to[N<<1],nex[N<<1],ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
ll val[N];
class zhan
{
private:
    ll A[12];
public:
    int k;
    void init(){
        for(int i=1;i<=k;i++)A[i]=-INF;
    }
    void add(ll x){
        if(x>A[k]){
            int i;
            for(i=k-1;i>=1;i--){
                if(x<=A[i]){break;}
                A[i+1]=A[i];
            }
            A[i+1]=x;
        }
    }
    ll get(int t){
        ll ans=0;
        for(int i=1;i<=k-t;i++){
            if(A[i]>0)ans+=A[i];
        }
        return ans;
    }
}p;
void dfs(int s,int f){
    int i;
    dp[s][1]=val[s];
    dp[s][0]=0;/*父亲选*/
    dp[s][2]=0;/*父亲不选*/
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
    }
    p.init();
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dp[s][1]+=dp[to[i]][0];
        dp[s][0]+=dp[to[i]][2];
        dp[s][2]+=dp[to[i]][2];
        p.add(dp[to[i]][1]-dp[to[i]][2]);
    }
    dp[s][0]+=p.get(1);
    dp[s][2]+=p.get(0);
}
int main(){
    int n,m,i,a,b;
    ll ans=0;
    scanf("%d %d %d",&n,&m,&p.k);
    for(i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=1;i<=n;i++){
        if(dp[i][1]==0){
            dfs(i,0);
            ans+=max(dp[i][1],dp[i][2]);
        }
    }
    printf("%lld",ans);
    return 0;
}