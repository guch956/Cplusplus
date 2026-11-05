#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=100003;
const ll P=1e9+7;
ll mi2[N];
int num[N<<1];
int main(){
    ll ans = 0;
    int n,i,l,r;
    scanf("%d",&n);
    mi2[0] = 1;
    for(i=1;i<=n;i++){
        mi2[i] = 2*mi2[i-1]%P;
        scanf("%d %d",&l,&r);
        num[l]++;num[r]--;
    }
    r = n;
    n = n<<1;
    for(i=1;i<n;i++){
        num[i] = num[i]+num[i-1];
    }
    for(i=1;i<n;i++){
        if(num[i]>num[i-1]){
            ans = (ans+mi2[r-num[i]])%P;
        }
    }
    printf("%lld",ans);
    return 0;
}