#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
#define ll long long
ll dp[N][23];
struct {
    int to;
    int next;
}g[N<<2];
int head[N],ent,kk;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int main(){
    int n,a,b,i,j,k;
    ll c;
    scanf("%d %d",&n,&kk);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&dp[i][0]);
    }
    for(j=1;j<=kk;j++){
        for(a=1;a<=n;a++){
            dp[a][j]=dp[a][0];
            for(i=head[a];i!=0;i=g[i].next){
                b = g[i].to;
                c = 1;
                for(k=j-1;k>=0;k--){
                    if(c==1)dp[a][j]+=dp[b][k];
                    else dp[a][j]-=dp[a][k];
                    c=1-c;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        printf("%lld\n",dp[i][kk]);
    }
    return 0;
}