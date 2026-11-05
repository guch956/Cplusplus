#include<iostream>
#include<cstdio>
const int N=200003;
int A[N];
int main(){
    int n,i,j;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(j=n;j>=1;j--){
        if(A[j]!=-1 && A[j]!=j-1)break;
    }
    for(i=1;i<=n;i++){
        if(A[i]==-1){
            if(j<=i){ans = ans+n-1;}
            if(i==n){ans++;}
        }
        else{
            if(A[i]!=i+1){
                if(j<=i){ans++;}
                break;
            }
        }
    }
    ans = ans%998244353;
    printf("%lld",ans);
    return 0;
}