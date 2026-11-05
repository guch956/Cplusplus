#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
const ll P=1e9+7;
ll zuix[N],phi[N];
ll p[N],num;
void init(){
    ll i,j,c;
    for(i=2;i<=N;i++){
        if(!zuix[i]){
            zuix[i]=i;
            phi[i]=i-1;
            p[++num]=i;
        }
        for(j=1;j<=num;j++){
            c=i*p[j];
            if(c>N){break;}
            zuix[c]=p[j];
            if(i%p[j]==0){
                phi[c]=p[j]*phi[i];
                break;
            }
            phi[c]=(p[j]-1)*phi[i];
        }
    }
    phi[1]=1;
}
ll getphi(ll x){
    int i=2;
    ll ans=1,a=1;
    while(1){
        if(x<=N){
            return phi[x]*ans;
        }
        while((x%i)!=0){
            if(i>N){
                return (x-1)*ans;
            }
            i++;
        }
        a=i-1;
        x=x/i;
        while((x%i)==0){
            a=a*i;
            x=x/i;
        }
        ans=ans*a;
    }
}
ll quick(ll x,ll y){
    ll a=x;
    ll ans=1;
    while(y){
        if(y&1){ans=(ans*a)%P;}
        a = (a*a)%P;
        y = y>>1;
    }
    return ans;
}
void getp(ll x,ll y){
    num=0;
    ll a;
    while(x!=1){
        a=zuix[x];
        if(y%a==0){
            p[++num]=a;
        }
        while(x%a==0){
            x = x/a;
        }
    }
}
int main(){
    ll n;
    ll i,ans,a,j,b,k;
    scanf("%lld",&n);
    if(n==1){
        printf("1");
    }
    else{
        init();
        a = getphi(n);
        ans=(a*2)%P;
        for(i=2;i*i<n;i++){
            if(n%i==0){
                j = n/i;
                ans+=quick(2,j)*phi[i];
                ans%=P;
                getp(i,j);
                b = a/phi[i];
                for(k=1;k<=num;k++){
                    b = b/p[k];
                    b = b*(p[k]-1);
                }
                ans+=quick(2,i)*b;
                ans%=P;
            }
        }
        if(i*i==n){
            ans+=quick(2,i)*phi[i];
            ans%=P;
        }
        ans=((ans-n+2)%P+P)%P;
        printf("%lld",ans);
    }
    return 0;
}
