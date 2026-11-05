#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100003;const int M=200003;
const int INF=0x3f3f3f3f;
struct {
    int to;
    int next;
    int w;
}g1[M<<1];
struct {
    int to;
    int next;
}g[N];
int head[N],ent;
int n,m;
int head1[N];int ent1;
int topx[N];
int deep[N],son[N],siz[N];
int fa[N];
int vis[N];
int dfm[N],dfn;
int tree[N<<2];
int tag[N<<2];
int ans[N];
void addedge(int u,int v,int w){
    ent1++;
    g1[ent1].to=v;
    g1[ent1].w=w;
    g1[ent1].next=head1[u];
    head1[u]=ent1;
}
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
struct node{
    int id;
    int dis;
    node(int a,int b){id=a;dis=b;}
    bool operator <(const node &a)const {
        return dis>a.dis;
    }
};
void dfs1(int s){
    int i,v;
    siz[s]=1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        deep[v]=deep[s]+1;
        dfs1(v);
        if(siz[v]>siz[son[s]]){
            son[s]=v;
        }
        siz[s]+=siz[v];
    }
}
void dfs2(int s,int topp){
    int i,v;
    dfm[s]=++dfn;
    topx[s]=topp;
    if(son[s]){
        dfs2(son[s],topp);
    }
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==son[s]){continue;}
        dfs2(v,v);
    }
}
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=min(tree[ls(p)],tree[rs(p)]);
}
void addtag(int p,int d){
    tree[p]=min(tree[p],d);
    tag[p]=min(tag[p],d);
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=INF;
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
void push(int p,int pl,int pr){
    if(pl==pr){
        ans[pl]=tree[p];
        return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p);
    push(ls(p),pl,mid);
    push(rs(p),mid+1,pr);
}
void update1(int a,int b,int d){
    while(topx[a]!=topx[b]){
        if(deep[topx[a]]<deep[topx[b]]){
            swap(a,b);
        }
        update(1,1,n,dfm[topx[a]],dfm[a],d);
        a = fa[topx[a]];
    }
    if(deep[a]<deep[b]){swap(a,b);}
    if(a!=b){
        update(1,1,n,dfm[b]+1,dfm[a],d);
    }
}
void dij1(int s){
    int i,v,d,u;
    node a(s,0);
    for(i=1;i<=n;i++){
        vis[i]=INF;
    }
    vis[s]=0;
    priority_queue<node> q;
    q.push(a);
    while(q.size()){
        a = q.top();q.pop();
        u = a.id;
        if(a.dis>vis[u]){continue;}
        for(i=head1[u];i!=0;i=g1[i].next){
            v = g1[i].to;
            d = a.dis+g1[i].w;
            if(d<vis[v]){
                vis[v]=d;
                fa[v]=u;
                q.push(node(v,d));
            }
        }
    }
    for(i=1;i<=n;i++){
        if(i!=s){
            adde(fa[i],i);
        }
    }
    dfs1(s);
    dfs2(s,s);
    for(u=1;u<=n;u++){
        for(i=head1[u];i;i=g1[i].next){
            if(i&1){continue;}
            v = g1[i].to;
            if(u!=fa[v] && v!=fa[u]){
                update1(u,v,vis[u]+vis[v]+g1[i].w);
            }
        }
    }
    push(1,1,n);
    for(i=2;i<=n;i++){
        if(ans[dfm[i]]==INF){
            printf("-1\n");
        }
        else{
            printf("%d\n",ans[dfm[i]]-vis[i]);
        }
    }
}
int main(){
    int i,a,b,c;
    scanf("%d %d",&n,&m);
    memset(tree,0x3f,sizeof(tree));
    memset(tag,0x3f,sizeof(tag));
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        addedge(a,b,c);
        addedge(b,a,c);
    }
    dij1(1);
    return 0;
}

