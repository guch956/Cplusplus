#include<iostream>
#include<cstdio>
using namespace std;
int dp[10002][2];
int shui[102];
int rongl[102];
const int INF=0x3f3f3f3f;
int main(){
    int n,m,i,j,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&shui[i]);
        sum+=shui[i];
    }
    for(i=1;i<=n;i++){
        scanf("%d",&rongl[i]);
    }
    for(i=1;i<=sum;i++){
        dp[i][0]=INF;
    }
    for(i=1;i<=n;i++){
        for(j=sum;j>=rongl[i];j--){
            if(dp[j-rongl[i]][0] <= dp[j][0]-2){
                dp[j][0]=dp[j-rongl[i]][0]+1;
                dp[j][1]=dp[j-rongl[i]][1]+shui[i];
            }
            else if(dp[j-rongl[i]][0] == dp[j][0]-1){
                dp[j][1]=max(dp[j][1],dp[j-rongl[i]][1]+shui[i]);
            }
        }
        for(j=rongl[i]-1;j>=1;j--){
            if(dp[j][0]>=2){
                dp[j][1]=shui[i];
            }
            else{
                dp[j][1]=max(dp[j][1],shui[i]);
            }
            dp[j][0]=1;
        }
    }
    printf("%d %d",dp[sum][0],sum-dp[sum][1]);
    return 0;
}
