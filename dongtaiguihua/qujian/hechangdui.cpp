#include<iostream>
#include<cstdio>
using namespace std;
const int N=1003;
const int P=19650827;
int dp[N][N][2];
int p[N];
int main(){
    int n,i,j,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
        dp[i][i][0]=0;
        dp[i][i][1]=1;
    }
    for(l=1;l<n;l++){
        for(i=1;i<=n-l;i++){
            j = i+l;
            if(p[i+1]>p[i]){
                dp[i][j][0]+=dp[i+1][j][0];
            }
            if(p[j]>p[i]){
                dp[i][j][0]+=dp[i+1][j][1];
                dp[i][j][1]+=dp[i][j-1][0];
            }
            dp[i][j][0]%=P;
            if(p[j-1]<p[j]){
                dp[i][j][1]+=dp[i][j-1][1];
            }
            dp[i][j][1]%=P;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%P;
    return 0;
}