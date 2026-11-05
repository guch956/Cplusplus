#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
const ll P=1e9+7;
char c[N];
ll dp[N][3];
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
void dfs(int s,int f){
    int i,v;
    dp[s][0]=1;
    if(c[s]=='a'){dp[s][1]=1;}
    else{dp[s][2]=1;}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs(v,s);
        dp[s][0]=dp[s][0]*(2*dp[v][0]+dp[v][1]+dp[v][2])%P;
        dp[s][1]=dp[s][1]*(dp[v][0]+dp[v][1])%P;
        dp[s][2]=dp[s][2]*(dp[v][0]+dp[v][2])%P;
    }
    dp[s][0]=(dp[s][0]-dp[s][1]-dp[s][2]+2*P)%P;
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        cin>>c[i];
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,0);
    printf("%lld",dp[1][0]);
    return 0;
}