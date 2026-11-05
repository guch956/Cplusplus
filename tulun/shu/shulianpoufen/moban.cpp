#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
const int N=100002;
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
struct edge{
    int to;
    int next;
};
int fa[N],son[N],siz[N],deep[N],top[N];
edge g[N<<1];int ent;int head[N];
int dfn,dfnm[N];
ll w[N],wdfn[N];
ll tree[N<<2];ll tag[N<<2];
ll mod;int n;
void addg(int u,int v){
    ent++;
    g[ent].to=u;
    g[ent].next=head[v];
    head[v]=ent;
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs1(int s,int father){
    int i,v;
    deep[s]=deep[father]+1;
    siz[s]=1;
    fa[s]=father;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=father){
            dfs1(v,s);
            siz[s]+=siz[v];
            if(siz[son[s]]<siz[v]){
                son[s]=v;
            }
        }
    }
}
void dfs2(int s,int father,int topx){
    int i,v;
    top[s]=topx;
    dfn++;dfnm[s]=dfn;
    wdfn[dfn]=w[s];
    if(son[s]!=0){dfs2(son[s],s,topx);}
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=father && v!=son[s]){
            dfs2(v,s,v);
        }
    }
}
void push_up(int p){
    tree[p]=(tree[ls(p)]+tree[rs(p)])%mod;
}
void addtag(int p,ll len,ll d){
    tag[p]= (tag[p]+d)%mod;
    tree[p]= (tree[p]+d*len)%mod;
}
void push_down(int p,int pl,int pr){
    int mid=(pl+pr)>>1;
    addtag(ls(p),mid+1-pl,tag[p]);
    addtag(rs(p),pr-mid,tag[p]);
    tag[p]=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){tree[p]=wdfn[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pl,pr);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p]%mod;}
    int mid=(pl+pr)>>1;ll ans=0;
    push_down(p,pl,pr);
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans%mod;
}
void update1(int x,int y,ll d){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        update(1,1,n,dfnm[top[x]],dfnm[x],d);
        x = fa[top[x]];
    }
    if(deep[x]<deep[y]){
        swap(x,y);
    }
    update(1,1,n,dfnm[y],dfnm[x],d);
}
ll chaxun1(int x,int y){
    ll ans=0;
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        ans+=chaxun(1,1,n,dfnm[top[x]],dfnm[x]);
        ans = ans%mod;
        x = fa[top[x]];
    }
    if(deep[x]<deep[y]){swap(x,y);}
    ans+=chaxun(1,1,n,dfnm[y],dfnm[x]);
    return ans%mod;
}
void update2(int x,ll d){
    update(1,1,n,dfnm[x],dfnm[x]+siz[x]-1,d);
}
ll chaxun2(int x){
    return chaxun(1,1,n,dfnm[x],dfnm[x]+siz[x]-1);
}
int main(){
    int root,a,m,b,i,k;ll e;
    /*freopen("P3384_4.in","r",stdin);
    freopen("P3384_4.out","w",stdout);*/
    scanf("%d %d %d %lld",&n,&m,&root,&mod);
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        addg(a,b);
    }
    dfs1(root,root);
    dfs2(root,0,root);
    build(1,1,n);
    while(m){
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %lld",&a,&b,&e);
            update1(a,b,e);
        }
        else if(k==2){
            scanf("%d %d",&a,&b);
            printf("%lld\n",chaxun1(a,b));
        }
        else if(k==3){
            scanf("%d %lld",&a,&e);
            update2(a,e);
        }
        else{
            scanf("%d",&a);
            printf("%lld\n",chaxun2(a));
        }
        m--;
    }
    return 0;
}