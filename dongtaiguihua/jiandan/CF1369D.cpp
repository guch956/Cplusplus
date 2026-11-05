#include<iostream>
#include<cstdio>
using namespace std;
const int N=2000009;
const int P=1e9+7;
int dp[N];
int main(){
    int n,i,T;
    dp[3]=1;
    for(i=4;i<N;i+=3){
        dp[i]=(2*dp[i-2]%P+dp[i-1])%P;
        dp[i+1]=(2*dp[i-1]%P+dp[i])%P;
        dp[i+2]=(2*dp[i]%P+dp[i+1]+1)%P;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",dp[n]*2%P*2%P);
    }
    return 0;
}