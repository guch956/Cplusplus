#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
int nex[N],to[N];
int head[N],ent;
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
int son[N],deep[N],siz[N],top[N];
int fa[N];
int dfm[N],dfmx[N],dfn;
int ans[N];
struct {
    int id;
    int dep;
}query[N];
int headq[N];
int nexq[N],entq;
int num[N];
void addq(int i,int d,int s){
    entq++;
    nexq[entq]=headq[s];
    query[entq].id=i;
    query[entq].dep=d;
    headq[s]=entq;
}
void dfs1(int s){
    int i;
    deep[s]=deep[fa[s]]+1;
    siz[s]=1;   
    for(i=head[s];i;i=nex[i]){
        dfs1(to[i]);
        siz[s]+=siz[to[i]];
        if(siz[to[i]]>siz[son[s]]){
            son[s]=to[i];
        }
    }
}
void dfs2(int s,int topx){
    int i;
    top[s]=topx;
    dfm[s]=++dfn;
    dfmx[dfn]=s;
    if(son[s]){
        dfs2(son[s],topx);
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==son[s]){continue;}
        dfs2(to[i],to[i]);
    }
}
int up(int s,int k){
    while(deep[top[s]]+k>deep[s]){
        k -= deep[s]-deep[top[s]]+1;
        s = fa[top[s]];
    }
    return dfmx[dfm[s]-k];
}
void subdfs(int s,int d){
    int i;
    num[deep[s]]+=d;
    for(i=head[s];i;i=nex[i]){
        subdfs(to[i],d);
    }
}
void dfs(int s,bool clear){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==son[s]){continue;}
        dfs(to[i],1);
    }
    if(son[s]){
        dfs(son[s],0);
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==son[s]){continue;}
        subdfs(to[i],1);
    }
    for(i=headq[s];i;i=nexq[i]){
        ans[query[i].id]=num[query[i].dep]-1;
    }
    if(clear){
        for(i=head[s];i;i=nex[i]){
            subdfs(to[i],-1);
        }
    }
    else{
        num[deep[s]]++;
    }
}
int main(){
    int n,q,i,a,b,c;
    scanf("%d %d",&n,&q);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        adde(a,i);
        fa[i]=a;
    }
    dfs1(1);
    dfs2(1,1);
    for(i=1;i<=q;i++){
        scanf("%d %d",&a,&b);
        if(deep[a]<=b){ans[i]=0;}
        else{
            c = up(a,b);
            addq(i,deep[a],c);
        }
    }
    dfs(1,0);
    for(i=1;i<=q;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}