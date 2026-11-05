#include<iostream>
using namespace std;
const int N=503;
int p[N];
int dp[N][N];
int main(){
    int n,i,l,r,k;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>p[i];
        dp[i][i]=1;
    }
    for(i=1;i<n;i++){
        for(l=1;l<=n-i;l++){
            r = l+i;
            dp[l][r]=1+dp[l+1][r];
            if(p[l]==p[l+1]){
                dp[l][r]=min(dp[l][r],1+dp[l+2][r]);
            }
            for(k=l+2;k<=r;k++){
                if(p[l]==p[k]){
                    dp[l][r]=min(dp[l][r],dp[l+1][k-1]+dp[k+1][r]);
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}