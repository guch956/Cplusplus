#include<iostream>
#include<cstdio>
using namespace std;
const int N=300002;
struct edge
{
    int to;
    int next;
};
edge g[N<<1];int head[N],ent=1;
int n;
int dmax[N],leafs[N];
bool daxiao[N];
void addedge(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
void dfs(int s,int fa){
    int i,v,a;
    if(daxiao[s]){
        a = -0x3f3f3f3f;
        for(i=head[s];i;i=g[i].next){
            v = g[i].to;
            if(v!=fa){
                dfs(v,s);
                leafs[s]+=leafs[v];
                a = max(a,dmax[v]-leafs[v]);
            }
        }
        dmax[s]=leafs[s]+a;
    }
    else{
        for(i=head[s];i;i=g[i].next){
            v = g[i].to;
            if(v!=fa){
                dfs(v,s);
                leafs[s]+=leafs[v];
                dmax[s]+=dmax[v]-1;
            }
        }
        dmax[s]++;
    }
    if(leafs[s]==0){
        leafs[s]=1;
        dmax[s]=1;
    }
}
int main(){
    int n,i,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&daxiao[i]);
    }
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        addedge(i,a);
        addedge(a,i);
    }
    dfs(1,-1);
    printf("%d",dmax[1]);
    return 0;
}
