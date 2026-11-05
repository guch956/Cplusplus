#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=1e9+7;
const int N=1050000;
ll jiecheng[N];
ll ni[N];
int log2[N];
int main(){
    int n,T,i;
    ll r,k;
    jiecheng[0]=1;
    ni[0]=1;
    log2[1]=0;
    ni[1]=1;
    jiecheng[1]=1;
    for(i=2;i<N;i++){
        jiecheng[i]=(jiecheng[i-1]*i)%P;
        log2[i]=log2[(i+1)>>1]+1;
        r = P%i;
        k = (P-r)/i;
        ni[i]=(P-k)*ni[r]%P;
    }
    for(i=1;i<N;i++){
        ni[i]=ni[i-1]*ni[i]%P;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        k = log2[n];
        r = 1<<k;
        k = jiecheng[r]*ni[r-n]%P*ni[k]%P;
        printf("%lld\n",k);
    }
    return 0;
}
