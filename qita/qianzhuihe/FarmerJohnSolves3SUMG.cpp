#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000001;
ll tong[2000003];
ll ans[5003][5003];
int A[5003];
int main(){
    int n,q,i,j,a;
    ll s;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(i=3;i<=n;i++){
        s = 0;
        for(j=i-1;j>=1;j--){
            ans[j][i]+=ans[j][i-1];
            a = A[j]+A[i]+N;
            if(a>=0 && a<=2*N){
                s+=tong[a];
            }
            ans[j][i]+=s;
            tong[-A[j]+N]++;
        }
        for(j=i-1;j>=1;j--){
            tong[-A[j]+N]--;
        }
    }
    while(q--){
        scanf("%d %d",&i,&j);
        printf("%lld\n",ans[i][j]);
    }
    return 0;
}