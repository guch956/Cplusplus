#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
const ll P=1e9+7;
ll mi[N];
ll dp[N];
ll sum;
int main(){
    int n,k,i;
    ll m;
    scanf("%d %lld %d",&n,&m,&k);
    mi[0]=1;
    for(i=1;i<=n;i++){
        mi[i]=mi[i-1]*m%P;
    }
    dp[1]=m;
    sum+=dp[1];
    for(i=2;i<k;i++){
        dp[i]=(m-1)*mi[i-1]%P;
        sum=(sum+dp[i])%P;
    }
    for(i=k;i<=n;i++){
        dp[i]=(m-1)*sum%P;
        sum=(sum-dp[i+1-k]+dp[i]+P)%P;
    }
    sum=(mi[n]-sum+P)%P;
    printf("%lld",sum);
    return 0;
}