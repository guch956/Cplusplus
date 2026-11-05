#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
const int Z=1e5;
const int INF=0x3f3f3f3f;
struct {
    int ls;
    int rs;
    int ma;
    int id;
}t[N*100];
int ent;
int head[N],entt;
int nex[N<<1],to[N<<1];
int siz[N],fa[N],deep[N],top[N],son[N];
int root[N];
int ans[N];
void adde(int u,int v){
    entt++;
    nex[entt]=head[u];
    to[entt]=v;
    head[u]=entt;
}
void dfs1(int s,int f){
    int i;
    siz[s]=1;
    fa[s]=f;
    deep[s]=deep[f]+1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        siz[s]+=siz[to[i]];
        if(siz[to[i]]>siz[son[s]]){
            son[s]=to[i];
        }
    }
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
    if(deep[x]<deep[y]){return x;}
    return y;
}
void push_up(int p){
    if(t[t[p].ls].ma>=t[t[p].rs].ma){
        t[p].ma=t[t[p].ls].ma;
        t[p].id=t[t[p].ls].id;
    }
    else{
        t[p].ma=t[t[p].rs].ma;
        t[p].id=t[t[p].rs].id;
    }
}
void addnode(int & p,int pl,int pr,int x,int d){
    if(!p){p = ++ent;}
    if(pl==pr){t[p].ma+=d;t[p].id=x;return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){addnode(t[p].ls,pl,mid,x,d);}
    else{addnode(t[p].rs,mid+1,pr,x,d);}
    push_up(p);
}
int hebing(int r1,int r2,int l,int r){
    if(r1==0 || r2==0){return r1+r2;}
    if(l==r){t[r2].ma=t[r1].ma+t[r2].ma;return r2;}
    int mid=(l+r)>>1;
    t[r2].ls=hebing(t[r1].ls,t[r2].ls,l,mid);
    t[r2].rs=hebing(t[r1].rs,t[r2].rs,mid+1,r);
    push_up(r2);
    return r2;
}
void dfs(int s){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s]){continue;}
        dfs(to[i]);
        root[s]=hebing(root[to[i]],root[s],1,Z);
    }
    if(t[root[s]].ma){ans[s]=t[root[s]].id;}
    else{ans[s]=0;}
}
int main(){
    int n,i,a,m,b,c;
    scanf("%d %d",&n,&m);
    t[0].ma=-INF;
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    while(m--){
        scanf("%d %d %d",&a,&b,&i);
        c = lca(a,b);
        if(c!=1){addnode(root[fa[c]],1,Z,i,-1);}
        addnode(root[c],1,Z,i,-1);
        addnode(root[a],1,Z,i,1);
        addnode(root[b],1,Z,i,1);
    }
    dfs(1);
    for(i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}