#include<iostream>
#include<cstdio>
using namespace std;
const int N=300003;
struct {
    int to;
    int next;
    int len;
}g[N<<1];
int n;
int head[N],ent;
void adde(int u,int v,int w){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].len=w;
    head[u]=ent;
}
int fa[N],siz[N],son[N],top[N];
int juli[N];
int deep[N];
int lens[N],begin1[N],begin2[N],lcas[N];
int ma;
int m,num,ans;
void dfs(int s,int f){
    int v,i;
    deep[s]=deep[f]+1;
    siz[s]=1;
    fa[s]=f;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        juli[v]=juli[s]+g[i].len;
        dfs(v,s);
        if(siz[v]>siz[son[s]]){son[s]=v;}
        siz[s]+=siz[v];
    }
}
void dfs2(int s,int topx){
    int i,v;
    top[s]=topx;
    if(son[s]){dfs2(son[s],topx);}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==fa[s] || v==son[s]){continue;}
        dfs2(v,v);
    }
}
void lca(int k){
    int a=begin1[k],b=begin2[k];
    while(top[a]!=top[b]){
        if(deep[top[a]]<deep[top[b]]){swap(a,b);}
        a = fa[top[a]];
    }
    if(deep[a]>deep[b]){swap(a,b);}
    lcas[k]=a;
    lens[k]=juli[begin1[k]]-2*juli[a]+juli[begin2[k]];
    ma=max(ma,lens[k]);
}
void dfs1(int s,int f){
    int v,i;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs1(v,s);
            deep[s]+=deep[v];
        }
    }
    if(deep[s]==num){
        ans=max(ans,juli[s]-juli[fa[s]]);
    }
}
bool check(int z){
    int i;
    num=0;
    for(i=1;i<=n;i++){
        deep[i]=0;
    }
    for(i=1;i<=m;i++){
        if(lens[i]>z){
            deep[begin1[i]]++;
            deep[begin2[i]]++;
            deep[lcas[i]]-=2;
            num++;
        }
    }
    ans=0;
    dfs1(1,1);
    if(ans+z>=ma){return 1;}
    else{return 0;}
}
int erfen(){
    int l=0,r=ma,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){r = mid;}
        else{l = mid+1;}
    }
    return l;
}
int main(){
    int i,a,b,c;
    /*freopen("2.in","r",stdin);*/
    scanf("%d %d",&n,&m);
    for(i=1;i<=n-1;i++){
        scanf("%d %d %d",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dfs(1,1);
    dfs2(1,1);
    for(i=1;i<=m;i++){
        scanf("%d %d",&begin1[i],&begin2[i]);
        lca(i);
    }
    cout<<erfen();
    return 0;
}