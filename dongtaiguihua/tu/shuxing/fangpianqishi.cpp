#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000003;
const int INF=0x3f3f3f3f;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int dp[N];
int p[N];
int LOG2[N];
void dfs1(int s,int f){
    int v,i,num=0,a=1;
    dp[s] = INF;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
    }
    p[0]=0;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        p[num]=dp[v];
        num++;
    }
    if(num>=2){
        sort(p,p+num);
        for(i=0;i<LOG2[num];i++){
            dp[s] = min(dp[s],max(i+p[num-1],LOG2[num-a]+p[num-a-1]));
            a = a<<1;
        }
        dp[s]++;
    }
    else{dp[s]=p[0]+1;}
}
int main(){
    int n,i,a,b,nmax=1;
    int T,ans;
    freopen("4.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        ent=0;
        ans=INF;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            head[i]=0;
        }
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        for(i=nmax+1;i<=n;i++){
            LOG2[i] = LOG2[(i+1)>>1]+1;
        }
        nmax = max(n,nmax);
        for(i=1;i<=n;i++){
            dfs1(i,0);
            ans = min(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}