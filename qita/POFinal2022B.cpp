#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
ll A[N],B[N];
ll sum[N];
int main(){
    int n,m,i;
    ll ans = 0x3f3f3f3f3f3f3f3f,s=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){scanf("%lld",&A[i]);}
    for(i=1;i<=m;i++){scanf("%lld",&B[i]);}
    sort(A+1,A+n+1);
    sort(B+1,B+m+1);
    for(i=n;i>=1;i--){
        sum[i] = sum[i+1]+abs(A[i]-B[i+m-n]);
    }
    for(i=1;i<=m;i++){
        ans = min(ans,s+sum[i]);
        s+=abs(A[i]-B[i]);
    }
    printf("%lld",ans);
    return 0;
}