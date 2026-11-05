#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
struct {
    int to;
    int next;
    bool type;/*1表大于，0表大于等于*/
}g[N<<1],gg[N<<1];
int head[N],ent;
void adde(int u,int v,bool t){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].type=t;
    head[u]=ent;
}
int dfm[N],low[N],sccn[N],sccsiz[N];
int zhan[N],top;
int dfn;
int scc;
int headg[N],entg;
ll dp[N];
int n;
ll ans;
void addeg(int u,int v,bool t){
    entg++;
    gg[entg].next=headg[u];
    gg[entg].to=v;
    gg[entg].type=t;
    headg[u]=entg;
}
void tarjan(int s){
    int i,v;
    dfm[s]=low[s]=++dfn;
    zhan[top++]=s;
    for(i=head[s];i;i=g[i].next){
        v=g[i].to;
        if(!dfm[v]){
            tarjan(v);
            low[s]=min(low[s],low[v]);
        }
        else if(!sccn[v]){
            low[s]=min(low[s],dfm[v]);
        }
    }
    if(dfm[s]==low[s]){
        scc++;
        while(1){
            top--;
            sccsiz[scc]++;
            sccn[zhan[top]]=scc;
            if(zhan[top]==s){
                break;
            }
        }
    }
}
void dfs(int s){
    int i,v;
    dfm[s]=1;
    dp[s]=1;
    for(i=headg[s];i;i=gg[i].next){
        v=gg[i].to;
        if(!dfm[v]){
            dfs(v);
        }
        if(gg[i].type){
            dp[s]=max(dp[s],dp[v]+1);
        }
        else{
            dp[s]=max(dp[s],dp[v]);
        }
    }
    ans+=sccsiz[s]*dp[s];
}
void suodian(){
    int i,j,v;
    for(i=1;i<=n;i++){
        if(!dfm[i]){
            tarjan(i);
        }
    }
    for(j=1;j<=n;j++){
        for(i=head[j];i;i=g[i].next){
            v=g[i].to;
            if(sccn[j]==sccn[v]){
                if(g[i].type){
                    printf("-1");
                    return ;
                }
            }
            else{
                addeg(sccn[j],sccn[v],g[i].type);
            }
        }
        dfm[j]=0;
    }
    for(i=1;i<=scc;i++){
        if(!dfm[i]){
            dfs(i);
        }
    }
    printf("%lld",ans);
}
int main(){
    int m,i,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&i,&a,&b);
        if(i==1){
            adde(a,b,false);
            adde(b,a,false);
        }
        else if(i==2){
            adde(b,a,true);
        }
        else if(i==3){
            adde(a,b,false);
        }
        else if(i==4){
            adde(a,b,true);
        }
        else{
            adde(b,a,false);
        }
    }
    suodian();
    return 0;
}
