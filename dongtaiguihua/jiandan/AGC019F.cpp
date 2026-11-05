#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
const ll P=998244353;
const int N=1000003;
ll jiec[N],ni[N];
void init(int n){
    ll i,k,r;
    jiec[0]=jiec[1]=1;
    ni[0]=ni[1]=1;
    for(i=2;i<=n;i++){
        k = P/i;
        r = P%i;
        ni[i] = (P-k)*ni[r]%P;
    }
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        ni[i]=ni[i]*ni[i-1]%P;
    }
}
inline ll C(int m,int n){
    return jiec[n]*ni[m]%P*ni[n-m]%P;
}
ll quick(ll a,ll b){
    ll an=1;
    while(b){
        if(b&1){an = an*a%P;}
        a = a*a%P;
        b = b>>1;
    }
    return an;
}
int main(){
    ll ans=0,i;
    int m,n,t;
    scanf("%d %d",&n,&m);
    if(n>m){swap(n,m);}
    if(n==0){printf("%d",m);}
    else{
        init(m+n);
        for(t=1;t<=n;t++){
            ans = (ans+2*P+C(t+1,t+m)+C(t+1,t+n)-C(t+1,2*t-1)-C(t+1,2*t))%P;
        }
        for(i=1;i<=n;i++){
            ans = (i*C(m-1,m+n-1-i)%P+ans)%P;
        }
        for(i=1;i<=m;i++){
            ans = (i*C(n-1,m+n-1-i)%P+ans)%P;
        }
        ans = ans*quick(C(n,m+n),P-2)%P;
        printf("%lld",ans);
    }
    return 0;
}