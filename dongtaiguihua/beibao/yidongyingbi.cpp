#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=150003;
const ll P=1e9+7;
ll jiec[N];
ll ni[N];
ll dp[N];
void init(int n){
    ll i,k,r;
    jiec[0]=jiec[1]=1;
    ni[0]=ni[1]=1;
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        r = P%i;
        k = P/i;
        ni[i]=ni[r]*(P-k)%P;
    }
    for(i=2;i<=n;i++){
        ni[i]=ni[i-1]*ni[i]%P;
    }
}
inline ll C(int n,int m){
    return jiec[n]*ni[m]%P*ni[n-m]%P;
}
int main(){
    int n,m,i,r,t,m1,j,m2;
    ll ans=0;
    scanf("%d %d",&n,&m1);
    init(n);
    m = (m1+1)>>1;
    dp[0]=1;
    for(r=0;r<=17;r++){
        t = 1<<r;
        for(i=n/2;i>=t;i--){
            for(j=1;2*j<=m && t*j<=i;j++){
                dp[i]=(C(m,2*j)*dp[i-t*j]%P+dp[i])%P;
            }
        }
    }
    m1 = m1&1;
    m2 = n-2*m+m1;
    for(i=0;i<=m2;i++){
        if((i&1)==0){ans = (C(n-m-i,m-m1)*dp[i/2]+ans)%P;}
        //else{ans = (C(n-m-i,m-m1)*(C(i+m-1,m-1)-dp[i/2]+P)%P+ans)%P;}
    }
    printf("%lld",(C(n,2*m-m1)-ans+P)%P);
    return 0;
}