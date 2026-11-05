#include<iostream>
#include<cstdio>
using namespace std;
const int N=500002;
struct {
    int to;
    int next;
}g[N<<2];
int ent=1,head[N];
int n;
void adde(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
int dfn,dfm[N],deep[N],son[N],top[N],siz[N],fa[N];
void dfs1(int s,int f){
    int i,a=0,v,ma=0;
    deep[s]=deep[f]+1;
    fa[s]=f;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs1(v,s);
            siz[s]+=siz[v];
            if(siz[v]>ma){
                ma=siz[v];
                a = v;
            }
        }
    }
    son[s]=a;
    siz[s]++;
}
void dfs2(int s,int f,int topx){
    int i,v;
    dfn++;
    dfm[s]=dfn;
    top[s]=topx;
    if(son[s]!=0){
        dfs2(son[s],s,topx);
    }
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f && v!=son[s]){
            dfs2(v,s,v);
        }
    }
}
int tree[N<<2],tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void addtag(int p,int len,int x){
    tree[p]=len*x;
    tag[p]=x;
}
void push_down(int p,int len){
    if(tag[p]!=-1){
        addtag(ls(p),(len+1)>>1,tag[p]);
        addtag(rs(p),len>>1,tag[p]);
        tag[p]=-1;
    }
}
void update(int p,int pl,int pr,int l,int r,int x){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,x);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){update(ls(p),pl,mid,l,r,x);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,x);}
    push_up(p);
}
int chaxun(int p,int pl,int pr,int x){
    if(pl==pr){return tree[p];}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(x<=mid){return chaxun(ls(p),pl,mid,x);}
    else{return chaxun(rs(p),mid+1,pr,x);}
}
void caozuo1(int s){
    update(1,1,n,dfm[s],dfm[s]+siz[s]-1,1);
}
void caozuo2(int s){
    while(top[s]!=top[1]){
        update(1,1,n,dfm[top[s]],dfm[s],0);
        s = fa[top[s]];
    }
    update(1,1,n,1,dfm[s],0);
}
int caozuo3(int s){
    return chaxun(1,1,n,dfm[s]);
}
int main(){
    int m,i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    scanf("%d",&m);
    dfs1(1,1);
    dfs2(1,1,1);
    while(m){
        scanf("%d %d",&i,&b);
        if(i==1){
            caozuo1(b);
        }
        else if(i==2){
            caozuo2(b);
        }
        else{
            printf("%d\n",caozuo3(b));
        }
        m--;
    }
    return 0;
}