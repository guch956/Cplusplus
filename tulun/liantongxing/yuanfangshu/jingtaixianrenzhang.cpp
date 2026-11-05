#include<iostream>
#include<cstdio>
using namespace std;
const int N=10003;
class tu{
    public:
        int head[N<<1],nex[N<<2],to[N<<2],len[N<<2],ent;
        void adde(int u,int v,int l){
            ent++;
            to[ent]=v;
            nex[ent]=head[u];
            len[ent]=l;
            head[u]=ent;
        }
}g1,g;
int zhan[N],top;
int dfm[N<<1],low[N<<1],num,dfn;
int othlen[N<<1];
int deep[N];
int ndeep[N<<1];
int dep[N<<1],siz[N<<1],fa[N<<1],son[N<<1],topp[N<<1];
void dfs(int s,int f){
    int i,v,di;
    dfm[s]=low[s]=++dfn;
    zhan[++top]=s;
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(v==f){continue;}
        if(dfm[v]){
            low[s]=min(low[s],dfm[v]);
            othlen[v]=g1.len[i];
        }
        else{
            deep[v]=deep[s]+g1.len[i];
            dfs(v,s);
            low[s]=min(low[v],low[s]);
            if(low[v]==dfm[s]){
                num++;
                di = zhan[top];
                while(1){
                    g.adde(num,zhan[top],min(deep[zhan[top]]-deep[s],othlen[s]+deep[di]-deep[zhan[top]]));
                    fa[zhan[top]]=num;
                    if(zhan[top--]==v){break;}
                }
                g.adde(s,num,0);
                fa[num]=s;
                othlen[num]=othlen[s]+deep[di]-deep[s];
            }
            if(low[v]>dfm[s]){
                g.adde(s,v,g1.len[i]);
                fa[v]=s;
                top--;
            }
        }
    }
}
int dfs1(int s){
    int i,v;
    siz[s]=1;
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        ndeep[v]=ndeep[s]+g.len[i];
        dep[v]=dep[s]+1;
        dfs1(v);
        siz[s]+=siz[v];
        if(siz[v]>siz[son[s]]){son[s]=v;}
    }
}
void dfs2(int s,int topx){
    int i,v;
    topp[s]=topx;
    dfm[s]=++dfn;
    low[dfn]=s;
    if(son[s]){dfs2(son[s],topx);}
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(v==son[s]){continue;}
        dfs2(v,v);
    }
}
int lca(int x,int y){
    while(topp[x]!=topp[y]){
        if(dep[topp[x]]<dep[topp[y]]){swap(x,y);}
        x = fa[topp[x]];
    }
    if(dep[x]<dep[y])return x;
    return y;
}
int find(int a,int c){
    int la;
    while(topp[a]!=topp[c]){
        la = topp[a];
        a = fa[topp[a]];
    }
    if(a!=c){return low[dfm[c]+1];}
    return la;
}
int main(){
    int n,m,q,i,a,b,c,ans,x,y;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        g1.adde(a,b,c);
        g1.adde(b,a,c);
    }
    num = n;
    dfs(1,0);
    dfs1(1);
    dfn=0;
    dfs2(1,1);
    while(q--){
        scanf("%d %d",&a,&b);
        c = lca(a,b);
        if(c<=n){
            ans = ndeep[a]+ndeep[b]-2*ndeep[c];
        }
        else{
            x = find(a,c);
            y = find(b,c);
            if(deep[x]<deep[y]){swap(x,y);}
            ans = ndeep[a]+ndeep[b]-ndeep[x]-ndeep[y]+min(deep[x]-deep[y],othlen[c]-deep[x]+deep[y]);
        }
        printf("%d\n",ans);
    }
    return 0;
}