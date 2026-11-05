#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
ll num[N];
int main(){
    int n,i,a;
    ll ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        num[a]++;
    }
    for(i=1;i<=n;i++){
        ans = num[i]*(num[i]-1)/2*(n-num[i])+ans;
    }
    printf("%lld",ans);
    return 0;
}