#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
int head[N],to[N],nex[N],ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int dp[N];
int siz[N];
void dfs(int s){
    int i,m=0,ma=0,sum=0,x;
    for(i=head[s];i;i=nex[i]){
        dfs(to[i]);
        siz[s] += siz[to[i]];
        sum += dp[to[i]];
        if(dp[to[i]]>=ma){
            m = to[i];
            ma = dp[to[i]];
        }
    }
    sum = sum-ma;
    if(ma>sum){
        x = siz[s]-siz[m];
        if(ma>x){dp[s]=ma-x;}
        else{dp[s]=(ma+sum)&1;}
    }
    else{dp[s]=(ma+sum)&1;}
    dp[s]++;
    siz[s]++;
}
int main(){
    int T,n,i,a;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=2;i<=n;i++){
            scanf("%d",&a);
            adde(a,i);
        }
        dfs(1);
        printf("%d\n",(n-dp[1])/2);
        for(i=1;i<=n;i++){
            head[i]=0;
            dp[i]=0;
            siz[i]=0;
        } 
        ent=0;
    }
    return 0;
}