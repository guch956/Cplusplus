#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int to;
    int next;
}g[N<<1];
int n;
int head[N],ent,deep[N],son[N],topx[N],fa[N],siz[N];
int dfn[N],dfm;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int v,i,a=0,b=0;
    siz[s]=1;
    fa[s]=f;
    deep[s]=deep[f]+1;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs1(v,s);
            siz[s]+=siz[v];
            if(siz[v]>b){
                b = siz[v];
                a = v;
            }
        }
    }
    son[s]=a;
}
void dfs2(int s,int top){
    int v,i;
    dfm++;
    topx[s]=top;
    dfn[s]=dfm;
    if(son[s]){
        dfs2(son[s],top);
    }
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=fa[s] && v!=son[s]){
            dfs2(v,v);
        }
    }
}
int tree[N<<2];
int tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void addtag(int p,int pl,int pr,int d){
    tree[p]+=d*(pr-pl+1);
    tag[p]+=d;
}
void push_down(int p,int pl,int pr){
	int mid=(pl+pr)>>1;
    addtag(ls(p),pl,mid,tag[p]);
    addtag(rs(p),mid+1,pr,tag[p]);
    tag[p]=0;
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){
        addtag(p,pl,pr,d);return ;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
int chaxun(int p,int pl,int pr,int x){
    if(pl==pr){return tree[p];}
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(x<=mid){return chaxun(ls(p),pl,mid,x);}
    else{return chaxun(rs(p),mid+1,pr,x);}
}
void update1(int a,int b){
    while(topx[a]!=topx[b]){
        if(deep[topx[a]]<deep[topx[b]]){
            update(1,1,n,dfn[topx[b]],dfn[b],1);
            b = fa[topx[b]];
        }
        else{
            update(1,1,n,dfn[topx[a]],dfn[a],1);
            a = fa[topx[a]];
        }
    }
    if(deep[a]<deep[b]){
        update(1,1,n,dfn[a]+1,dfn[b],1);
    }
    if(deep[a]>deep[b]){
        update(1,1,n,dfn[b]+1,dfn[a],1);
    }
}
int main(){
    int i,a,b,m;
    char c;
    /*freopen("2.in","r",stdin);*/
    /*freopen("2.out","w",stdout);*/
    scanf("%d %d",&n,&m);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    while(m){
        cin>>c;
        if(c=='P'){
            scanf("%d %d",&a,&b);
            update1(a,b);
        }
        else{
            scanf("%d %d",&a,&b);
            if(a==fa[b]){
                printf("%d\n",chaxun(1,1,n,dfn[b]));
            }
            else{
                printf("%d\n",chaxun(1,1,n,dfn[a]));
            }
        }
        m--;
    }
    return 0;
}
