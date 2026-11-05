#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=1e9+7;
ll quick(ll a,ll x){
    ll an=1;
    while(x){
        if(x&1){an = an*a%P;}
        x = x>>1;
        a = a*a%P;
    }
    return an;
}
int main(){
    int T;
    ll a,b,k;
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld %lld",&k,&a,&b);
        a = max(a,b/k+1);
        printf("%lld\n",quick(2,b-a+1));
    }
    return 0;
}