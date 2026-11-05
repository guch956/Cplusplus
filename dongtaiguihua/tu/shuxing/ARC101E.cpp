#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=5005;
const ll P=1e9+7;
ll dp[N][N];
ll linshi[N];
int siz[N];
int head[N],nex[N<<1],to[N<<1],ent;
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void dfs(int s,int f){
    int i,j,k,su=1;
    siz[s]=1;
    dp[s][1]=1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        su+=siz[to[i]];
        for(j=0;j<=su;j++){linshi[j]=0;}
        for(j=siz[s];j>=0;j--){
            for(k=1;k<=siz[to[i]];k++){
                dp[s][j+k]=(dp[s][j]*dp[to[i]][k]%P+dp[s][j+k])%P;
                linshi[j+k]=(j*dp[s][j]%P*k%P*dp[to[i]][k]%P+linshi[j+k])%P;
            }
            dp[s][j]=0;
        }
        for(j=su;j>=0;j--){
            dp[s][j]=(dp[s][j]+linshi[s+2])%P;
        }
        siz[s]=su;
    }
}
int main(){
    return 0;
}
