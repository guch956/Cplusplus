#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1048600;
ll bing[N];
int odd[N];
ll A[30];
int get(ll x){
    int a=0;
    while(x){
        if(x&1){
            a++;
        }
        x = x>>1;
    }
    return a;
}
int main(){
    int n,i,d,k=0,m,a=1,t;
    ll ans;
    scanf("%d %d",&n,&d);
    for(i=0;i<n;i++){
        scanf("%lld",&A[i]);
    }
    ans=(ll)1<<d;
    m = (1<<n)-1;
    for(i=1;i<=m;i++){
        bing[i]=bing[i-a]|A[k];
        t = get(bing[i]);
        odd[i]=odd[i-a]^1;
        if(odd[i]){
            ans-=(ll)1<<(d-t);
        }
        else{
            ans+=(ll)1<<(d-t);
        }
        if(i==2*a-1){
            k++;
            a = a<<1;
        }
    }
    cout<<ans;
    return 0;
}