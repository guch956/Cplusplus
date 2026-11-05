#include<iostream>
#include<cstdio>
using namespace std;
const int N=300003;
class tu{
    public:
        int head[N],to[N<<1],nex[N<<1],ent;
        void adde(int u,int v){
            ent++;
            to[ent]=v;
            nex[ent]=head[u];
            head[u]=ent;
        }
}g,g1;
int dfm[N],low[N],dfn;
int num,top;
int zhan[N];
int dp[N],ans;
int bian[N];
void dfs(int s,int f){
    int i,v;
    dfm[s]=low[s]=++dfn;
    zhan[++top]=s;
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(v==f){continue;}
        if(dfm[v]){low[s] = min(low[s],dfm[v]);}
        else{
            dfs(v,s);
            low[s] = min(low[s],low[v]);
        }
    }
    if(low[s]==dfm[s]){
        num++;
        while(1){
            bian[zhan[top]]=num;
            if(zhan[top--]==s){break;}
        }
    }
}
void dfs1(int s,int f){
    int i,v;
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(v==f){continue;}
        dfs1(v,s);
        ans = max(ans,dp[s]+dp[v]+1);
        dp[s] = max(dp[s],dp[v]+1);
    }
}
int main(){
    int n,m,a,b,i;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        g1.adde(a,b);
        g1.adde(b,a);
    }
    dfs(1,1);
    for(a=1;a<=n;a++){
        for(i=g1.head[a];i;i=g1.nex[i]){
            b = g1.to[i];
            if(bian[a]!=bian[b]){
                g.adde(bian[a],bian[b]);
            }
        }
    }
    dfs1(1,1);
    printf("%d",ans);
    return 0;
}