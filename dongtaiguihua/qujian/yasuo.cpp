#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=53;
int dp[N][N];
int dp1[N][N];
int isyiban[N][N];
char s[N];
int main(){
    int n,i,j,k,a;
    scanf("%s",s+1);
    n = strlen(s+1);
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            if((j-i)&1){
                a = 1;
                for(k=i;2*k<=i+j;k++){
                    if(s[k]!=s[k+((j-i+1)>>1)]){
                        a=0;
                    }
                }
                isyiban[i][j]=a;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j<=n-i;j++){
            dp[j][j+i]=i+1;
            dp1[j][j+i]=i+1;
            for(k=j;k<j+i;k++){
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+1);
                dp1[j][j+i]=min(dp1[j][j+i],dp1[j][k]+i+j-k);
            }
            if(isyiban[j][j+i]){
                dp1[j][j+i]=min(dp1[j][j+i],dp1[j][j+(i>>1)]+1);
            }
            dp[j][j+i]=min(dp[j][j+i],dp1[j][j+i]);
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}