#include<iostream>
#include<cstdio>
using namespace std;
const int N=20003;
class tu{
    public:
        int head[N],to[N<<1],nex[N<<1],ent,len[N<<1];
        void adde(int u,int v,int l){
            ent++;
            to[ent]=v;
            nex[ent]=head[u];
            len[ent]=l;
            head[u]=ent;
        }
}g,g1;
int dfm[N],dfn,low[N];
int zhan[N],top;
int deep[N];
int n,num;
int dp[N];
void dfs(int s,int f){
    int i,v,len,d;
    zhan[++top]=s;
    dfm[s]=low[s]=++dfn;
    for(i=g1.head[s];i;i=g1.nex[i]){
        v = g1.to[i];
        if(v==f){continue;}
        if(dfm[v]){
            low[s]=min(low[s],dfm[v]);
        }   
        else{
            deep[v]=deep[s]+1;
            dfs(v,s);
            low[s]=min(low[v],low[s]);
            if(low[v]==dfm[s]){
                len = deep[zhan[top]]-deep[s]+1;
                num++;
                while(1){
                    d = deep[zhan[top]]-deep[s];
                    g.adde(num,zhan[top],max(len-d,d));
                    if(zhan[top--]==v){break;}
                }
                g.adde(s,num,len);
            }
            else if(low[v]>dfm[s]){
                g.adde(s,v,1);
            }
        }
    }
}
void dfs1(int s){
    int i,v,sum=0,d;
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        dfs1(v);
        if(v<=n)dp[s] = max(dp[s],dp[v]+g.len[i]);
        else sum+=g.len[i];
    }
    d=sum+dp[s];;
    for(i=g.head[s];i;i=g.nex[i]){
        v = g.to[i];
        if(v>n){
            dp[s] = max(dp[s],sum-g.len[i]+dp[v]);
        }
    }
    dp[s] = max(dp[s],d);
}
int main(){
    int m,i,a,b;
    scanf("%d %d",&n,&m);
    num = n;
    while(m--){
        scanf("%d %d",&a,&b);
        g1.adde(a,b,1);
        g1.adde(b,a,1);
    }
    dfs(1,1);
    dfs1(1);
    printf("%d",dp[1]);
    return 0;
}