#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=200003;
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
ll siz[N],dp[N][2];
void dfs(int s,int f){
    int v,i;
    ll min1=INF,min2=INF,masiz=0,m;
    siz[s]=1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs(v,s);
        siz[s]+=siz[v];
        masiz=max(masiz,siz[v]);
        dp[s][0]+=dp[v][0];
        dp[s][1]+=dp[v][0];
        m = dp[v][1]-dp[v][0]-siz[v];
        if(m<min1){
            min2=min1;
            min1=m;
        }
        else if(m<min2){min2=m;}
    }
    if(min1==INF){
        dp[s][0]=2;
        dp[s][1]=1;
    }
    else{
        dp[s][0]+=min(min1+min2,-2*masiz);
        dp[s][0]+=2*siz[s];
        dp[s][1]=dp[s][1]+min1+siz[s];
    }
}
int main(){
    int n,i,a;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        adde(i,a);
        adde(a,i);
    }
    dfs(1,0);
    printf("%lld",dp[1][0]);
    return 0;
}