#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=200003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll A[N];
int main(){
    int n,i;
    ll c,X,Y,l=-INF,r=INF,ans;
    scanf("%d %lld %lld",&n,&X,&Y);
    Y = Y-X;
    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    c = X*A[1]%Y;
    for(i=1;i<=n;i++){
        if(X*A[i]%Y!=c)break;
    }
    if(i<=n){
        printf("-1");
    }
    else{
        for(i=1;i<=n;i++){
            l = max(l,(X*A[i]-c)/Y);
            r = min(r,(X*A[i]-c)/Y+A[i]);
        }    
        if(l<=r){
            ans = 0;
            for(i=1;i<=n;i++){
                ans=ans+r-((X*A[i]-c)/Y);
            }
            printf("%lld",ans);
        }
        else printf("-1");
    }
    return 0;
}