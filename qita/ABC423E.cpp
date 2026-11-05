#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300003;
ll sum[N][3];
int main(){
    int n,i,q;
    ll d,l,r;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&d);
        sum[i][0]=sum[i-1][0]+d;
        sum[i][1]=sum[i-1][1]+d*i;
        sum[i][2]=sum[i-1][2]+d*i*i;
    }
    while(q--){
        scanf("%lld %lld",&l,&r);
        l--;
        d = -sum[r][2]+sum[l][2]+(l+1+r)*(sum[r][1]-sum[l][1])-l*(r+1)*(sum[r][0]-sum[l][0]);
        printf("%lld\n",d);
    }
    return 0;
}