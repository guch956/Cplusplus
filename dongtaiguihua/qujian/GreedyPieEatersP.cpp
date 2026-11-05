#include<iostream>
#include<cstdio>
using namespace std;
const int N=302;
int ma[N][N][2],new1=1,old1=0;
int dp[N][N];
int qujian[N][N];
int main(){
    int n,m,i,j,k,a;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&j,&k);
        qujian[j][k]+=a;
    }
    for(i=1;i<=n;i++){
        dp[i][i]=qujian[i][i];
        ma[i][i][0]=qujian[i][i];
    }
    for(k=1;k<n;k++){
        for(i=1;a=i+k,a<=n;i++){
            for(j=i;j<=a;j++){
                ma[j][i][new1]=max(max(ma[j][i][old1],ma[j][i+1][old1]),qujian[i][a]);
                dp[i][a]=max(dp[i][a],ma[j][i][new1]+dp[i][j-1]+dp[j+1][a]);
            }
        }
        swap(new1,old1);
    }
    printf("%d",dp[1][n]);
    return 0;
}

