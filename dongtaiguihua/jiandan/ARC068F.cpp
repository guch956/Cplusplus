#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=4003;
const ll P=1e9+7;
ll mi[N];
ll jiec[N],ni[N];
ll catalan[N];
ll dp[N][N];
ll quick(ll a,ll b){
    ll an=1;
    while(b){
        if(b&1){an = an*a%P;}
        a = a*a%P;
        b = b>>1;
    }
    return an;
}
void init(ll n){
    ll i,k,r;
    mi[0]=mi[1]=1;
    jiec[0]=jiec[1]=1;
    ni[0]=ni[1]=1;
    catalan[0]=catalan[1]=1;
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        mi[i]=mi[i-1]*2%P;
        r = P%i;
        k = P/i;
        ni[i]=ni[r]*(P-k)%P;
        catalan[i]=catalan[i-1]*(4*i-2)%P*quick(i+1,P-2)%P;
    }
    for(i=2;i<=n;i++){
        ni[i]=ni[i-1]*ni[i]%P;
    }
}
inline ll C(int n,int m){
    if(m<0)return 0;
    return jiec[n]*ni[m]%P*ni[n-m]%P;
}
int main(){
    int n,k,i,j;
    ll ans=0;
    scanf("%d %d",&n,&k);
    init(n*2);
    ans = catalan[k-1];
    for(i=0;i<=2*n;i++){
        dp[i][0]=1;
        dp[0][i]=catalan[i];
    }
    for(i=2;i<=2*n;i++){
        for(j=1;j<i;j++){
            dp[i-j][j]=(dp[i-j-1][j]+dp[i-j+1][j-1])%P;
        }
    }
    for(i=n-k+2;i<=n;i++){
        ans = (dp[i-n+k-1][n-i]*C(i-2,n-k-1)%P+ans)%P;
    }
    ans = ans*mi[n-k]%P;
    printf("%lld",ans);
    return 0;
}