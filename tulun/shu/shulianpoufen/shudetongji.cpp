#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int N=30003;const ll INF=0x3f3f3f3f3f3f3f3f;
struct {
    int to;
    int next;
}g[N<<1];int ent=1;
int n;
int head[N];int dfn;
int siz[N];int son[N];int dfnm[N];
int top[N];int deep[N];int fa[N];
void addedge(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
    g[ent].to=u;
    g[ent].next=head[v];
    head[v]=ent;
    ent++;
}
void dfs1(int s,int f){
    int i,v,smax=0,so=0;
    deep[s]=deep[f]+1;
    fa[s]=f;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs1(v,s);
            siz[s]+=siz[v];
            if(siz[v]>smax){
                smax=siz[v];
                so=v;
            }
        }
    }
    son[s]=so;
    siz[s]++;
}
void dfs2(int s,int topx){
    int i,v;
    dfn++;
    dfnm[s]=dfn;
    top[s]=topx;
    if(son[s]!=0){dfs2(son[s],topx);}
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=fa[s] && v!=son[s]){
            dfs2(v,v);
        }
    }
}
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
struct {
    ll t_max;
    ll t_sum;
}tree[N<<2];
ll w[N];
void push_up(int p){
    tree[p].t_max=max(tree[ls(p)].t_max,tree[rs(p)].t_max);
    tree[p].t_sum=tree[ls(p)].t_sum+tree[rs(p)].t_sum;
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p].t_max=w[pl];
        tree[p].t_sum=w[pl];
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int x,ll d){
    if(pl==pr){
        tree[p].t_max=d;
        tree[p].t_sum=d;return ;
    }
    int mid=(pl+pr)>>1;
    if(x<=mid)update(ls(p),pl,mid,x,d);
    if(x>mid)update(rs(p),mid+1,pr,x,d);
    push_up(p);
}
ll chaxun1(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p].t_max;}
    int mid=(pl+pr)>>1;ll ans=-INF;
    if(l<=mid){ans=max(ans,chaxun1(ls(p),pl,mid,l,r));}
    if(r>mid){ans=max(ans,chaxun1(rs(p),mid+1,pr,l,r));}
    return ans;
}
ll chaxun2(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p].t_sum;}
    int mid=(pl+pr)>>1;ll ans=0;
    if(l<=mid){ans=ans+chaxun2(ls(p),pl,mid,l,r);}
    if(r>mid){ans=ans+chaxun2(rs(p),mid+1,pr,l,r);}
    return ans;
}
ll t_chaxun1(int x,int y){
    ll ans=-INF;
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        ans=max(ans,chaxun1(1,1,n,dfnm[top[x]],dfnm[x]));
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){swap(x,y);}
    ans=max(ans,chaxun1(1,1,n,dfnm[x],dfnm[y]));
    return ans;
}
ll t_chaxun2(int x,int y){
    ll ans=0;
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        ans=ans+chaxun2(1,1,n,dfnm[top[x]],dfnm[x]);
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){swap(x,y);}
    ans=ans+chaxun2(1,1,n,dfnm[x],dfnm[y]);
    return ans;
}
int main(){
    int m,i,a,b,k;ll e;
    char c[10];
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        addedge(a,b);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(i=1;i<=n;i++){
        scanf("%lld",&e);
        w[dfnm[i]]=e;
    }
    build(1,1,n);
    scanf("%d",&m);
    while(m){
        scanf("%s",c);
        if(c[1]=='H'){
            scanf("%d %lld",&a,&e);
            update(1,1,n,dfnm[a],e);
        }
        else if(c[1]=='M'){
            scanf("%d %d",&a,&b);
            printf("%lld\n",t_chaxun1(a,b));
        }
        else{
            scanf("%d %d",&a,&b);
            printf("%lld\n",t_chaxun2(a,b));
        }
        m--;
    }
    return 0;
}