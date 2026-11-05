#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
int num[N];
int A[N];
int main(){
    int n,i;
    long long ans=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    num[A[n]]++;
    for(i=n-1;i>=1;i--){
        if(A[i]!=A[i+1]){
            ans = ans+n-i-num[A[i]];
        }
        num[A[i]]++;
    }
    printf("%lld",ans);
    return 0;
}