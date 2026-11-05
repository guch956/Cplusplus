#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
bool check(ll n,ll x,ll k,ll m){
    ll y,p=(m+1)*x,t=0,z,w;
    while(n>=p){
        y = n/x;
        z = n-x*y;
        w = z/y+1;
        t+=w;
        n-=y*w;
    }
    w = (n-1)/m+1;
    if(t+w<=k){return 1;}
    return 0;
}
int main(){
    ll n,m,k,l,r,mid;
    cin>>n>>k>>m;
    l = 1;r = n/(m+1);
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(n,mid,k,m)){l = mid;}
        else{r = mid-1;}
    }
    cout<<l;
    return 0;
}
