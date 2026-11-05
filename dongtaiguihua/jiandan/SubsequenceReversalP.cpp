#include<iostream>
#include<cstdio>
using namespace std;
const int N=52;
int dp[N][N][N][N];
int p[N];
int main(){
    int i,n,d,j,a,b,m=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
        m = max(m,p[i]);
    }   
    for(i=1;i<=n;i++){
        for(a=1;a<=m;a++){
            for(b=a;b<=m;b++){
                if(a<=p[i] && b>=p[i]){
                    dp[i][i][a][b]=1;
                }
            }
        }
    }
    for(d=1;d<n;d++){
        for(i=1;i<=n-d;i++){
            j = i+d;
            for(a=1;a<=m;a++){
                for(b=a;b<=m;b++){
                    dp[i][j][a][b]=max(dp[i+1][j][a][b],dp[i][j-1][a][b]);
                    if(a<=p[i] && p[i]<=b){
                        dp[i][j][a][b]=max(dp[i][j][a][b],dp[i+1][j][p[i]][b]+1);
                        dp[i][j][a][b]=max(dp[i][j][a][b],dp[i+1][j-1][a][p[i]]+1);
                    }
                    if(a<=p[j] && p[j]<=b){
                        dp[i][j][a][b]=max(dp[i][j][a][b],dp[i][j-1][a][p[j]]+1);
                        dp[i][j][a][b]=max(dp[i][j][a][b],dp[i+1][j-1][p[j]][b]+1);
                    }
                    if(a<=p[j] && p[j]<=p[i] && p[i]<=b){
                        dp[i][j][a][b]=max(dp[i][j][a][b],dp[i+1][j-1][p[j]][p[i]]+2);
                    }
                }
            }
        }
    }
    printf("%d",dp[1][n][1][m]);
    return 0;
}