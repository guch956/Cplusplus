#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll A[100003];
int main(){
    int T,n;
    ll i,j,mi,ans,k;
    scanf("%d %d",&n,&T);
    while(T--){
        scanf("%d %lld",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%lld",&A[i]);
        }
        sort(A+1,A+n+1);
        ans = 0;mi = k-A[1];
        for(i=1;i<=n;i++){
            mi = min(mi,k*i-A[i]);
            ans = max(i*k-A[i]-mi,ans);
        }
        ans+=k;
        printf("%lld\n",ans);
    }
    return 0;
}
