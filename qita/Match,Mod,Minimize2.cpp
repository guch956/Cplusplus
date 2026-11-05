#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300003;
ll A[N],B[N];
int main(){
    int T,n,i,j;
    ll sum,M,num;
    scanf("%d",&T);
    while(T--){
        scanf("%d %lld",&n,&M);
        sum=0;num=n;
        for(i=0;i<n;i++){scanf("%d",&A[i]);sum+=A[i];}
        for(i=0;i<n;i++){scanf("%d",&B[i]);sum+=B[i];}
        sort(A,A+n);
        sort(B,B+n);
        j = n;
        for(i=0;i<n;i++){
            while(A[j-1]+B[i]>=M){j--;}
            num = min(num,(ll)(2*n-1-i-j));
        }
        sum = sum-M*num;
        printf("%lld\n",sum);
    }
    return 0;
}