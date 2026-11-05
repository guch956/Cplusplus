#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll A[200003];
int main(){
    int T,n,i;
    ll m,sum,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d %lld",&n,&m);
        sum = 0;ans = 0;
        for(i=1;i<=n;i++){
            scanf("%lld",&A[i]);
            sum+=A[i];
        }
        sort(A+1,A+n+1,greater<ll>());
        if(m>=n){
            for(i=1;i<=n;i++){ans=ans+A[i]*(i-1);}
            ans = sum*m-ans;
        }
        else{
            for(i=1;i<=m;i++){
                ans=ans+A[i]*(m-i+1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}