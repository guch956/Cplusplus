#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=3831;
const int INF=2000000000;
int dp[2][N][2][2];
int p[N];
int main(){
    int n,i,j,b,now=1,old=0;
    int ans;
    scanf("%d %d",&n,&b);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    dp[old][0][1][1]=dp[old][0][1][0]=dp[old][0][0][1]=-INF;
    dp[old][1][0][1]=dp[old][1][1][0]=dp[old][1][0][0]=-INF;
    for(i=2;i<=n;i++){
        dp[now][0][1][1]=dp[now][0][1][0]=dp[now][0][0][1]=-INF;
        for(j=1;j<=i;j++){
            dp[now][j][1][1]=max(dp[old][j-1][1][1]+p[i],dp[old][j-1][1][0]);
            dp[now][j][0][1]=max(dp[old][j-1][0][1]+p[i],dp[old][j-1][0][0]);
            dp[now][j][1][0]=max(dp[old][j][1][1],dp[old][j][1][0]);
            dp[now][j][0][0]=max(dp[old][j][0][1],dp[old][j][0][0]);
        }
        swap(now,old);
    }
    dp[old][b][1][1]+=p[1];
    ans=max(dp[old][b][0][0],max(dp[old][b][0][1],max(dp[old][b][1][0],dp[old][b][1][1])));
    printf("%d",ans);
    return 0;
}