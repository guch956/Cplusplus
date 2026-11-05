#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int fa[N];
int nex[N<<1],to[N<<1],head[N],ent;
int top[N],siz[N],son[N];
int deep[N];
int dfm[N],dfn;
int zhan[N];
bool xing[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    fa[s]=f;
    siz[s]=1;
    deep[s]=deep[f]+1;
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        if(siz[to[i]]>siz[son[s]]){son[s]=to[i];}
        siz[s]+=siz[to[i]];
    }
}
void dfs2(int s,int topx){
    int i;
    dfm[s]=++dfn;
    top[s]=topx;
    if(son[s]){dfs2(son[s],topx);}
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s]){continue;}
        dfs2(to[i],to[i]);
    }
}
int main(){
    int n,q,i,a,b,m,ma;
    scanf("%d %d",&n,&q);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    dfs2(1,1);
    while(q--){
        scanf("%d",&m);
        ma=0;
        for(i=1;i<=m;i++){
            scanf("%d",&zhan[i]);
            zhan[i]=fa[zhan[i]];
            xing[i]=0;
            if(deep[zhan[i]]>deep[ma]){ma=zhan[i];}
        }
        while(1){
            for(i=1;i<=m;i++){
                if(dfm[ma]>=dfm[zhan[i]] && dfm[zhan[i]]>=dfm[top[ma]]){xing[i]=1;}
            }
            if(ma==1){break;}
            ma = fa[top[ma]];
        }
        for(i=1;i<=m;i++){
            if(!xing[i]){break;}
        }
        if(i==m+1){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}