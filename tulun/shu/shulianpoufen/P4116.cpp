#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int son[N],fa[N],top[N],dfm[N],siz[N],dfn;
int to[N<<1],nex[N<<1],head[N<<1],ent;
int tree[N<<2];
int black[N];
void adde(int u,int v){
    ent++;
    to[ent] = v;
    nex[ent] = head[u];
    head[u] = ent;
}
void dfs1(int s,int f){
    int i;
    fa[s] = f;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){
            continue;
        }
        dfs1(to[i],s);
        if(siz[to[i]]>siz[son[s]]){
            son[s] = to[i];
        }
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
}
void dfs2(int s,int t){
    int i;
    top[s] = t;
    dfm[s] = ++dfn;
    if(son[s]){
        dfs2(son[s],t);
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s]){
            continue;
        }
        dfs2(to[i],to[i]);
    }
}
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline void pushup(int p){
    if(tree[ls(p)]){tree[p] = tree[ls(p)];}
    else{ tree[p] = tree[rs(p)];}
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1,a=0;
    if(l<=mid){a = chaxun(ls(p),pl,mid,l,r);}
    if(a==0 && r>mid){a = chaxun(rs(p),mid+1,pr,l,r);}
    return a;
} 
void change(int p,int pl,int pr,int x,int d){
    if(pl==pr){tree[p] = d;return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){change(ls(p),pl,mid,x,d);}
    else{change(rs(p),mid+1,pr,x,d);}
    pushup(p);
}
int main(){
    int n,q,i,a,b,ans;
    scanf("%d %d",&n,&q);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,0);
    dfs2(1,1);
    while(q--){
        scanf("%d %d",&i,&a);
        if(i==0){
            black[a] = black[a]^1;
            change(1,1,n,dfm[a],a*black[a]);
        }
        else{
            ans = -1;
            while(a){
                b = chaxun(1,1,n,dfm[top[a]],dfm[a]);
                ans = b?b:ans; 
                a = fa[top[a]];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}