#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int head[N],nex[N<<1],to[N<<1],ent;
int dp[N];
int col[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    dp[s]=col[s];
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        dp[s]+=max(dp[to[i]],0);
    }
}
void dfs2(int s,int f){
    int i,a;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        a = dp[s]-max(dp[to[i]],0);
        dp[to[i]]+=max(a,0);
        dfs2(to[i],s);
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&col[i]);
        col[i]=col[i]==0?-1:col[i];
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(i=1;i<=n;i++){
        printf("%d ",dp[i]);
    }
    return 0;
}