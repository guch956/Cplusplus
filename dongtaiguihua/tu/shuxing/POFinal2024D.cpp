#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int dp[N],siz[N];
int nex[N],to[N],head[N],ent,m;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s){
    int i;
    siz[s]=1;
    dp[s]=0;
    for(i=head[s];i;i=nex[i]){
        dfs(to[i]);
        dp[s]+=dp[to[i]];
        siz[s]+=siz[to[i]];
    }
    if(siz[s]>m){siz[s]=0;dp[s]++;}
}
int main(){
    int n,i,a,k,l,r;
    scanf("%d %d",&n,&k);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        adde(a,i);
    }
    l = 0;r = n;
    while(l<r){
        m = (l+r)>>1;
        dfs(1);
        if(dp[1]<=k){r = m;}
        else{l = m+1;}
    }
    printf("%d",l);
    return 0;
}