#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
int dfm[N],dfn,low[N],num,n;
int deep[N],geshu[N],siz[N],fa[N],son[N],top[N];
int zhan[N],topp;
int q[N];
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
    dfm[s]=low[s]=++dfn;
    zhan[++topp]=s;
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
    dfm[s]=++dfn;
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
bool bijiao(int x1,int x2){
    return dfm[x1]<dfm[x2];
}
int build(int nu){
    int i,x,y,ans=1,last;
    topp=0;
    sort(q+1,q+nu+1,bijiao);
    zhan[++topp]=q[1];
    for(i=2;i<=nu;i++){
        y = 0;
        while(topp){
            last = y;
            y = lca(zhan[topp],q[i]);
            if(dfm[y]<dfm[zhan[topp]]){
                topp--;
            }
            else{break;}
        }
        if(topp==0){
            ans+=geshu[fa[zhan[1]]]+geshu[q[i]]-geshu[y]-geshu[fa[y]];
            zhan[++topp]=y;
        }
        else{ans+=geshu[q[i]]-geshu[last==0?zhan[topp]:last];}
        zhan[++topp]=q[i];
    }
    return ans;
}
void solve(){
    int m,i,a,b,Q;
    scanf("%d %d",&n,&m);
    num = n;
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g1.adde(a,b);
        g1.adde(b,a);
    }
    dfn=0;
    dfs(1);
    dfs1(1);
    dfn=0;
    dfs2(1,1);
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&a);
        for(i=1;i<=a;i++){
            scanf("%d",&q[i]);
        }
        printf("%d\n",build(a)-a);
    }
    for(i=1;i<=num;i++){
        g1.head[i]=g.head[i]=0;
        son[i]=0;dfm[i]=0;
    }
    g1.ent=g.ent=0;
    topp=0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){solve();}
    return 0;
}