#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
const ll P=998244353;
ll dp[N][3];
int head[N],to[N<<1],nex[N<<1],id[N<<1],ent;
int fa[N];
void adde(int u,int v,int i){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    id[ent]=i;
    head[u]=ent;
}
bool bijiao(int p1,int p2){
    return fa[p1]<fa[p2];
}
int zhan[N];
ll chengji[N];
ll chengji2[N];
void dfs(int s,int f){
    int i,num=0,b=fa[s];
    ll ji=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        fa[s]=id[i];
        fa[to[i]]=id[i];
        dfs(to[i],s);
    }
    fa[s]=b;
    for(i=head[s];i;i=nex[i]){
        zhan[++num]=to[i];
    }
    sort(zhan+1,zhan+num+1,bijiao);
    int k;
    for(k=1;k<=num;k++){if(zhan[k]==f)break;}
    for(i=1;i<k;i++){
        chengji[i]=chengji[i-1]*(dp[zhan[i]][0]+dp[zhan[i]][1])%P;
    }
    chengji2[k]=1;
    for(i=k-1;i>=1;i--){
        chengji2[i]=chengji2[i+1]*(dp[zhan[i]][0]+dp[zhan[i]][2])%P;
    }
    for(i=k+1;i<=num;i++){ji = ji*(dp[zhan[i]][0]+dp[zhan[i]][2])%P;}
    for(i=1;i<k;i++){
        dp[s][0]=(dp[s][0]+chengji[i-1]*dp[zhan[i]][2]%P*chengji2[i+1]%P)%P;
    }
    dp[s][0]=dp[s][0]*ji%P;
    dp[s][1]=chengji[k-1]*ji%P;
    chengji[k]=1;
    chengji2[num+1]=1;
    for(i=k+1;i<=num;i++){
        chengji[i]=chengji[i-1]*(dp[zhan[i]][0]+dp[zhan[i]][1])%P;
    }
    for(i=num;i>k;i--){
        chengji2[i]=chengji2[i+1]*(dp[zhan[i]][0]+dp[zhan[i]][2])%P;
    }
    dp[s][2]=chengji[num];
    for(i=k+1;i<=num;i++){
        dp[s][2]=(dp[s][2]+chengji[i-1]*dp[zhan[i]][2]%P*chengji2[i+1]%P)%P;
    }
    dp[s][2]=dp[s][2]*chengji[k-1]%P;
}
int main(){
    int n,i,a,b;
    chengji[0]=1;
    scanf("%d",&n);
    adde(1,0,0);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b,i);
        adde(b,a,i);
    }
    dfs(1,0);
    printf("%lld",dp[1][2]);
    return 0;
}