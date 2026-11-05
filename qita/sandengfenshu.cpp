#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
struct 
{
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
int w[N];
int sum;
ll sum31[N];
ll ans;
void dfs(int s,int f){
    int v,i;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs(v,s);
        w[s]+=w[v];
    }
}
void dfs1(int s,int f){
    int v,i;
    ll num=0;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
        ans+= sum31[s]*sum31[v];
        sum31[s]+=sum31[v];
    }
    if(3*w[s]==2*sum){
        ans+=sum31[s];
    }
    if(3*w[s]==sum){sum31[s]++;}
}
int main(){
    int n,s,i,a;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&w[i],&a);
        if(a==0){s = i;}
        else{
            adde(i,a);
            adde(a,i);
        }
        sum+=w[i];
    }
    dfs(s,0);
    dfs1(s,0);
    printf("%lld",ans);
    return 0;
}

