#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
struct node{
    int val;
    int id;
}p[N];
bool bijiao(node & n1,node & n2){
    return n1.val<n2.val;
}
int daxiao[N];
int head[N],to[N<<1],nex[N<<1],ent;
int fa[N],siz[N],son[N],top[N],deep[N];
int root[N];
int num[N<<6],ls[N<<6],rs[N<<6];
int n;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void push_up(int p){num[p]=num[ls[p]]+num[rs[p]];}
void dfs1(int s,int f){
    fa[s]=f;
    deep[s]=deep[f]+1;
    int i;
    siz[s]=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        if(siz[to[i]]>siz[son[s]]){son[s]=to[i];}
        siz[s]+=siz[to[i]];
    }
}
void build(int last,int & now,int pl,int pr,int id){
    now = ++ent;
    if(pl==pr){num[now]=1;return ;}
    int mid=(pl+pr)>>1;
    if(id<=mid){
        rs[now]=rs[last];
        build(ls[last],ls[now],pl,mid,id);
    }
    else{
        ls[now]=ls[last];
        build(rs[last],rs[now],mid+1,pr,id);
    }
    push_up(now);
}
void dfs2(int s,int topx){
    top[s]=topx;
    build(root[fa[s]],root[s],1,n,daxiao[s]);
    if(son[s]){dfs2(son[s],topx);}
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s]){continue;}
        dfs2(to[i],to[i]);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){return y;}
    return x;
}
int chaxun(int r1,int r2,int r3,int r4,int k,int pl,int pr){
    if(pl==pr){return pl;}
    int mid=(pl+pr)>>1;
    int nu=num[ls[r1]]+num[ls[r2]]-num[ls[r3]]-num[ls[r4]];
    if(nu>=k){
        return chaxun(ls[r1],ls[r2],ls[r3],ls[r4],k,pl,mid);
    }
    else{
        return chaxun(rs[r1],rs[r2],rs[r3],rs[r4],k-nu,mid+1,pr);
    }
}
int main(){
    int i,q,a,b,last=0,k,c;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].val);
        p[i].id=i;
    }
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<=n;i++){daxiao[p[i].id]=i;}
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    ent=0;
    dfs1(1,0);
    dfs2(1,1);
    while(q--){
        scanf("%d %d %d",&a,&b,&k);
        a = a^last;
        c = lca(a,b);
        last = chaxun(root[a],root[b],root[fa[c]],root[c],k,1,n);
        last = p[last].val;
        printf("%d\n",last);
    }
    return 0;
}
