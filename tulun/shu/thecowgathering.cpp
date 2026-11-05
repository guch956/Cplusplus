#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int head[N],to[N<<1],nex[N<<1],ent;
int head1[N],to1[N<<1],nex1[N<<1],ent1;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void adde1(int u,int v){
    ent1++;
    to1[ent1]=v;
    nex1[ent1]=head1[u];
    head1[u]=ent1;
}
int fa[N];
int f[N],siz[N],dfn[N],dfm,deep[N];
int From[N],To[N];
void dfs(int s,int ff){
    int i;
    f[s]=ff;
    dfn[s]=++dfm;
    deep[s]=deep[ff]+1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==ff){continue;}
        dfs(to[i],s);
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
}
int headq[N],toq[N],nexq[N],entq;
void addq(int u,int v){
    entq++;
    toq[entq]=v;
    nexq[entq]=headq[u];
    headq[u]=entq;
}
int zhan[N],top;
bool fail;
bool vis[N];
int vi[N];
void dfs2(int s,int ff){
    int i;
    zhan[++top]=s;
    for(i=headq[s];i;i=nexq[i]){
        if(fa[f[zhan[toq[i]]]]==0 || fa[f[zhan[toq[i]]]]==zhan[toq[i]]){
            fa[f[zhan[toq[i]]]]=zhan[toq[i]];
        }
        else{
            fail=1;
        }
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==ff){continue;}
        dfs2(to[i],s);
    }
    top--;
}
void dfs3(int s,int ff){
    vis[s]=1;
    if(fa[s]!=0 && fa[s]!=ff){fail=1;return;}
    else{fa[s]=ff;}
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==ff){continue;}
        dfs3(to[i],s);
    }
}
void dfs4(int s,int ff){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==ff){continue;}
        adde1(s,to[i]);
        dfs4(to[i],s);
    }
}
void dfs5(int s){
    int i;
    vi[s]=1;
    for(i=head1[s];i;i=nex1[i]){
        if(vi[to1[i]]==1){
            fail=1;
        }
        if(!vi[to1[i]]){
            dfs5(to1[i]);
        }
    }
    vi[s]=2;
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    for(i=1;i<=m;i++){
        scanf("%d %d",&To[i],&From[i]);
        if(dfn[From[i]]>=dfn[To[i]] && dfn[From[i]]<=dfn[To[i]]+siz[To[i]]-1){
            addq(From[i],deep[To[i]]+1);
        }
        else{
            if(fa[To[i]]==0 || fa[To[i]]==f[To[i]]){
                fa[To[i]]=f[To[i]];
            }
            else{
                fail=1;
            }
        }
    }
    dfs2(1,0);
    for(i=1;i<=n;i++){
        if(!vis[i] && fa[i]){
            dfs3(i,fa[i]);
        }
    }
    if(!fail){
        a = 1;
        while(fa[a]){
            a = fa[a];
        }
        for(i=1;i<=m;i++){
            adde1(From[i],To[i]);
        }
        dfs4(a,6666666);
        dfs5(a);
    }
    if(fail){
        for(i=1;i<=n;i++){
            printf("0\n");
        }
    }
    else{
        for(i=1;i<=n;i++){
            if(vis[i]){
                printf("0\n");
            }
            else{
                printf("1\n");
            }
        }
    }
    return 0;
}

