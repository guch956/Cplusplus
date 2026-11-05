#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int to;
    int next;
}g[N<<2];
int head[N],ent=1;
int dp[N][2][2];
int done[N];
int s1[2];
int k;
int zhi[N];
void adde(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
void dfs(int s,int f){
    int v,i;
    if(done[s]==1){
        s1[0]=s;
        s1[1]=f;
        return ;
    }
    done[s]=1;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs(v,s);
        }
    }
}
void jisuan(int s,int f){
    int i,v;
    dp[s][1][k]+=zhi[s];
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f && v!=s1[k]){
            jisuan(v,s);
            dp[s][0][k]+=max(dp[v][0][k],dp[v][1][k]);
            dp[s][1][k]+=dp[v][0][k];
        }
    }
}
int main(){
    double p,ans;
    int n,a,b,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&zhi[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        a++;b++;
        adde(a,b);
        adde(b,a);
    }
    scanf("%lf",&p);
    dfs(1,1);
    k = 0;
    jisuan(s1[k],s1[1-k]);
    k = 1;
    jisuan(s1[k],s1[1-k]);
    ans=max(dp[s1[0]][0][0],dp[s1[1]][0][1])*p;
    printf("%.1lf",ans);
    return 0;
}

