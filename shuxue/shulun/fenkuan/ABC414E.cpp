#include<iostream>
#include<cstdio>
#define ll long long
const ll P=998244353;
int main(){
    using namespace std;
    ll n,l,r,ans=0,t;
    cin>>n;
    for(l=1;l<=n;t=n/l){
        r = n/t;
        ans+=(r-l+1)*t;
        ans %= P;
        l = r+1;
    }
    ans = n%P*((n+1)%P)%P*((P+1)/2)%P-ans;
    ans = (P+ans)%P;
    cout<<ans;
    
    return 0;
}