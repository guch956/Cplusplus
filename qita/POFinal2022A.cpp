#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int A[N];
int main(){
    int n,x,i,j=0,ans=0,sum=0;
    scanf("%d %d",&n,&x);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        sum+=A[i];
        while(sum>x){
            j++;
            sum-=A[j];
        }
        ans = max(ans,i-j);
    }
    printf("%d",ans);
    return 0;
}