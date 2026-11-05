#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
const int M=1000003;
struct {
    int to;
    int next;
}g[M],g1[M];
int head[N],ent;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int dfm[N],low[N]/*大小*/,dfn;
int n,X;
int sccn[N],sccnt,geshu[N];
int zhan[N]/*个数*/,top=1;
struct node{
    int u;
    int v;
}p[M];int top1;
void adde1(int u,int v){
    dfn++;
    g1[dfn].to=v;
    g1[dfn].next=dfm[u];
    dfm[u]=dfn;
}
void tarjan(int s){
    int i,v;
    dfm[s]=low[s]=++dfn;
    zhan[top++]=s;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(!dfm[v]){
            tarjan(v);
            low[s] = min(low[s],low[v]);
        }
        else if(!sccn[v]){
            low[s] = min(low[s],dfm[v]);
        }
    }
    if(dfm[s]==low[s]){
        sccnt++;
        while(1){
            top--;
            sccn[zhan[top]]=sccnt;
            geshu[sccnt]++;
            if(zhan[top]==s){
                break;
            }
        }
    }
}
bool bijiao(node & n1,node & n2){
    return n1.u==n2.u?n1.v<n2.v:n1.u<n2.u;
}
void dfs(int s){
    int v,i;
    zhan[s]=0;
    for(i=dfm[s];i;i=g1[i].next){
        v = g1[i].to;
        if(!low[v]){
            dfs(v);
        }
        if(low[v]>low[s]){
            low[s] = low[v];
            zhan[s] = zhan[v];
        }
        else if(low[v]==low[s]){
            zhan[s]+=zhan[v];
            zhan[s] = zhan[s]%X;
        }
    }
    low[s]+=geshu[s];
    if(!zhan[s]){
        zhan[s]=1;
    }
}
void jisuan(){
    int i,j,v,ans=0,num=0;
    for(i=1;i<=n;i++){
        if(!dfm[i]){
            tarjan(i);
        }
    }
    for(i=1;i<=sccnt;i++){
        dfm[i]=0;
        low[i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=head[i];j;j=g[j].next){
            v = g[j].to;
            if(sccn[i]!=sccn[v]){
                p[top1].u=sccn[i];
                p[top1].v=sccn[v];
                top1++;
            }
        }
    }
    sort(p,p+top1,bijiao);
    adde1(p[0].u,p[0].v);
    for(i=1;i<top1;i++){
        if(p[i].u!=p[i-1].u || p[i].v!=p[i-1].v){
            adde1(p[i].u,p[i].v);
        }
    }
    for(i=1;i<=sccnt;i++){
        if(!low[i]){
            dfs(i);
            ans = max(ans,low[i]);
        }
    }
    for(i=1;i<=sccnt;i++){
        if(low[i]==ans){
            num = (num+zhan[i])%X;
        }
    }
    printf("%d\n",ans);
    printf("%d",num);
}
int main(){
    int m,a,b;
    scanf("%d %d %d",&n,&m,&X);
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    jisuan();
    return 0;
}

