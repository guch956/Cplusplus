#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=20;
ll sum[1<<N];
ll dp[1<<N];
ll hei[N],pow[N],wei[N];
int main(){
    int n,i,j,m,k;
    ll H,ans=-1;
    scanf("%d %lld",&n,&H);
    dp[0]=0x3f3f3f3f3f3f3f3f;
    for(i=0;i<n;i++){
        scanf("%lld %lld %lld",&hei[i],&wei[i],&pow[i]);
    }
    m = 1<<n;
    for(i=1;i<m;i++){
        dp[i]=-1;
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                k = i^(1<<j);
                sum[i]=sum[k]+hei[j];
                dp[i]=max(dp[i],min(pow[j],dp[k]-wei[j]));
            }
        }
        if(sum[i]>=H){ans = max(ans,dp[i]);}
    }
    if(ans!=-1){printf("%lld",ans);}
    else{printf("Mark is too tall");}
    return 0;
}