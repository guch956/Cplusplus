#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=10003;
struct {
    int to;
    int next;
}g[N<<4];
int head[N],ent;
int dfm[N],low[N],ge;
int ans,dfn;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs(int s,int e){
    int v,i,child=0,gedian=0;
    dfm[s]=++dfn;
    low[s]=dfm[s];
    for(i=head[s];i!=-1;i=g[i].next){
        if(i==(e^1)){continue;}
        v = g[i].to;
        if(!dfm[v]){
            child++;
            dfs(v,i);
            low[s]=min(low[s],low[v]);
            if(low[v]>=dfm[s] && s!=ge){
                gedian++;
            }
        }
        else{
            low[s]=min(low[s],dfm[v]);
        }
    }
    if(s==ge){
        ans = max(ans,child-1);
    }
    else{
        ans = max(ans,gedian);
    }
}
int main(){
    int n,m,a,b,i,num;
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0){break;}
        memset(head,-1,sizeof(head));
        memset(dfm,0,sizeof(dfm));
        ans=-0x3f3f3f3f;
        num=0;
        dfn=0;
        ent=-1;
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            adde(++a,++b);
            adde(b,a);
        }
        for(i=1;i<=n;i++){
            if(!dfm[i]){
                ge = i;
                num++;
                dfs(i,10000000);
            }
        }    
        printf("%d\n",ans+num);
    }
    return 0;
}