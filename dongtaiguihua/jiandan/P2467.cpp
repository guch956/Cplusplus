#include<iostream>
#include<cstdio>
using namespace std;
int dp[5000][2][2];
int main(){
    int n,P,i,a;
    int now=1,old=0;
    int ans=0;
    scanf("%d %d",&n,&P);
    dp[1][0][0]=dp[1][1][0]=1;
    for(i=2;i<=n;i++){
        dp[i][0][now] = 0;
        for(a=i-1;a>=1;a--){
            dp[a][0][now] = (dp[a+1][0][now]+dp[a][1][old])%P;
        }
        dp[1][1][now] = 0;
        for(a=2;a<=i;a++){
            dp[a][1][now] = (dp[a-1][1][now]+dp[a-1][0][old])%P;
        }
        swap(old,now);
    }
    for(i=1;i<=n;i++){
        ans = (ans+dp[i][1][old])%P;
        ans = (ans+dp[i][0][old])%P;
    }
    printf("%d",ans);
    return 0;
}