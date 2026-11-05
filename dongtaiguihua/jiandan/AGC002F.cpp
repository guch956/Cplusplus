#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=2002;
const ll P=1e9+7;
ll jiec[N*N];
ll ni[N*N];
ll dp[2][N];
void init(int n){
    ll k,r,i;
    jiec[0]=jiec[1]=1;
    ni[0]=ni[1]=1;
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        r = P%i;
        k = P/i;
        ni[i]=(P-k)*ni[r]%P;
    }
    for(i=2;i<=n;i++){ni[i]=ni[i]*ni[i-1]%P;}
}
inline ll C(int m,int n){
    return jiec[n]*ni[m]%P*ni[n-m]%P;
}
int main(){
    int n,k,i,j,now=1,old=0;
    scanf("%d %d",&n,&k);
    if(k==1){printf("1");}
    else{
        init(n*k);
        dp[old][1]=1;
        dp[old][0]=1;
        for(i=2;i<=n;i++){
            for(j=1;j<=i;j++){
                dp[now][j]=C(k-2,i*k-j-1)*dp[old][j-1];
            }
            dp[now][0]=0;
            for(j=i;j>=0;j--){
                dp[now][j]=(dp[now][j]+dp[now][j+1])%P;
            }
            swap(now,old);
        }
        dp[old][0]=dp[old][0]*jiec[n]%P;
        printf("%lld",dp[old][0]);
    }
    return 0;
}
