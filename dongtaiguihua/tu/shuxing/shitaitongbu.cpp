#include<iostream>
#include<cstdio>
using namespace std;
const int N=500002;
#define ll long long
struct{
    int to;
    int next;
    ll len;
}g[N<<2];
int head[N],ent;
ll dp[N],ma[N],ans;
void adde(int a,int b,ll c){
    ent++;
    g[ent].to=b;
    g[ent].next=head[a];
    g[ent].len=c;
    head[a]=ent;
}
void dfs1(int s,int f){
    int v,i;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
        ma[s]=max(ma[s],ma[v]+g[i].len);
    }
}
void dfs2(int s,int f,ll sum){
    int v,i;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        ans+= sum-ma[v]-g[i].len;
        dfs2(v,s,ma[v]);
    }
}
int main(){
    int n,i,g,a,b;
    ll c;
    scanf("%d",&n);
    scanf("%d",&g);
    for(i=1;i<n;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dfs1(g,g);
    dfs2(g,g,ma[g]);
    printf("%lld",ans);
    return 0;
}