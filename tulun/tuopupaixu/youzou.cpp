#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=998244353;
const int N=100003;
ll num[N];
ll sum[N];
bool vis[N];
int to[N*7],nex[N*7],head[N],ent;
ll power(ll a,ll x){
    ll an=1;
    while(x){
        if(x&1){an = an*a%P;}
        a = a*a%P;
        x = x>>1;
    }
    return an;
}
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s){
    int i;
    vis[s]=1;
    num[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(!vis[to[i]]){
            dfs(to[i]);
        }
        num[s]=(num[s]+num[to[i]])%P;
        sum[s]=(sum[s]+sum[to[i]]+num[to[i]])%P;
    }
}
int main(){
    int n,m,i,a,b;
    ll s=0,g=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){dfs(i);}
        s+=sum[i];
        g+=num[i];
    }
    s = s%P;g = g%P;
    s = s*power(g,P-2)%P;
    printf("%lld",s);
    return 0;
}
