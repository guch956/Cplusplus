#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100002;
class tu{
    public:
    int head[N],nex[N*10],to[N*10],ent;
    tu(){ent=0;memset(head,0,sizeof(head));}
    void add(int u,int v){
        ent++;
        to[ent]=v;
        nex[ent]=head[u];
        head[u]=ent;
    }
}g,g1;
int scc[N],sccn;
int ans,end1;
int dfm[N],low[N],dfn;
int zhan[N],top;
int jiage[N],majg[N],mijg[N];
void tarjan(int s){
    int i,v;
    dfm[s]=low[s]=++dfn;
    zhan[top++]=s;
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(!dfm[v]){
            tarjan(v);
            low[s]=min(low[s],low[v]);
        }
        else if(!scc[v]){low[s]=min(low[s],dfm[v]);}
    }
    if(low[s]==dfm[s]){
        sccn++;
        majg[sccn]=-1;
        mijg[sccn]=123456;
        while(1){
            scc[zhan[--top]]=sccn;
            majg[sccn]=max(majg[sccn],jiage[zhan[top]]);
            mijg[sccn]=min(mijg[sccn],jiage[zhan[top]]);
            if(zhan[top]==s){break;}
        }
    }
}
int dp[N];
void dfs(int s){
    int i,v;
    dp[s]=(s==end1?majg[s]:-1);
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(dp[v]==-2){
            dfs(v);
        }
        dp[s]=max(dp[s],dp[v]);
    }
    if(dp[s]>=0){dp[s]=max(dp[s],majg[s]);}
    ans = max(ans,dp[s]-mijg[s]);
}
int main(){
    int m,n,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){scanf("%d",&jiage[i]);dp[i]=-2;}
    while(m--){
        scanf("%d %d %d",&a,&b,&i);
        g.add(a,b);
        if(i==2){g.add(b,a);}
    }
    tarjan(1);
    for(a=1;a<=n;a++){
        if(dfm[a]){
            for(i=g.head[a];i;i=g.nex[i]){
                b = g.to[i];
                if(scc[a]!=scc[b]){
                    g1.add(scc[a],scc[b]);
                }
            }
        }
    }
    end1=scc[n];
    dfs(scc[1]);
    printf("%d\n",ans);
    return 0;
}