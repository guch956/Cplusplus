#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
int dfm[N],dfn,low[N];
int n,num;
int geshu[N],deep[N],siz[N],son[N],top[N],fa[N];
int zhan[N],topp;
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
void dfs(int s){
    int i,v;
    zhan[++topp]=s;
    dfm[s]=low[s]=++dfn;
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(dfm[v]){
            low[s]=min(low[s],dfm[v]);
        }
        else{
            dfs(v);
            low[s]=min(low[s],low[v]);
            if(low[v]==dfm[s]){
                num++;
                while(1){
                    g.adde(num,zhan[topp]);
                    fa[zhan[topp]]=num;
                    if(zhan[topp--]==v){break;}
                }
                g.adde(s,num);
                fa[num]=s;
            }
        }
    }
}
void dfs1(int s){
    int i,v;
    siz[s]=1;
    geshu[s]=geshu[fa[s]];
    if(s<=n){geshu[s]++;}
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        deep[v]=deep[s]+1;
        dfs1(v);
        siz[s]+=siz[v];
        if(siz[v]>siz[son[s]]){son[s]=v;}
    }
}
void dfs2(int s,int topx){
    int i,v;
    top[s]=topx;
    if(son[s]){dfs2(son[s],topx);}
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(v==son[s]){continue;}
        dfs2(v,v);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        x = fa[top[x]];
    }
    if(deep[x]<deep[y]){return x;}
    return y;
}
int main(){
    int m,i,a,b,c;
    scanf("%d %d",&n,&m);
    num = n;
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g1.adde(a,b);
        g1.adde(b,a);
    }
    dfs(1);
    dfs1(1);
    dfs2(1,1);
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&a,&b);
        c = lca(a,b);
        printf("%d\n",geshu[a]+geshu[b]-geshu[c]-geshu[fa[c]]);
    }
    return 0;
}