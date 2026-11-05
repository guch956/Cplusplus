#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct node{
    int lc;
    int rc;
    int duan;
}tree[N<<2];
int tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
node hebing1(node  a,node  b){
    node c;
    if(a.duan==0){
        return b;
    }
    if(b.duan==0){
        return a;
    }
    c.lc=a.lc;
    c.rc=b.rc;
    c.duan=a.duan+b.duan;
    if(a.rc==b.lc){c.duan--;}
    return c;
}
void push_up(int p){
    tree[p]=hebing1(tree[ls(p)],tree[rs(p)]);
}
void addtag(int p,int c){
    tag[p]=c;
    tree[p].lc=tree[p].rc=c;
    tree[p].duan=1;
}
void push_down(int p){
    if(tag[p]!=0){
        addtag(ls(p),tag[p]);
        addtag(rs(p),tag[p]);
        tag[p]=0;
    }
}
void update(int p,int pl,int pr,int l,int r,int c){
    if(l<=pl && r>=pr){addtag(p,c);return ;}
    push_down(p);
    int mid=(pl+pr)>>1;
    if(l<=mid){update(ls(p),pl,mid,l,r,c);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,c);}
    push_up(p);
}
node chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;
    push_down(p);
    node a,b;
    a.duan=b.duan=0;
    if(l<=mid){a=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){b=chaxun(rs(p),mid+1,pr,l,r);}
    return hebing1(a,b);
}
struct {
    int to;
    int next;
}g[N<<1];
int head[N];int ent=1;
int fa[N],topx[N],son[N],siz[N],dfn[N];
int deep[N];
int dfm;
int n,m;
int col[N];int coll[N];
void adde(int a,int b){
    g[ent].to=b;
    g[ent].next=head[a];
    head[a]=ent;
    ent++;
}
void dfs1(int s,int f){
    int v,a=0,b=0,i;
    fa[s]=f;
    deep[s]=deep[f]+1;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs1(v,s);
            if(siz[v]>b){
                b = siz[v];
                a = v;
            }
            siz[s]+=siz[v];
        }
    }
    son[s]=a;
    siz[s]++;
}
void dfs2(int s,int t){
    int i,v;
    dfm++;
    dfn[s]=dfm;
    coll[dfm]=col[s];
    topx[s]=t;
    if(son[s]!=0){
        dfs2(son[s],t);
    }
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=fa[s] && v!=son[s]){
            dfs2(v,v);
        }
    }
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p].lc=tree[p].rc=coll[pl];
        tree[p].duan=1;
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update1(int a,int b,int c){
    while(topx[a]!=topx[b]){
        if(deep[topx[a]]<deep[topx[b]]){
            swap(a,b);
        }
        update(1,1,n,dfn[topx[a]],dfn[a],c);
        a = fa[topx[a]];
    }
    if(deep[a]<deep[b]){
        swap(a,b);
    }
    update(1,1,n,dfn[b],dfn[a],c);
}
void chaxun1(int a,int b){
    node x,y;
    x.duan=0;
    y.duan=0;
    while(topx[a]!=topx[b]){
        if(deep[topx[a]]<deep[topx[b]]){
            y = hebing1(chaxun(1,1,n,dfn[topx[b]],dfn[b]),y);
            b = fa[topx[b]];
        }
        else{
            x = hebing1(chaxun(1,1,n,dfn[topx[a]],dfn[a]),x);
            a = fa[topx[a]];
        }
    }
    if(deep[a]<deep[b]){
        y = hebing1(chaxun(1,1,n,dfn[a],dfn[b]),y);
    }
    else{
        x = hebing1(chaxun(1,1,n,dfn[b],dfn[a]),x);
    }
    swap(x.lc,x.rc);
    printf("%d\n",hebing1(x,y).duan);
}
int main(){
    int i,a,b;
    char c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&col[i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    build(1,1,n);
    while(m){
        cin>>c;
        if(c=='C'){
            scanf("%d %d %d",&a,&b,&i);
            update1(a,b,i);
        }
        else{
            scanf("%d %d",&a,&b);
            chaxun1(a,b);
        }
        m--;
    }
    return 0;
}