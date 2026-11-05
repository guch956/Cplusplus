#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=302;
int dp[N][N][2];
int x[N];
int main(){
    int n,m,i,j,k,ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    sort(x+1,x+n+1);
    for(i=1;i<=n;i++){
        dp[i][i][0]=x[i]<0?x[i]:-x[i];
        dp[i][i][0]+=m;
        dp[i][i][1]=dp[i][i][0];
        ans = max(ans,dp[i][i][0]);
    }
    for(i=2;i<=n;i++){
        for(j=i-1;j>=1;j--){
            dp[j][i][0]=max(dp[j+1][i][0]-x[j+1],dp[j+1][i][1]-x[i])+m+x[j];
            dp[j][i][1]=max(dp[j][i-1][0]+x[j],dp[j][i-1][1]+x[i-1])-x[i]+m;
            ans = max(ans,max(dp[j][i][0],dp[j][i][1]));
        }
    }
    printf("%d",ans);
    return 0;
}