#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int A[N];
int main(){
    int n,i,ans=0,r,j=1;
    scanf("%d %d",&n,&r);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        ans=ans+1-A[i];
    }
    while(j<=r && A[j]==1){j++;}
    for(i=j;i<=r;i++){ans+=2*A[i];}
    j = n;
    while(j>r && A[j]==1){j--;}
    for(i=j;i>r;i--){ans+=2*A[i];}
    printf("%d",ans);
    return 0;
}