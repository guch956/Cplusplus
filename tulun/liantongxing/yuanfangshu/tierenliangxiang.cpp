#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
int n,num;
class tu{
    public:
        int head[N],to[N<<1],nex[N<<1],ent;
        void adde(int u,int v){
            ent++;
            nex[ent]=head[u];
            to[ent]=v;
            head[u]=ent;
        }
}g,g1;
int dfn,dfm[N],low[N];
ll w[N];
ll siz[N],S;
int zhan[N],top;
ll ans;
void dfs(int s){
    int i,v;
    dfm[s]=low[s]=++dfn;
    w[s]=1;
    S++;
    zhan[++top]=s;
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(dfm[v]){
            low[s] = min(low[s],dfm[v]);
        }
        else{
            dfs(v);
            low[s] = min(low[s],low[v]);
            if(low[v]==dfm[s]){
                num++;
                w[num]=-1;
                while(1){
                    w[num]++;
                    g.adde(num,zhan[top]);
                    if(zhan[top--]==v){break;}
                }
                g.adde(s,num);
            }
        }
    }
}
void dfs1(int s){
    int i,v;
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        dfs1(v);
        ans+=2*w[s]*siz[s]*siz[v];
        siz[s]+=siz[v];
    }
    if(s<=n){
        siz[s]++;
        ans+=2*w[s]*(siz[s]-1)*(S-siz[s]);
    }
    else{ans+=2*w[s]*siz[s]*(S-siz[s]);}
}
int main(){
    int m,i,a,b;
    scanf("%d %d",&n,&m);
    num = n;
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g1.adde(a,b);
        g1.adde(b,a);
    }
    for(i=1;i<=n;i++){
        if(!dfm[i]){
            S=0;
            dfs(i);
            dfs1(i);
        }
    }
    printf("%lld",ans);
    return 0;
}