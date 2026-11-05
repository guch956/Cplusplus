#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
ll sum[N<<2];
ll tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    sum[p]=sum[ls(p)]+sum[rs(p)];
}
void addtag(int p,ll len,ll d){
    sum[p]+=d*len;
    tag[p]+=d;
}
void push_down(int p,ll len){
    addtag(ls(p),(len+1)>>1,tag[p]);
    addtag(rs(p),len>>1,tag[p]);
    tag[p]=0;
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return sum[p];}
    int mid=(pl+pr)>>1;ll s=0;
    push_down(p,pr-pl+1);
    if(l<=mid){s+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){s+=chaxun(rs(p),mid+1,pr,l,r);}
    return s;
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
int head[N],to[N],nex[N],ent;
int fa[N],son[N],siz[N],top[N],deep[N];
int dfn,dfm[N];
int n;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s){
    int i;
    deep[s]=deep[fa[s]]+1;
    siz[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s]){continue;}
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
    if(son[s]){
        dfs2(son[s],topx);
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s]){
            continue;
        }
        dfs2(to[i],to[i]);
    }
}
void update1(int u,int v,ll d){
    while(top[u]!=top[v]){
        if(deep[top[u]]<deep[top[v]]){swap(u,v);}
        update(1,1,n,dfm[top[u]],dfm[u],d);
        u = fa[top[u]];
    }
    if(deep[u]<deep[v]){swap(u,v);}
    update(1,1,n,dfm[v],dfm[u],d);
}
int main(){
    int q,i,a,b;
    char c;
    ll d;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        a++;
        b++;
        fa[b]=a;
        adde(a,b);
    }
    dfs1(1);
    dfs2(1,1);
    scanf("%d",&q);
    while(q--){
        cin>>c;
        if(c=='A'){
            scanf("%d %d %lld",&a,&b,&d);
            update1(++a,++b,d);
        }
        else{
            scanf("%d",&a);
            a++;
            printf("%lld\n",chaxun(1,1,n,dfm[a],dfm[a]+siz[a]-1));
        }
    }
    return 0;
}
