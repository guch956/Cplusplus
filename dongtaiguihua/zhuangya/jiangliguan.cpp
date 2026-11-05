#include<iostream>
#include<cstdio>
using namespace std;
double dp[32800][2];
int A[20];
double p[20];
int main(){
    int n,k,i,j,t,now=1,old=0,m;
    scanf("%d %d",&k,&n);
    for(i=1;i<=n;i++){
        scanf("%lf",&p[i]);
        while(1){
            scanf("%d",&t);
            if(t==0){break;}
            A[i] = A[i]|(1<<(t-1));
        }
    }
    m = (1<<n)-1;
    for(j=1;j<=k;j++){
        for(i=0;i<=m;i++){
            dp[i][now]=0;
            for(t=1;t<=n;t++){
                if((A[t]&i)==A[t]){
                    dp[i][now]+=max(dp[i][old],dp[i|(1<<(t-1))][old]+p[t]);
                }
                else{
                    dp[i][now]+=dp[i][old];
                }
            }
            dp[i][now]=dp[i][now]/n;
        }
        swap(now,old);
    }
    printf("%.6lf",dp[0][old]);
    return 0;
}