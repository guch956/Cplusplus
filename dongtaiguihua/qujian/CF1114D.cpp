#include<iostream>
#include<cstdio>
using namespace std;
const int N=5003;
int dp[N][N];
int col[N];
int main(){
    int m,n=0,i,c,last=0,j;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d",&c);
        if(c!=last){
            col[++n]=c;
        }
        last = c;
    }
    for(c=1;c<n;c++){
        for(i=1;i<=n-c;i++){
            j = i+c;
            dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
            if(col[i]==col[j]){
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]+1);
            }
        }
    }
    printf("%d",dp[1][n]);
    return 0;
} 