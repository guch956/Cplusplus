#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[250003];
ll val[503];
int weight[503];
int main(){
    ll init=0,ans=-INF,a,b;
    int n,i,j,num=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %lld %lld",&weight[i],&a,&b);
        init+=a;
        val[i]=b-a;
        num+=weight[i];
    }
    for(i=1;i<=num;i++)dp[i]=-INF;
    num = 0;
    for(i=1;i<=n;i++){
        num+=weight[i];
        for(j=num;j>=weight[i];j--){
            dp[j] = max(dp[j],dp[j-weight[i]]+val[i]);
        }
    }
    for(j=num;2*j>=num;j--)ans = max(ans,dp[j]);
    ans+=init;
    printf("%lld",ans);
    return 0;
}