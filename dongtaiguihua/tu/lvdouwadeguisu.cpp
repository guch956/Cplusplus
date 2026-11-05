#include<iostream>
#include<cstdio>
using namespace std;
const int N=100004;
struct {
    int to;
    int next;
    double w;
}g[N<<1];
int head[N],ent=1;
bool done[N];
double dp[N];
void adde(int u,int v,double w){
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].w=w;
    head[u]=ent;
    ent++;
}
void dfs(int s){
    int v,i,k=0;
    done[s]=1;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(done[v]==0){
            dfs(v);
        }
        dp[s]+=dp[v];
        dp[s]+=g[i].w;
        k++;
    }
    if(k!=0){
        dp[s]=dp[s]/k;
    }
}
int main(){
    int n,m,i,a,b;
    double c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %lf",&a,&b,&c);
        adde(a,b,c);
    }
    dfs(1);
    printf("%.2lf",dp[1]);
    return 0;

}