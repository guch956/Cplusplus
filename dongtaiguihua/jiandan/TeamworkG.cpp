#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll dp[10003];
ll p[10003];
int main(){
    int n,k,i,j;
    ll ma;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&p[i]);
    }
    for(i=1;i<=n;i++){
        ma=p[i];
        for(j=i-1;j>=i-k && j>=0;j--){
            dp[i]=max(dp[i],(i-j)*ma+dp[j]);
            ma=max(ma,p[j]);
        }
    }
    printf("%lld",dp[n]);
    return 0;
}