#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int ma;
    int add;
    int fuzhi;
}t[N<<2];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void push_up(int p){
    t[p].ma=max(t[ls(p)].ma,t[rs(p)].ma);
}
inline void addtag(int p,int d){
    t[p].ma+=d;
    t[p].add+=d;
}
inline void fuzhitag(int p,int d){
    t[p].ma=d;
    t[p].add=0;
    t[p].fuzhi=d;
}
inline void push_down(int p){
    if(t[p].fuzhi!=-1){
        fuzhitag(ls(p),t[p].fuzhi);
        fuzhitag(rs(p),t[p].fuzhi);
        t[p].fuzhi=-1;
    }
    addtag(ls(p),t[p].add);
    addtag(rs(p),t[p].add);
    t[p].add=0;
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return t[p].ma;}
    int mid=(pl+pr)>>1,ans=-0x3f3f3f3f;
    push_down(p);
    if(l<=mid)ans = max(ans,chaxun(ls(p),pl,mid,l,r));
    if(r>mid)ans = max(ans,chaxun(rs(p),mid+1,pr,l,r));
    return ans;
}
void updfuzhi(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){fuzhitag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid)updfuzhi(ls(p),pl,mid,l,r,d);
    if(r>mid)updfuzhi(rs(p),mid+1,pr,l,r,d);
    push_up(p);
}
void updadd(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid)updadd(ls(p),pl,mid,l,r,d);
    if(r>mid)updadd(rs(p),mid+1,pr,l,r,d);
    push_up(p);
}
int head[N],nex[N<<1],to[N<<1],ent;
int edge[N][3];
int deep[N],fa[N],son[N],siz[N],top[N],dfm[N];
int dfn,n;
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
        if(siz[to[i]]>siz[son[s]])son[s]=to[i];
    }
}
void dfs2(int s,int topx){
    int i;
    top[s]=topx;
    dfm[s]=++dfn;
    if(son[s])dfs2(son[s],topx);
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s])continue;
        dfs2(to[i],to[i]);
    }
}
int query(int a,int b){
    int ans=-0x3f3f3f3f;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        ans = max(ans,chaxun(1,1,n,dfm[top[a]],dfm[a]));
        a = fa[top[a]];
    }
    if(deep[a]>deep[b]){swap(a,b);}
    if(a!=b)ans = max(ans,chaxun(1,1,n,dfm[a]+1,dfm[b]));
    return ans;
}
void add(int a,int b,int d){
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        updadd(1,1,n,dfm[top[a]],dfm[a],d);
        a = fa[top[a]];
    }
    if(deep[a]>deep[b]){swap(a,b);}
    if(a!=b)updadd(1,1,n,dfm[a]+1,dfm[b],d);
}
void fuzhi(int a,int b,int d){
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]])swap(a,b);
        updfuzhi(1,1,n,dfm[top[a]],dfm[a],d);
        a = fa[top[a]];
    }
    if(deep[a]>deep[b]){swap(a,b);}
    if(a!=b)updfuzhi(1,1,n,dfm[a]+1,dfm[b],d);
}
int main(){
    int i,a,b,d;
    char s[10];
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
        adde(edge[i][0],edge[i][1]);
        adde(edge[i][1],edge[i][0]);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(i=1;i<n;i++){
        if(fa[edge[i][1]]==edge[i][0])swap(edge[i][0],edge[i][1]);
        updfuzhi(1,1,n,dfm[edge[i][0]],dfm[edge[i][0]],edge[i][2]);
    }
    while(1){
        scanf("%s",s);
        if(s[1]=='a'){
            scanf("%d %d",&a,&b);
            printf("%d\n",query(a,b));
        }
        else if(s[1]=='d'){
            scanf("%d %d %d",&a,&b,&d);
            add(a,b,d);
        }
        else if(s[1]=='h'){
            scanf("%d %d",&a,&d);
            updfuzhi(1,1,n,dfm[edge[a][0]],dfm[edge[a][0]],d);
        }
        else if(s[1]=='o'){
            scanf("%d %d %d",&a,&b,&d);
            fuzhi(a,b,d);
        }
        else break;
    }
    return 0;
}