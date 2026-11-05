#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int head[N],to[N<<1],nex[N<<1];
int sum[N];
int top[N],siz[N],son[N],deep[N],fa[N];
int ent,ans,m;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    deep[s]=deep[f]+1;
    fa[s]=f;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        if(siz[to[i]]>siz[son[s]]){son[s]=to[i];}
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
}
void dfs2(int s,int topx){
    int i;
    top[s]=topx;
    if(son[s]){dfs2(son[s],topx);}
    for(i=head[s];i;i=nex[i]){
        if(to[i]==son[s] || to[i]==fa[s]){continue;}
        dfs2(to[i],to[i]);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){return y;}
    return x;
}
void dfs3(int s){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s]){continue;}
        dfs3(to[i]);
        if(sum[to[i]]==1){ans++;}
        if(sum[to[i]]==0){ans+=m;}
        sum[s]+=sum[to[i]];
    }
}
int main(){
    int n,i,b,a,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++){scanf("%d %d",&a,&b);adde(a,b);adde(b,a);}
    dfs(1,0);
    dfs2(1,1);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        c = lca(a,b);
        sum[a]++;sum[b]++;
        sum[c]-=2;
    }
    dfs3(1);
    printf("%d",ans);
    return 0;
}