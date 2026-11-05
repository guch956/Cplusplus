#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=18;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[1<<N][N+1];
ll g[N+1][N+1];
ll m[N+1];
struct node{
    ll sum;
    ll *dp1;
}p[1<<N];
bool bijiao(node & n1,node & n2){
    return n1.sum<n2.sum;
}
int q[1<<N][N+1];
int head[N+1],tail[N+1];
int main(){
    int n,me,i,a,b,Q,j,k;
    ll c;
    scanf("%d %d",&n,&me);
    for(i=1;i<=n;i++){
        scanf("%lld",&m[i]);
    }
    for(i=1;i<=me;i++){
        scanf("%d %d %lld",&a,&b,&c);
        g[b][a]=c;
    }
    Q = (1<<n)-1;
    for(i=1;i<=Q;i++){
        for(j=1;j<=n;j++){
            if(i==(1<<(j-1))){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=INF;
            }
            if(i&(1<<(j-1))){
                p[i].sum=p[i-(1<<(j-1))].sum+m[j];
                for(k=1;k<=n;k++){
                    if(g[j][k]!=0 && i&(1<<(k-1))){
                        dp[i][j]=min(dp[i][j],dp[i-(1<<(j-1))][k]+g[j][k]*m[k]);
                    }
                }
            }
            p[i].dp1=dp[i];
        }
    }
    sort(p+1,p+1+Q,bijiao);
    for(i=1;i<=n;i++){
        head[i]=tail[i]=1;
        q[tail[i]][i]=0;
        for(j=1;j<=Q;j++){
            while(head[i]<tail[i] && 
            (p[j].dp1[i]-p[q[tail[i]][i]].dp1[i])*(p[q[tail[i]][i]].sum-p[q[tail[i]-1][i]].sum)<=
            (p[q[tail[i]][i]].dp1[i]-p[q[tail[i]-1][i]].dp1[i])*(p[j].sum-p[q[tail[i]][i]].sum)){
                tail[i]--;
            }
            q[++tail[i]][i]=j;
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d")
    }
    return 0;
}
