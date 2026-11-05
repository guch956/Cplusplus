#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int cishu[N],A[N];
void solve(){
    int n,m,i,l,r,ma,mi;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    while(m--){
        scanf("%d %d",&l,&r);
        cishu[l]++;cishu[r+1]--;
    }
    ma = A[1]-cishu[1];
    mi = A[1]+cishu[1];
    for(i=2;i<=n;i++){
        cishu[i]=cishu[i-1]+cishu[i];
        ma = max(ma,A[i]-cishu[i]);
        mi = min(mi,A[i]+cishu[i]);
    }
    printf("%d\n",max(0,ma-mi));
    for(i=1;i<=n;i++){
        cishu[i]=0;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}