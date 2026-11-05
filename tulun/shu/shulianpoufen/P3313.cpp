#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int sum;
    int ma;
    int ls;
    int rs;
}t[N*100];
int ent;
int root[N];
int xiny[N],w[N];
inline void push_up(int p){
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
    t[p].ma=max(t[t[p].ls].ma,t[t[p].rs].ma);
}
int add(int p,int pl,int pr,int x,int d){
    ent++;
    if(pl==pr){
        t[ent].ma=t[ent].sum=d;
        return ent;
    }
    int mid=(pl+pr)>>1,a=ent;
    if(x<=mid){
        t[a].rs=t[p].rs;
        t[a].ls=add(t[p].ls,pl,mid,x,d);
    }
    else{
        t[a].ls=t[p].ls;
        t[a].rs=add(t[p].rs,mid+1,pr,x,d);
    }
    push_up(a);
    return a;
}
int querymax(int p,int pl,int pr,int l,int r){
    if(p==0)return 0;
    if(l<=pl && r>=pr)return t[p].ma;
    int mid=(pl+pr)>>1,ans=0;
    if(l<=mid)ans = max(ans,querymax(t[p].ls,pl,mid,l,r));
    if(r>mid)ans = max(ans,querymax(t[p].rs,mid+1,pr,l,r));
    return ans;
}
int querysum(int p,int pl,int pr,int l,int r){
    if(p==0)return 0;
    if(l<=pl && r>=pr)return t[p].sum;
    int mid=(pl+pr)>>1,ans=0;
    if(l<=mid)ans+=querysum(t[p].ls,pl,mid,l,r);
    if(r>mid)ans+=querysum(t[p].rs,mid+1,pr,l,r);
    return ans;
}
int head[N],nex[N<<1],to[N<<1];
int deep[N],top[N],siz[N],son[N],fa[N];
int dfm[N],dfn,n;
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    deep[s]=deep[f]+1;
    siz[s]=1;
    fa[s]=f;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f)continue;
        dfs1(to[i],s);
        siz[s]+=siz[to[i]];
        if(siz[to[i]]>siz[son[s]])son[s]=to[i];
    }
}
void dfs2(int s,int topx){
    int i;
    dfm[s]=++dfn;
    top[s]=topx;
    if(son[s])dfs2(son[s],topx);
    for(i=head[s];i;i=nex[i]){
        if(to[i]==son[s] || to[i]==fa[s])continue;
        dfs2(to[i],to[i]);
    }
}
int chaxunmax(int a,int b){
    int x=xiny[a],ans=0;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]]){swap(a,b);}
        ans = max(ans,querymax(root[x],1,n,dfm[top[a]],dfm[a]));
        a = fa[top[a]];
    }
    if(deep[a]<deep[b])swap(a,b);
    ans = max(ans,querymax(root[x],1,n,dfm[b],dfm[a]));
    return ans;
}
int chaxunsum(int a,int b){
    int x=xiny[a],ans=0;
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]]){swap(a,b);}
        ans+=querysum(root[x],1,n,dfm[top[a]],dfm[a]);
        a = fa[top[a]];
    }
    if(deep[a]<deep[b]){swap(a,b);}
    ans+=querysum(root[x],1,n,dfm[b],dfm[a]);
    return ans;
}
int main(){
    int q,i,a,b,ans;
    char s[8];
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)scanf("%d %d",&w[i],&xiny[i]);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    ent=0;
    for(i=1;i<=n;i++){
        root[xiny[i]]=add(root[xiny[i]],1,n,dfm[i],w[i]);
    }
    while(q--){
        scanf("%s",s);
        scanf("%d %d",&a,&b);
        switch (s[1]){
            case 'C':
                root[xiny[a]]=add(root[xiny[a]],1,n,dfm[a],0);
                xiny[a]=b;
                root[xiny[a]]=add(root[xiny[a]],1,n,dfm[a],w[a]);
                break;
            case 'W':
                w[a]=b;
                root[xiny[a]]=add(root[xiny[a]],1,n,dfm[a],w[a]);
                break;
            case 'S':
                ans = chaxunsum(a,b);
                printf("%d\n",ans);
                break;
            case 'M':
                ans = chaxunmax(a,b);
                printf("%d\n",ans);
                break;
        }
    }
    return 0;
}