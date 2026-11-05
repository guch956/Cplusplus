#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=1e9+9;
const int N=300007;
ll sum1[N],sum2[N];
ll sum[N];
ll f[N];
ll A[N];
int n;
inline int lowbit(int x){return x&(-x);}
void update(int x,ll d){
    int i=1;
    while(x<=n){
        sum1[x]=(f[i]*d+sum1[x])%P;
        sum2[x]=(f[i+1]*d+sum2[x])%P;
        sum[x]=(d+sum[x])%P;
        i+=lowbit(x);
        x+=lowbit(x);
    }
}
ll chaxun(int x){
    ll ans=0,s=0;
    int i=3;
    while(x){
        ans=(f[i-1]*sum2[x]%P+f[i-2]*sum1[x]%P+ans)%P;
        s = (sum[x]+s)%P;
        i+=lowbit(x);
        x-=lowbit(x);
    }
    return (ans-s+P)%P;
}
int main(){
    int q,i,l,r;
    ll a;
    f[0]=0;f[1]=1;
    scanf("%d %d",&n,&q);
    for(i=2;i<=n+5;i++){f[i]=(f[i-1]+f[i-2])%P;}
    for(i=1;i<=n;i++)scanf("%lld",&A[i]);
    update(1,A[1]);
    for(i=2;i<=n;i++)update(i,(A[i]-A[i-1]-A[i-2])%P+P);
    while(q--){
        scanf("%d %d %d",&i,&l,&r);
        if(i==1){
            update(l,1);
            update(r+1,P-f[r-l+2]);
            update(r+2,P-f[r-l+1]);
        }
        else{
            a = (chaxun(r)-chaxun(l-1)+P)%P;
            printf("%lld\n",a);
        }
    }
    return 0;
}