#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=100003;
ll sum[N<<2];
ll tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    sum[p]=sum[ls(p)]+sum[rs(p)];
}
void addtag(int p,ll len,ll d){
    sum[p]+=len*d;
    tag[p]+=d;
}
void push_down(int p,ll len){
    addtag(ls(p),(len+1)>>1,tag[p]);
    addtag(rs(p),len>>1,tag[p]);
    tag[p]=0;
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return sum[p];}
    int mid=(pl+pr)>>1;ll a=0;
    push_down(p,pr-pl+1);
    if(l<=mid){a+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){a+=chaxun(rs(p),mid+1,pr,l,r);}
    return a;
}
class lian{
    public:
    int head[N],to[N<<1],nex[N<<1],other[N<<1],ent;
    lian(){ent=0;memset(head,0,sizeof(head));}
    void add(int u,int v,int o){
        ent++;
        to[ent]=v;
        nex[ent]=head[u];
        other[ent]=o;
        head[u]=ent;
    }
    void pop(int u){
        head[u] = nex[head[u]];
    }
}g,caozuo,t,ti;
int cz[N],col[N];
int tim[N];
int dfm[N],dfn;
bool type[N];
int siz[N];
ll ans[N];
void dfs(int s,int f){
    int i,v;
    siz[s]=1;
    dfm[s]=++dfn;
    for(i=t.head[s];i;i=t.nex[i]){
        if(tim[t.to[i]]>t.other[i]){
            caozuo.add(t.other[i],s,1);
            caozuo.add(tim[t.to[i]],s,-1);
            tim[t.to[i]]=t.other[i];
            ti.add(t.to[i],t.other[i],s);
        }
    }
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(v==f){continue;}
        dfs(v,s);
        siz[s]+=siz[v];
    }
    for(i=t.head[s];i;i=t.nex[i]){
        if(ti.other[ti.head[t.to[i]]]==s){
            ti.pop(t.to[i]);
            tim[t.to[i]]=ti.to[ti.head[t.to[i]]];
        }
    }
}
int main(){
    int n,i,a,b,q,j;
    scanf("%d %d",&n,&q);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g.add(a,b,0);
        g.add(b,a,0);
    }
    for(i=1;i<=1e5;i++){
        tim[i]=q+1;
        ti.add(i,q+1,0);
    }
    for(i=1;i<=q;i++){
        scanf("%d",&j);
        if(j==1){
            type[i]=1;
            scanf("%d %d",&cz[i],&col[i]);
            t.add(cz[i],col[i],i);
        }
        else{
            scanf("%d",&cz[i]);
        }
    }
    dfs(1,1);
    for(i=1;i<=q;i++){
        if(!type[i]){
            printf("%lld\n",chaxun(1,1,n,dfm[cz[i]],dfm[cz[i]]+siz[cz[i]]-1));
        }
        else{
            for(j=caozuo.head[i];j;j=caozuo.nex[j]){
                a = caozuo.to[j];
                update(1,1,n,dfm[a],dfm[a]+siz[a]-1,caozuo.other[j]);
            }
        }
    }
    return 0;
}
