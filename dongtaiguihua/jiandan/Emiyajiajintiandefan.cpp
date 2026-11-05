#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=998244353;
ll num[103][2003];
ll sum[103];
ll dp[103][204];
int main(){
    ll answer=1,tol;
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&num[i][j]);
            sum[i]+=num[i][j];
        }
        sum[i]%=P;
        answer=answer*(sum[i]+1)%P;
    }
    dp[0][n]=1;
    for(k=1;k<=m;k++){
        for(i=1;i<=n;i++){
            for(j=n-i;j<=n+i;j++){
                dp[i][j]=dp[i-1][j]+num[i][k]*dp[i-1][j-1]+(sum[i]-num[i][k])*dp[i-1][j+1];
                dp[i][j]%=P;
            }
        }
        tol=0;
        for(j=n+1;j<=2*n;j++){
            tol+=dp[n][j];
        }
        tol%=P;
        answer = (answer-tol+P)%P;
    }
    answer = (answer-1+P)%P;
    cout<<answer;
    return 0;
}
