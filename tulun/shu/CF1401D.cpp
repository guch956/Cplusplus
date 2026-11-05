#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
const ll P=1e9+7;
ll pri[N];
ll num[N],top;
ll siz[N];
int head[N],to[N<<1],nex[N<<1],ent;
int n;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    siz[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        siz[s]+=siz[to[i]];
    }
    num[++top]=siz[s]*(n-siz[s]);
}
int main(){
    int i,a,b,T,m;
    ll ans,chengji;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans = 0;top = 0;
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%lld",&pri[i]);
        }
        sort(pri+1,pri+m+1,greater<ll>());
        dfs(1,1);
        sort(num+1,num+n,greater<ll>());
        if(m<=n-1){
            for(i=1;i<=m;i++){
                ans = (num[i]*pri[i]%P+ans)%P;
            }
            for(i=m+1;i<n;i++){
                ans = (ans+num[i])%P;
            }
        }
        else{
            chengji=1;
            for(i=1;i<=m-n+2;i++){
                chengji=pri[i]*chengji%P;
            }
            ans = chengji*num[1]%P;
            for(i=2;i<n;i++){
                ans = (num[i]*pri[i+m-n+1]%P+ans)%P;
            }
        }
        printf("%lld\n",ans);
        for(i=1;i<=n;i++){head[i]=0;}
        ent=0;
    }
    return 0;
}