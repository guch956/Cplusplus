#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int head[N],to[N<<1],nex[N<<1],ent;
int deep[N],top[N],siz[N],son[N],fa[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    deep[s]=deep[f]+1;
    siz[s]=1;
    fa[s]=f;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        if(siz[to[i]]>siz[son[s]]){son[s]=to[i];}
        siz[s]+=siz[to[i]];
    }
}
void dfs2(int s,int topx){
    int i;
    top[s]=topx;
    if(son[s]){dfs2(son[s],topx);}
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
    if(deep[x]<deep[y])return x;
    return y;
}
int dis(int x,int y){
    int z=lca(x,y);
    return deep[x]+deep[y]-2*deep[z];
}
int main(){
    int T,n,i,a,b,x,y,k,s;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d %d",&x,&y,&a,&b,&k);
        s = dis(a,b);
        if(k>=s && ((k-s)&1)==0){printf("YES\n");}
        else{
            s = min(dis(a,x)+1+dis(y,b),dis(a,y)+1+dis(x,b));
            if(k>=s && ((k-s)&1)==0){
                printf("YES\n");
            }
            else{printf("NO\n");}
        }
    }
    return 0;
}