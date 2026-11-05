#include<iostream>
#include<cstdio>
using namespace std;
const int N=7103;
#define ll long long
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[N][N];
int q[N],head,tail;
ll daijia[N];
int n;
void jisuan(){
    int i,j,k,s,t;
    for(k=2;k<=n;k++){
        s = k;
        head=1;
        tail=2;
        q[head]=k-1;
        for(i=k-1;i>=1;i--){
            dp[i][k]=INF;
            while(dp[i][s-1]>dp[s][k]){
                if(head<tail && q[head]==s-1){
                    head++;
                }
                s--;
            }
            dp[i][k]=min(dp[i][k],dp[i][s]+daijia[s]);
            t = q[head];
            dp[i][k]=min(dp[i][k],dp[t+1][k]+daijia[t]);
            while(tail>head && daijia[i-1]+dp[i][k] <= daijia[q[tail-1]]+dp[q[tail-1]+1][k]){
                tail--;
            }
            q[tail]=i-1;
            tail++;
        }
    }
    printf("%lld\n",dp[1][n]);
}
int main(){
    int T,i;
    scanf("%d",&T);
    while(T){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&daijia[i]);
        }
        jisuan();
        T--;
    }
    return 0;
}