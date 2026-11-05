#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
struct {
    int to;
    int next;
}g[N],g1[N];
int sccn[N],w[N],sccw[N],sccnt;
int head[N],ent;
bool isjb[N],sccis[N];
int zhan[N],top;
int dfn[N],low[N],dfm;
int n;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void adde1(int u,int v){
    dfm++;
    g1[dfm].to=v;
    g1[dfm].next=dfn[u];
    dfn[u]=dfm;
}
void tarjan(int s){
    int v,i;
    dfn[s]=low[s]=++dfm;
    zhan[++top]=s;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[s]=min(low[s],low[v]);
        }
        else if(!sccn[v]){
            low[s]=min(low[s],dfn[v]);
        }
    }
    if(low[s]==dfn[s]){
        sccnt++;
        while(1){
            sccw[sccnt]+=w[zhan[top]];
            sccn[zhan[top]]=sccnt;
            if(isjb[zhan[top]]){
                sccis[sccnt]=1;
            }
            if(zhan[top]==s){
                top--;
                break;
            }
            top--;
        }
    }
}
void buildtu(){
    int i,j,v;
    for(i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    dfm=0;
    for(i=1;i<=sccnt;i++){
        dfn[i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=head[i];j;j=g[j].next){
            v = g[j].to;
            if(sccn[i]!=sccn[v]){
                adde1(sccn[i],sccn[v]);
            }
        }
    }
}
void dp(int s){
    int i,v;
    for(i=dfn[s];i;i=g1[i].next){
        v = g1[i].to;
        if(low[v]==-1){dp(v);}
        low[s]=max(low[s],low[v]);
    }
    if(sccis[s]){low[s]=max(low[s],0);}
    if(low[s]>=0){low[s]+=sccw[s];}
}
int main(){
    int m,a,b,i,s;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    scanf("%d %d",&s,&m);
    while(m--){
        scanf("%d",&a);
        isjb[a]=1;
    }
    buildtu();
    for(i=1;i<=sccnt;i++){
        low[i]=-1;
    }
    dp(sccn[s]);
    printf("%d",low[sccn[s]]);
    return 0;
}
