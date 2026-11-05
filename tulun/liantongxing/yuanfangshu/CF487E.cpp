#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
const int INF=0x3f3f3f3f;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
class tu{
    public:
        int head[N],to[N<<1],nex[N<<1],ent;
        void adde(int u,int v){
            ent++;
            to[ent]=v;
            nex[ent]=head[u];
            head[u]=ent;
        }
}g1,g;
class xianduanshu{
    public:
        int n,* tree;
        void push_up(int p){tree[p]=min(tree[ls(p)],tree[rs(p)]);}
        void start(int ,int *);
        void build(int ,int ,int ,int *);
        void update(int ,int ,int ,int ,int );
        int chaxun(int ,int ,int ,int ,int );
        ~xianduanshu(){delete [] tree;}
}xian[N];
void xianduanshu::build(int p,int l,int r,int * t){
    if(l==r){tree[p]=t[l];return ;}
    int mid=(l+r)>>1;
    build(ls(p),l,mid,t);
    build(rs(p),mid+1,r,t);
    push_up(p);
}
void xianduanshu::start(int n1,int * t){
    n = n1;
    tree = new int [4*n];
    build(1,1,n,t);
}
void xianduanshu::update(int p,int pl,int pr,int x,int d){
    if(pl==pr){tree[p]=d;return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){update(ls(p),pl,mid,x,d);}
    else{update(rs(p),mid+1,pr,x,d);}
    push_up(p);
}
int xianduanshu::chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1,ans=INF;
    if(l<=mid){ans = min(ans,chaxun(ls(p),pl,mid,l,r));}
    if(r>mid){ans = min(ans,chaxun(rs(p),mid+1,pr,l,r));}
    return ans;
}
int dian[N];
int num,n;
int dfm[N],low[N],dfn;
int zhan[N],topp;
int fa[N],siz[N],son[N],deep[N],top[N];
int weifa[N];
void dfs(int s){
    int i,v,m;
    dfm[s]=low[s]=++dfn;
    zhan[++topp]=s;
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(dfm[v]){
            low[s] = min(low[s],dfm[v]);
        }
        else{
            dfs(v);
            low[s] = min(low[s],low[v]);
            if(low[v]==dfm[s]){
                num++;
                dian[num]=INF;
                while(1){
                    g.adde(num,zhan[topp]);
                    dian[num]=min(dian[num],dian[zhan[topp]]);
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
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        deep[v]=deep[s]+1;
        dfs1(v);
        if(siz[v]>siz[son[s]]){son[s]=v;}
        siz[s]+=siz[v];
    }
    siz[s]++;
    if(s>n){
        topp=0;
        for(i=g.head[s];i;i=g.nex[i]){
            v = g.to[i];
            weifa[v]=++topp;
            zhan[topp]=dian[v];
        }
        xian[s].start(topp,zhan);
    }
}
void dfs2(int s,int topx){
    int i,v;
    dfm[s]=++dfn;
    top[s]=topx;
    zhan[dfn]=dian[s];
    if(son[s]){dfs2(son[s],topx);}
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(v==son[s]){continue;}
        dfs2(v,v);
    }
}
int chaxun(int x,int y,int & z){
    int ans=INF;
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        ans = min(ans,xian[0].chaxun(1,1,xian[0].n,dfm[top[x]],dfm[x]));
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){swap(x,y);}
    z = x;
    ans = min(ans,xian[0].chaxun(1,1,xian[0].n,dfm[x],dfm[y]));
    return ans;
}
int main(){
    int m,q,i,a,b,lca,ans;
    char c;
    scanf("%d %d %d",&n,&m,&q);
    num = n;
    for(i=1;i<=n;i++){
        scanf("%d",&dian[i]);
    }
    while(m--){
        scanf("%d %d",&a,&b);
        g1.adde(a,b);
        g1.adde(b,a);
    }
    dfs(1);
    dfn=0;
    dfs1(1);
    dfs2(1,1);
    xian[0].start(num,zhan);
    while(q--){
        c = getchar();
        while (c!='A' && c!='C'){c = getchar();}
        if(c=='A'){
            scanf("%d %d",&a,&b);
            ans = chaxun(a,b,lca);
            if(lca>n){ans = min(ans,dian[fa[lca]]);}
            printf("%d\n",ans);
        }
        else{
            scanf("%d %d",&a,&b);
            dian[a]=b;
            xian[0].update(1,1,xian[0].n,dfm[a],b);
            if(fa[a]>n){
                xian[fa[a]].update(1,1,xian[fa[a]].n,weifa[a],b);
                dian[fa[a]]=xian[fa[a]].tree[1];
                xian[0].update(1,1,xian[0].n,dfm[fa[a]],dian[fa[a]]);
            }
        }
    }
    return 0;
}