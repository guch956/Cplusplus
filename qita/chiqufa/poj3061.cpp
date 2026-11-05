#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
const int N=100003;
ll A[N];
int main(){
    int n,i,j,t,ans;
    ll s,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d %lld",&n,&s);
        ans = n+1;
        j = 1;
        sum=0;
        for(i=1;i<=n;i++){scanf("%lld",&A[i]);}
        for(i=1;i<=n;i++){
            sum+=A[i];
            while(sum-A[j]>=s){sum-=A[j++];}
            if(sum>=s){ans = min(ans,i-j+1);}
        }
        if(ans==n+1){printf("0\n");}
        else{printf("%d\n",ans);}
    }
    return 0;
}