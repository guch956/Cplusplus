#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll P=998244353;
int main(){
    int T;
    int n,a;
    ll dp,ans,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans = 0;dp = 1;
        for(i=1;i<n;i++){
            scanf("%d",&a);
            ans = (ans*i+(a==0?dp:0))%P;
            dp = dp*(a==0?i:i-1)%P;
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}