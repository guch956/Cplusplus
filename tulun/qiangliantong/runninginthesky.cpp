#include<iostream>
#include<cstdio>
const int N=200003,M=2000003;
using namespace std;
struct edge{
    int to;
    int next;
};
edge g[M];int ent=1;
int head[N];int dp[N],dmax[N];
int w[N];
int stack[N],top;int num[N],low[N];
int df;int n;
int dian[N];int suodian[N];int dianmax[N];int numb;
int newhead[N];
int max1,max2;
void addedge(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
void addnew(int u,int v){
    g[ent].to=v;
    g[ent].next=newhead[u];
    newhead[u]=ent;
    ent++;
}
void tarjan(int s){
    int i,v;
    df++;num[s]=df;low[s]=df;
    stack[top]=s;top++;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(!num[v]){
            tarjan(v);
            low[s]=min(low[s],low[v]);
        }
        else if(!suodian[v]){
            low[s]=min(low[s],low[v]);
        }
    }
    if(low[s]==num[s]){
        numb++;
        while(1){
            top--;
            suodian[stack[top]]=numb;
            dian[numb]+=w[stack[top]];
            dianmax[numb]=max(dianmax[numb],w[stack[top]]);
            if(stack[top]==s){
                break;
            }
        }
    }
}
void dfs(int s){
    int i,v;
    for(i=newhead[s];i;i=g[i].next){
        v = g[i].to;
        if(!dp[v]){
            dfs(v);
        }
        if(dp[v]>dp[s]){
            dp[s]=dp[v];
            dmax[s]=dmax[v];
        }
        else if(dp[v]==dp[s]){
            dmax[s]=max(dmax[s],dmax[v]);
        }
    }
    dp[s]+=dian[s];
    dmax[s]=max(dmax[s],dianmax[s]);
}
void jisuan(){
    int i,j,v;
    for(i=1;i<=n;i++){
        if(!suodian[i]){
            tarjan(i);
        }
    }
    for(i=1;i<=n;i++){
        for(j=head[i];j;j=g[j].next){
            v = g[j].to;
            if(suodian[i]!=suodian[v]){
                addnew(suodian[i],suodian[v]);
            }
        }
    }
    for(i=1;i<=numb;i++){
        if(!dp[i]){
            dfs(i);
        }
    }
    for(i=1;i<=numb;i++){
        if(dp[i]>max1){
            max1=dp[i];
            max2=dmax[i];
        }
        else if(dp[i]==max1){
            max2=max(max2,dmax[i]);
        }
    }
}
int main(){
    int i,m,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    while(m){
        scanf("%d %d",&a,&b);
        addedge(a,b);
        m--;
    }
    jisuan();
    printf("%d %d",max1,max2);
    return 0;
}
