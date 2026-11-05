#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int deep[N];
int ans[N];
class lian{
    public:
    int head[N],nex[N<<1],to[N<<1],ent,other[N<<1];
    lian(){ent=0;}
    void add(int u,int v,int o){
        ent++;
        nex[ent]=head[u];
        to[ent]=v;
        other[ent]=o;
        head[u]=ent;
    }
    void pop(int u){head[u]=nex[head[u]];}
}g,q,p;
int fa[N];
int pinz[N];
int need[N];
int find(int x){
    if(x!=fa[x]){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
int lca[N];
void dfs1(int s,int f){
    int i;
    deep[s] = deep[f]+1;
    p.add(pinz[s],s,0);
    for(i=g.head[s];i;i=g.nex[i]){
        if(g.to[i]==f){continue;}
        dfs1(g.to[i],s);
        fa[find(g.to[i])]=s;
    }
    for(i=q.head[s];i;i=q.nex[i]){
        if(deep[q.to[i]]){
            lca[q.other[i]]=find(q.to[i]);
        }
        if(deep[p.to[p.head[need[q.other[i]]]]]>deep[ans[q.other[i]]]){
            ans[q.other[i]]=p.to[p.head[need[q.other[i]]]];
        }
    }
    p.pop(pinz[s]);
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&pinz[i]);
        fa[i]=i;
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g.add(a,b,0);
        g.add(b,a,0);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&need[i]);
        q.add(a,b,i);
        q.add(b,a,i);
    }
    dfs1(1,0);
    for(i=1;i<=m;i++){
        if(deep[lca[i]]<=deep[ans[i]]){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    return 0;
}
