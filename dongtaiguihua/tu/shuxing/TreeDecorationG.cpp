#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
ll num[N],dp[N];
ll danjia[N];
int to[N],nex[N],head[N],ent;
ll yaoqiu[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    for(i=head[s];i;i=nex[i]){
        dfs(to[i],s);
        num[s]+=num[to[i]];
        danjia[s]=min(danjia[s],danjia[to[i]]);
        dp[s]+=dp[to[i]];
    }
    if(num[s]<yaoqiu[s]){
        dp[s]+=(yaoqiu[s]-num[s])*danjia[s];
        num[s]=yaoqiu[s];
    }
}
int main(){
    int n,i,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %lld %lld",&a,&yaoqiu[i],&danjia[i]);
        if(i!=1){adde(a,i);}
    }
    dfs(1,1);
    printf("%lld",dp[1]);
    return 0;
}