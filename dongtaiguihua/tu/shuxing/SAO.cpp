#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=1003;
const ll P=1e9+7;
ll jiec[N];
ll ni[N];
ll dp[N][N];
ll siz[N];
ll quick(ll x,ll d){
    ll a=x,ans=1;
    while(d){
        if(d&1){
            ans= (ans*a)%P;
        }
        a = (a*a)%P;
        d = d>>1;
    }
    return ans;
}
struct {
    int to;
    int next;
    bool fx;
}g[N<<1];
int head[N],ent;
void adde(int u,int v,bool a){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].fx=a;
    head[u]=ent;
}
void dfs(int s,int f,bool x){
    ll i,j;
    int v,si,a;
    memset(dp[s],0,sizeof(dp[s]));
    dp[s][1]=1;siz[s]=1;
    for(a=head[s];a;a=g[a].next){
        v = g[a].to;
        if(v==f){continue;}
        dfs(v,s,g[a].fx);
        si=siz[s]+siz[v];
        for(i=si;i>=1;i--){
            dp[s][i]=dp[s][i]*dp[v][0]%P*jiec[si-i]%P*ni[siz[s]-i]%P*ni[siz[v]]%P;
            for(j=max((ll)1,i-siz[s]);j<=min(i-1,siz[v]);j++){
                dp[s][i]+=dp[s][i-j]*dp[v][j]%P*jiec[i-1]%P*jiec[si-i]%P*ni[i-j-1]%P*ni[j]%P*ni[siz[v]-j]%P*ni[siz[s]-i+j]%P;
                dp[s][i]=dp[s][i]%P;
            }
        }
        siz[s]=si;
    }
    if(x){
        dp[s][0]=0;
        for(i=1;i<=siz[s];i++){
            dp[s][i]=(dp[s][i-1]+dp[s][i])%P;
        }
    }
    else{
        j = 0;
        for(i=siz[s];i>=0;i--){
            si=dp[s][i];
            dp[s][i]=(j+dp[s][i+1])%P;
            j=si;
        }
    }
}
int main(){
    int t;
    ll i,n;
    int a,b;
    char c;
    jiec[0]=1;
    ni[0]=1;
    for(i=1;i<N;i++){
        jiec[i]=(jiec[i-1]*i)%P;
        ni[i]=quick(jiec[i],P-2);
    }
    scanf("%d",&t);
    while(t--){
        memset(head,0,sizeof(head));
        ent=0;
        scanf("%lld",&n);
        for(i=1;i<n;i++){
            scanf("%d %c %d",&a,&c,&b);
            a++;b++;
            if(c=='<'){
                adde(a,b,0);
                adde(b,a,1);
            }
            else{
                adde(a,b,1);
                adde(b,a,0);
            }
        }
        dfs(1,0,1);
        printf("%lld\n",dp[1][n]);
    }
    return 0;
}
