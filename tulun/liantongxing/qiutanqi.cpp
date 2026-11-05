#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
struct {
    int to;
    int next;
}g[N*5];
int head[N],ent;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int dfm[N],low[N],dfn;
int ans=0x3f3f3f3f;
int b;
void dfs(int s,int f){
    int i,v;
    dfm[s]=++dfn;
    low[s]=dfm[s];
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        if(dfm[v]){
            low[s]=min(low[s],dfm[v]);
        }
        else{
            dfs(v,s);
            low[s]=min(low[v],low[s]);
            if(s!=f && dfm[b]>=dfm[v] && low[v]>=dfm[s]){
                ans=min(ans,s);
            }
        }
    }
}
int main(){
    int n,a;
    scanf("%d",&n);
    while(1){
        scanf("%d %d",&a,&b);
        if(a==0 && b==0){break;}
        adde(a,b);
        adde(b,a);
    }
    scanf("%d %d",&a,&b);
    dfs(a,a);
    if(ans>n){
        printf("No solution");
    }
    else{
        printf("%d",ans);
    }
    return 0;
}