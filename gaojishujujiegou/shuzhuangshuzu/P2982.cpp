#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int head[N],to[N<<1],nex[N<<1],ent;
int tree[N];
int dfm[N],dfn,n;
int siz[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
inline int lowbit(int x){return x&(-x);}
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int chaxun(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void dfs(int s,int f){
    int i;
    dfm[s]=++dfn;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
}
int main(){
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        printf("%d\n",chaxun(dfm[a]));
        update(dfm[a],1);
        update(dfm[a]+siz[a],-1);
    }
    return 0;
}