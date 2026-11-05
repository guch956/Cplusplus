#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200003;
const int INF=0x3f3f3f3f;
int tree[N<<2];
int tag[N<<2];
bool exist[N];
int nidfm[N];
int dao[N];
int ran[N];
queue<int> q;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline void push_up(int p){tree[p]=min(tree[ls(p)],tree[rs(p)]);}
void addtag(int p,int d){
    tree[p]+=d;
    tag[p]+=d;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
void find(int p,int pl,int pr){
    if(tree[p]>0){return ;}
    if(pl==pr){
        if(exist[nidfm[pl]]){
            q.push(nidfm[pl]);
        }
        tree[p]=INF;
        return ;
    }
    push_down(p);
    int mid=(pl+pr)>>1;
    find(ls(p),pl,mid);
    find(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){
        addtag(p,d);
        find(p,pl,pr);
        return ;
    }
    push_down(p);
    int mid=(pl+pr)>>1;
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
int head[N],to[N<<1],nex[N<<1],ent;
int deep[N],top[N],siz[N],fa[N],son[N];
int weizhi[N],num,n;
int dfm[N],dfn;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    deep[s]=deep[f]+1;
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
    dfm[s]=++dfn;
    nidfm[dfn]=s;
    top[s]=topx;
    if(son[s]){dfs2(son[s],topx);}
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s]){continue;}
        dfs2(to[i],to[i]);
    }
}
void chaxun(int p,int pl,int pr,int x){
    if(pl==pr){
        if(tree[p]==1){
            q.push(nidfm[x]);
            tree[p]=INF;
        }
        tree[p]--;
        return ;
    }
    push_down(p);
    int mid=(pl+pr)>>1;
    if(x<=mid){chaxun(ls(p),pl,mid,x);}
    else{chaxun(rs(p),mid+1,pr,x);}
    push_up(p);
}
void update1(int x,int y,int d){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        update(1,1,n,dfm[top[x]],dfm[x],d);
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){swap(x,y);}
    update(1,1,n,dfm[x],dfm[y],d);
}
int main(){
    int m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        dao[a]=b;
        update1(a,b,1);
        exist[a]=1;
        ran[a]=i;
    }
    for(i=1;i<=n;i++){
        if(exist[i]){
            chaxun(1,1,n,dfm[i]);
        }
    }
    while(q.size()){
        a = q.front();
        q.pop();
        weizhi[++num]=a;
        //update(1,1,n,dfm[a],dfm[a],1);a处已赋值INF，无所谓是否+1
        update1(a,dao[a],-1);
    }
    if(num==m){
        printf("Yes\n");
        for(i=num;i>=1;i--){
            printf("%d ",ran[weizhi[i]]);
        }
    }
    else{printf("No");}
    return 0;
}