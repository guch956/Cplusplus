#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int main(){
    int q;
    ll n,l,r,mid,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%lld",&n);
        l = 1;r = 1e9+1;
        while(l<r){
            mid = (l+r+1)>>1;
            if(mid*mid<=n)l = mid;
            else r = mid-1;
        }
        ans = 3*l-2;
        if(n==l*l+2*l)ans+=2;
        else if(n>=l*l+l)ans+=1;
        printf("%lld\n",ans);
    }
    return 0;
}