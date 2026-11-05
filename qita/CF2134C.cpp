#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
ll sum[N];
int main(){
    int t,i,n;
    ll ans,a,ma;
    scanf("%d",&t);
    while(t--){
        ans=0;
        ma=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a);
            if(i&1){sum[i]=sum[i-1]-a;}
            else{sum[i]=sum[i-1]+a;}
        }
        for(i=2;i<=n;i++){
            sum[i]=sum[i]+ans;
            if(sum[i]<ma){
                ans+=ma-sum[i];
            }
            ma = max(ma,sum[i-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
