#include<iostream>
#include<cstdio>
using namespace std;
const int N=5003;
int head[N],to[N*20],nex[N*20],ent;
int scc[N],sccn,num[N];
int dfm[N],dfn,low[N];
int zhan[N],top;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void tarjan(int s){
    int i,v;
    dfm[s]=low[s]=++dfn;
    zhan[top++]=s;
    for(i=head[s];i;i=nex[i]){
        if(!dfm[to[i]]){
            tarjan(to[i]);
            low[s]=min(low[s],low[to[i]]);
        }
        else if(!scc[to[i]]){
            low[s]=min(low[s],low[to[i]]);
        }
    }
    if(low[s]==dfm[s]){
        sccn++;
        while(1){
            scc[zhan[--top]]=sccn;
            num[sccn]++;
            if(zhan[top]==s){break;}
        }
    }
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&a,&b,&i);
        adde(a,b);
        if(i==2)adde(b,a);
    }
    a = 0;
    for(i=1;i<=n;i++){
        if(!dfm[i])tarjan(i);
    }
    for(i=1;i<=n;i++){
        if(num[scc[i]]>num[a]){a = scc[i];}
    }
    printf("%d\n",num[a]);
    for(i=1;i<=n;i++){
        if(scc[i]==a){printf("%d ",i);}
    }
    return 0;
}
