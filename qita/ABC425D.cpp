#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
ll C[5003][5003];
int main(){
    int T,n,i,j,s,a;
    ll M,ans;
    scanf("%d %lld",&T,&M);
    C[0][0]=1;
    for(i=1;i<=5000;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
        }
    }
    while(T--){
        scanf("%d",&n);
        s = 0;ans = 1;
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            s+=a;
            ans = ans*C[s][a]%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}