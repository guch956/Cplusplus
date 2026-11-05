#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
ll P=998244353;
ll jiec[N];
ll mi2[N];
int main(){
    int T,n,k;
    ll i,ans;
    mi2[0]=jiec[0]=1;
    for(i=1;i<N;i++){
        jiec[i]=jiec[i-1]*i%P;
        mi2[i]=mi2[i-1]*2%P;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        ans = (jiec[n-k+1]-2*jiec[n-k]+2*P)*mi2[k-1]%P;
        if(k==n){ans = mi2[n-1];}
        printf("%lld\n",ans);
    }
    return 0;
}