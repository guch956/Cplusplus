#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
const int LEN=30;
struct {
    int son[2];
    int siz;
}t[N*LEN];
int p[50];
int root[N];
int ent;
int dfn;
int z[N];
int dfm[N],top[N],fa[N],son[N],siz[N];
int deep[N];
struct {
    int to;
    int next;
}g[N<<1];
int head[N],cnt;
void adde(int u,int v){
    cnt++;
    g[cnt].to=v;
    g[cnt].next=head[u];
    head[u]=cnt;
}
void dfs1(int s,int f){
    int v,i;
    deep[s]=deep[f]+1;
    siz[s]=1;
    fa[s]=f;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
        siz[s]+=siz[v];
        if(siz[v]>siz[son[s]]){
            son[s]=v;
        }
    }
}
void getp(int x){
    for(int i=LEN-1;i>=0;i--){
        p[i]=x&1;
        x=x>>1;
    }
}
int newnode(int si){
    ent++;
    t[ent].siz=si;
    return ent;
}
void insert(int *s,int k){
    int i,now=root[k-1],r=root[k];
    for(i=0;i<LEN;i++){
        t[r].son[s[i]]=newnode(t[t[now].son[s[i]]].siz+1);
        t[r].son[s[i]^1]=t[now].son[s[i]^1];
        now=t[now].son[s[i]];
        r=t[r].son[s[i]];
    }
}
int chaxun(int l,int r,int *s){
    int i,now1=root[l-1],now2=root[r],a1,a2;
    int ans=0;
    for(i=0;i<LEN;i++){
        a1=t[now1].son[s[i]^1];
        a2=t[now2].son[s[i]^1];
        if(t[a1].siz<t[a2].siz){
            ans+=1<<(LEN-i-1);
            now1=a1;
            now2=a2;
        }
        else{
            now1=t[now1].son[s[i]];
            now2=t[now2].son[s[i]];
        }
    }
    return ans;
}
void dfs2(int s,int topx){
    int v,i;
    dfm[s]=++dfn;
    top[s]=topx;
    getp(z[s]);
    root[dfn]=newnode(t[root[dfn-1]].siz+1);
    insert(p,dfn);
    if(son[s]){
        dfs2(son[s],topx);
    }
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==fa[s] || v==son[s]){continue;}
        dfs2(v,v);
    }
}
int chaxun1(int s,int x){
    getp(x);
    return chaxun(dfm[s],dfm[s]+siz[s]-1,p);
}
int chaxun2(int a,int b,int x){
    getp(x);
    int ans=0;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]]){
            swap(a,b);
        }
        ans=max(ans,chaxun(dfm[top[a]],dfm[a],p));
        a = fa[top[a]];
    }
    if(deep[a]<deep[b]){
        swap(a,b);
    }
    ans=max(ans,chaxun(dfm[b],dfm[a],p));
    return ans;
}
int main(){
    int n,m,i,a,b,c,x;
    root[0]=newnode(1);
    n = root[0];
    for(i=0;i<LEN;i++){
        t[n].son[0]=newnode(1);
        n = t[n].son[0];
    }
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&z[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    while(m--){
        scanf("%d",&c);
        if(c==1){
            scanf("%d %d",&a,&x);
            printf("%d\n",chaxun1(a,x));
        }
        else{
            scanf("%d %d %d",&a,&b,&x);
            printf("%d\n",chaxun2(a,b,x));
        }
    }
    return 0;
}
