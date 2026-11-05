#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
/*int tree[N<<2],mi[N<<2];
int son[N],siz[N],top[N],dfm[N],dfn;
int to[N<<1],fa[N],nex[N<<1],head[N],ent;
int zhuangtai[N],so[N];
int val[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    fa[s]=f;
    siz[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        siz[s]+=siz[to[i]];
        if(siz[to[i]]>siz[son[s]]){son[s]=to[i];}
    }
}
void dfs2(int s,int topx){
    int i;
    top[s]=topx;
    dfm[s]=++dfn;
    if(son[s]){dfs2(son[s],topx);}
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s]){continue;}
        dfs2(to[i],to[i]);
    }
}
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
void push_up(int p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
    mi[p]=mi[rs(p)]?mi[rs(p)]:mi[ls(p)];
}
void update(int p,int pl,int pr,int x,int d,int * t){
    if(pl==pr){t[p]=d;return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){update(ls(p),pl,mid,x,d,t);}
    else{update(rs(p),mid+1,pr,x,d,t);}
    push_up(p);
}
int chaxun1(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1,ans=0;
    if(l<=mid){ans = max(ans,chaxun1(ls(p),pl,mid,l,r));}
    if(r>mid){ans = max(ans,chaxun1(rs(p),mid+1,pr,l,r));}
    return ans;
}
int chaxun2(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return mi[p];}
    int mid=(pl+pr)>>1,a=0;
    if(r>mid){a = chaxun2(rs(p),mid+1,pr,l,r);}
    if(a){return a;}
    return l<=mid?chaxun2(ls(p),pl,mid,l,r):0;
}
int query(int x,int n){
    int ans=0,y,a,b=x,last=0;
    bool c=1;
    while(x){
        y = top[x];
        ans = max(ans,chaxun1(1,1,n,dfm[y],dfm[x]));
        if(c){
            a = chaxun2(1,1,n,dfm[y],dfm[x]);
            if(a){
                if(a==b || (dfm[b]<dfm[so[a]]) || (dfm[b]>=dfm[so[a]]+siz[so[a]])){
                    ans = max(ans,val[a]);
                }
                c = 0;
            }
        }
        x = fa[y];
        last=y;
    }
    return ans?ans:-1;
}
int main(){
    int n,i,a,b,q;
    char c[10];
    zhuangtai[0]=2;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){scanf("%d",&val[i]);}
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,0);
    dfs2(1,1);
    while(q--){
        scanf("%s",c);
        if(c[0]=='M'){
            scanf("%d",&a);
            b = a;
            update(1,1,n,dfm[a],val[a],tree);
            if(zhuangtai[a]){zhuangtai[a]=2;continue;}
            zhuangtai[a]=2;
            a = fa[a];
            while(!zhuangtai[a]){
                zhuangtai[a]=1;
                so[a]=b;
                update(1,1,n,dfm[a],a,mi);
                b = a;
                a = fa[a];
            }
            if(zhuangtai[a]==1){
                zhuangtai[a]=2;
                update(1,1,n,dfm[a],0,mi);
                update(1,1,n,dfm[a],val[a],tree);
            }
        }
        else{
            scanf("%d",&a);
            printf("%d\n",query(a,n));
        }
    }
    return 0;
}*/
int tree[N<<2],tag[N<<2];
int nex[N<<1],to[N<<1],head[N],ent;
int fa[N];
int dfn,dfm[N],siz[N];
int val[N];
int zhuangtai[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    dfm[s]=++dfn;
    fa[s]=f;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
}
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){tree[p]=max(tree[ls(p)],tree[rs(p)]);}
void addtag(int p,int d){
    tree[p]=max(tree[p],d);
    tag[p]=max(tag[p],d);
}
void push_down(int p){
    if(tag[p]){
        addtag(ls(p),tag[p]);
        addtag(rs(p),tag[p]);
        tag[p]=0;
    }
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1,ans=0;
    push_down(p);
    if(l<=mid){ans = max(ans,chaxun(ls(p),pl,mid,l,r));}
    if(r>mid){ans = max(ans,chaxun(rs(p),mid+1,pr,l,r));}
    return ans;
}
int main(){
    int n,q,i,a,b;
    char c[10];
    zhuangtai[0]=2;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,0);
    while(q--){
        scanf("%s",c);
        if(c[0]=='M'){
            scanf("%d",&a);
            b = a;
            update(1,1,n,dfm[a],dfm[a]+siz[a]-1,val[a]);
            if(zhuangtai[a]){zhuangtai[a]=2;continue;}
            zhuangtai[a]=2;
            a = fa[a];
            while(!zhuangtai[a]){
                zhuangtai[a]=1;
                update(1,1,n,dfm[a],dfm[b]-1,val[a]);
                if(dfm[b]<dfm[a]+siz[a]-1){update(1,1,n,dfm[b]+siz[b],dfm[a]+siz[a]-1,val[a]);}
                b = a;
                a = fa[a];
            }
            if(zhuangtai[a]==1){
                zhuangtai[a]=2;
                update(1,1,n,dfm[a],dfm[a]+siz[a]-1,val[a]);
            }
        }
        else{
            scanf("%d",&a);
            b = chaxun(1,1,n,dfm[a],dfm[a]);
            if(b){printf("%d\n",b);}
            else{printf("-1\n");}
        }
    }
    return 0;
}