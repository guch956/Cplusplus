#include<iostream>
#include<cstdio>
using namespace std;
const int N=1003;
int A[N];
int dp[N][N][2];
int main(){
    int T,n,i,j,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&A[i]);
            dp[i][i][0]=dp[i][i][1]=A[i];
        }
        for(j=2;j<=n;j++){
            for(i=j-1;i>=1;i--){
                a = dp[i][j-1][0];
                b = dp[i][j-1][1];
                if(b<=a){
                    if(A[j]>a){dp[i][j][0]=A[j];}
                    else if(A[j]==b){dp[i][j][0]=0;}
                    else if(A[j]<b){dp[i][j][0]=A[j];}
                    else{dp[i][j][0]=A[j]-1;}
                }
                else{
                    if(A[j]>b){dp[i][j][0]=A[j];}
                    else if(A[j]==b){dp[i][j][0]=0;}
                    else if(A[j]>=a){dp[i][j][0]=A[j]+1;}
                    else{dp[i][j][0]=A[j];}
                }
                a = dp[i+1][j][0];
                b = dp[i+1][j][1];
                if(a<=b){
                    if(A[i]>b){dp[i][j][1]=A[i];}
                    else if(A[i]==a){dp[i][j][1]=0;}
                    else if(A[i]<a){dp[i][j][1]=A[i];}
                    else{dp[i][j][1]=A[i]-1;}
                }
                else{
                    if(A[i]>a){dp[i][j][1]=A[i];}
                    else if(A[i]==a){dp[i][j][1]=0;}
                    else if(A[i]>=b){dp[i][j][1]=A[i]+1;}
                    else{dp[i][j][1]=A[i];}
                }
            }
        }
        if(dp[1][n-1][1]==A[n]){printf("0\n");}
        else{printf("1\n");}
    }
    return 0;
}