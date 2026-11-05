#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
int head[N];
int nex[N<<1];
int to[N<<1];
int deep[N];
int son[N];
struct {
    int ma;
    int index;
    int fir;
}dp[N];
struct {
    int num;
    int nex;
}g[N];
int ent;
void adde(int a,int b){
    ent++;
    nex[ent] = head[a];
    to[ent] = b;
    head[a] = ent;
}
void dfs1(int s,int f){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f)continue;
        dfs1(to[i],s);
        if(deep[to[i]]>deep[son[s]]){
            son[s] = to[i];
            deep[s] = deep[son[s]];
        }
    }
    deep[s]++;
}
void dfs2(int s,int f){
    int i,j,d,k;
    ent++;
    dp[s].fir = ent;
    g[dp[s].fir].num = 1;
    if(son[s]){
        dfs2(son[s],s);
        g[dp[s].fir].nex = dp[son[s]].fir;
        if(dp[son[s]].ma>1){
            dp[s].index = dp[son[s]].index+1;
            dp[s].ma = dp[son[s]].ma;
        }
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f || to[i]==son[s])continue;
        dfs2(to[i],s);
        d = g[dp[s].fir].nex;
        k = 1;
        for(j = dp[to[i]].fir;j;j = g[j].nex){
            g[d].num += g[j].num;
            if(g[d].num>dp[s].ma){
                dp[s].ma = g[d].num;
                dp[s].index = k;
            }
            else if(g[d].num==dp[s].ma){
                dp[s].index = min(k,dp[s].index);
            }
            d = g[d].nex;
            k++;
        }
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,0);
    ent = 0;
    dfs2(1,0);
    for(i=1;i<=n;i++){
        printf("%d\n",dp[i].index);
    }
    return 0;
}