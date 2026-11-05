#include<iostream>
#include<cstdio>
using namespace std;
const int P=1e9+7;
int dp[503][503][2];
char A[503][503];
int main(){
    int n,i,j,k,now=1,old=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>A[i][j];
        }
    }
    for(i=1;i<=n;i++){
        dp[i][i][old]=1;
    }
    for(k=n-1;k>=1;k--){
        for(i=1;i<=k;i++){
            for(j=1;j<=k;j++){
                if(A[k+1-i][i]==A[n+1-j][n+j-k]){
                    dp[i][j][now]=(dp[i][j][old]+dp[i+1][j][old])%P;
                    dp[i][j][now]+=(dp[i][j+1][old]+dp[i+1][j+1][old])%P;
                    dp[i][j][now]%=P;
                }
                else{
                    dp[i][j][now]=0;
                }
            }
        }
        swap(now,old);
    }
    printf("%d",dp[1][1][old]);
    return 0;
}